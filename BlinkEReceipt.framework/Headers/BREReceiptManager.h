//
//  BREReceiptManager.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 5/4/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <BlinkReceipt/BRScanResults.h>

typedef NS_ENUM(NSUInteger, BREReceiptProvider) {
    BREReceiptProviderNone = 0,
    BREReceiptProviderGmail,
    BREReceiptProviderOutlook,
    BREReceiptProviderYahoo,
    BREReceiptProviderAOL,
    BREReceiptProviderGmailIMAP
};

typedef NS_ENUM(NSUInteger, BREReceiptIMAPError) {
    BREReceiptIMAPErrorInvalidCredentials = 5,
    BREReceiptIMAPErrorGmailIMAPDisabled = 6,
    BREReceiptIMAPErrorGmailTwoFactor = 40
};

typedef NS_ENUM(NSUInteger, BRGoogleAccountResult) {
    BRGoogleAccountResultUserCancelled = 0,
    BRGoogleAccountResultBadEmail,
    BRGoogleAccountResultBadPassword,
    BRGoogleAccountResultEnabledLSA,
    BRGoogleAccountResultRedirectToSafari,
    BRGoogleAccountResultCreatedAppPassword,
    BRGoogleAccountResultAdminNeeded,
    BRGoogleAccountResultUnknownFailure
};

/**
 *  This class is the interface to manage e-receipt parsing
 */
@interface BREReceiptManager : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  In order to authenticate Gmail accounts, you must enable the Gmail API in your Google API Console and obtain a Client ID for your app's bundle.
 *  When you have done so, input the Client ID here before attempting to begin the OAuth process for Gmail
 */
@property (nonatomic, strong) NSString *googleClientId;

/**
 *  In order to authenticate Outlook accounts, you must register your app at the Azure Portal (https://portal.azure.com/) and add a new App Registration. This will generate an Application (client) ID
 *  When you have done so, input that id here before attempting to begin the OAuth process for Outlook
 */
@property (nonatomic, strong) NSString *outlookClientId;

/**
 *  Whether there is a stored provider
 */
@property (nonatomic) BOOL userHasProvider;

/**
 *  If there is a stored provider, this property will indicate which provider it is
 */
@property (nonatomic) BREReceiptProvider currentProvider;

/**
 *  Debug property to enable other sender emails to be parsed as ereceipts.
 *  Each element in this array should be a dictionary with the following keys:
 *
 *  `email` - The e-mail address to whitelist
 *
 *  `merchant` - The merchant to use for parsing emails from this sender. Values are: Peapod, Walmart, Target, Instacart, Jet, Costco, SamsClub
 */
@property (strong, nonatomic) NSArray<NSDictionary*> *whitelistedSenders;


/**
 *  How far back (in days) to search the user's inbox for e-receipts
 *
 *  Default: 14
 */
@property (nonatomic) NSInteger dayCutoff;

/**
 *  If the OAuth provider supports returning the logged-in email, it will be populated into this property after OAuth or silent authentications
 *  Note: It is not guaranteed to be populated on subsequent app runs
 */
@property (strong, nonatomic) NSString *userCurrentEmail;

///---------------------
/// @name Class Methods
///---------------------

+ (instancetype)shared;

///---------------
/// @name Methods
///---------------

/**
 *  Begins the OAuth process for the given provider (currently only Gmail and Outlook supported). If the completion is called with no error, you may then invoke `-[BREReceiptManager getEReceiptsWithCompletion:]`
 *
 *  @param provider         The provider you would like to authenticate against
 *  @param viewController   The view controller from which to present the OAuth modal
 *  @param completion       The completion is invoked after the OAuth attempt has completed
 *
 *      * `NSError *error` - The error returned during the OAuth attempt, if any. A successful attempt will return `nil`
 */
- (void)beginOAuthForProvider:(BREReceiptProvider)provider
           withViewController:(UIViewController*)viewController
                andCompletion:(void(^)(NSError *error))completion;

/**
 *  For IMAP providers (AOL, Yahoo, and Gmail if you prefer to connect to Gmail via IMAP) you must store the credentials prior to calling `-[BREReceiptManager getEReceiptsWithCompletion:]`
 *  In the case of Gmail, call this function before calling `-[BREReceiptManager setupGmailForIMAP:withCompletion:]`
 *
 *  @return `nil` on success, otherwise the error
 */
- (NSError *)storeImapCredentials:(NSString*)user
                      andPassword:(NSString*)password
                      forProvider:(BREReceiptProvider)provider;

/**
*  To connect to Gmail accounts via IMAP (instead of the native SDK), the user will have to enable certain Gmail account settings. Call this function to start the process
*
*  @param viewController   The view controller from which to present the controller that manages the Gmail account settings
*  @param completion       The completion is invoked after the attempt to configure the account has finished
*
*      * `BRGoogleAccountResult result` - The result of the attempt to configure the account. A successful result is `BRGoogleAccountResultEnabledLSA` or `BRGoogleAccountResultCreatedAppPassword`
*/
- (void)setupGmailForIMAP:(UIViewController*)viewController
           withCompletion:(void(^)(BRGoogleAccountResult result))completion;

/**
 *  Verifies that stored IMAP credentials are valid
 *
 *  @param completion   The completion is invoked after the attempt to verify IMAP credentials completes
 *
 *      * `BOOL success` - indicates whether verification succeeded or not
 *      * `NSError *error` - `nil` on success, otherwise contains error information
 */
- (void)verifyImapCredentials:(void(^)(BOOL success, NSError *error))completion;

/**
 *  Attempts to retrieve new (since last check) e-receipts from the stored e-mail account. You must have successfully authenticated an OAuth provider, or stored IMAP credentials prior to calling this method
 *
 *  @param completion   The completion function will be invoked when e-receipt parsing has completed.
 *
 *      * `NSArray<BRScanResults*> *receipts` - an array of `BRScanResults` objects corresponding to the e-receipts that were successfully parsed. You can expect the following order-level properties to be populated:
 *
 *          * `BRScanResults.total`
 *          * `BRScanResults.receiptDate`
 *          * `BRScanResults.ereceiptOrderNum`
 *
 *          For products in an e-receipt, you can expect the following properties to be populated:
 *
 *          * `BRProduct.productNumber`
 *          * `BRProduct.productDescription`
 *          * `BRProduct.unitPrice`
 *          * `BRProduct.totalPrice`
 *          * `BRProduct.quantity`
 *          * `BRProduct.shippingStatus`
 *
 *          If you have product intelligence enabled, we also attempt to populate these product fields:
 *
 *          * `BRProduct.productName`
 *          * `BRProduct.brand`
 *          * `BRProduct.category`
 *          * `BRProduct.size`
 *          * `BRProduct.upc`
 *          * `BRProduct.imgUrl`
 *
 *      * `NSError *error` - `nil` on success, otherwise contains the error
 */
- (void)getEReceiptsWithCompletion:(void(^)(NSArray<BRScanResults*> *receipts, NSError *error))completion;

/**
*  For debugging the parsing of e-receipt HTML
*
*  @param senderAddress    The email address from which this email originated, must be one of the recognized senders
*  @param rawHTML          The raw HTML from this email
*  @param completion       Same as completion for `getEReceiptWithCompletion:` above
*/
- (void)parseEReceiptFromSender:(NSString*)senderAddress
                        rawHTML:(NSString*)rawHTML
                     completion:(void(^)(NSArray<BRScanResults*> *receipts, NSError *error))completion;

/**
 *  Signs out of any stored email account and stored e-receipt info. For OAuth providers this signs out of the provider and invalidates the access token. For IMAP providers this removes stored credentails.
 */
- (void)signOut;

/**
 *  Resets emails so you don't need to log out and log in during testing
 */
- (void)resetEmailsChecked;

/**
 *  A passthrough function to be used in your app delegate's `openURL:options:provider:` method
 */
- (BOOL)openURL:(NSURL*)url
        options:(NSDictionary*)options
       provider:(BREReceiptProvider)provider;

@end
