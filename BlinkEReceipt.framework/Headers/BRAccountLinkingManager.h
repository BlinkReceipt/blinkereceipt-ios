//
//  BRAccountLinkingManager.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 12/2/19.
//  Copyright © 2019 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRAccountLinkingCredentials.h"
#import <BlinkReceipt/BRScanResults.h>

NS_ASSUME_NONNULL_BEGIN

///
typedef NS_ENUM(NSUInteger, BRAccountLinkingError) {
    BRAccountLinkingErrorNone,
    BRAccountLinkingErrorNoAccountsLinked,
    BRAccountLinkingErrorVerificationNeeded,
    BRAccountLinkingErrorVerificationCompleted,
    BRAccountLinkingErrorVerificationCancelled,
    BRAccountLinkingErrorNoCredentials,
    BRAccountLinkingErrorInternal,
    BRAccountLinkingErrorParsingFail,
    BRAccountLinkingErrorInvalidCredentials,
    BRAccountLinkingErrorRetailerNotFound
};

/**
*  Use this interface to manage users' linked retailer accounts for parsing e-receipts. Here is the basic flow:
*
*  1. Implement UI to capture the user's credentials to one or more retailers from the supported list (see `BRAccountLinkingRetailer` enum)
*  2. Store these using `-[BRAccountLinkingManager linkAccountWithCredentials:]`
*  3. Call `-[BRAccountLinkingManager grabNewOrdersWithCompletion:]`
*  4. The callback to this method will return all order details available since the most recent successful invocation
*/
@interface BRAccountLinkingManager : NSObject

///---------------------
/// @name Class Methods
///---------------------

+ (instancetype)shared;

///------------------
/// @name Properties
///------------------

/**
 *  Set this property to control how far back in the user's history to search for orders
 *
 *  Default: 15
 */
@property (nonatomic) NSInteger dayCutoff;

/**
 *  This property is an alternative to `dayCutoff` which allows you to set a specific date/time that serves as the boundary of how far back to search.
 *  If set, it will override `dayCutoff`
 *
 *  Default: nil
 */
@property (strong, nonatomic, nullable) NSDate *dateCutoff;

/**
*  Set this to a different country to access the correct version of the retailer's site, if it exists for that country (currently only supports Amazon UK)
*
*  Default: @"US"
*/
@property (strong, nonatomic) NSString *countryCode;

///---------------
/// @name Methods
///---------------

/**
 *  Link a retailer online account
 *  @param credentials The credentials for this account
 */
- (void)linkAccountWithCredentials:(BRAccountLinkingCredentials*)credentials;

/**
 *  Verify account for a given retailer
 *  @param retailer The retailer ID of the account you want to verify
 *  @param completion Callback will be executed after verification has been attempted
 *
 *      * `BRAccountLinkingError error` - any error that was encountered while attempting to verify the account
 */
- (void)verifyAccountForRetailer:(BRAccountLinkingRetailer)retailer
                  withCompletion:(void(^)(BRAccountLinkingError error, UIViewController * _Nullable vc))completion;

/**
 *  Returns all retailers for which there is a linked account
 *  @return An array of `NSNumber*` wrapped values from the `BRAccountLinkingRetailer` enum
 */
- (NSArray<NSNumber*>*)getLinkedRetailers;

/**
 *  Resets order history for a particular retailer
 */
- (void)resetHistoryForRetailer:(BRAccountLinkingRetailer)retailer;

/**
 *  Resets order history for all linked accounts
 */
- (void)resetHistory;

/**
 *  Unlink a retailer online account
 *  @param retailer The retailer for which to unlink the account
 *  @param completion Unlinking an account involves async operations involving cookies, so this completion indicates when those operations have completed
 */
- (void)unlinkAccountForRetailer:(BRAccountLinkingRetailer)retailer withCompletion:(void(^)(void))completion;

/**
 *  Unlink all accounts
 *  @param completion Unlinking accounts involves async operations involving cookies, so this completion indicates when those operations have completed
 */
- (void)unlinkAllAccountsWithCompletion:(void(^)(void))completion;

/**
 *  Grab new orders across all linked accounts
 *  @note If there is more than one account linked, they will be searched in parallel, so to determine when the whole process is done, you should wait until you get a callback indicating 0 orders remaining for every linked account
 *  @note You must have a valid license key set in `[BRScanManager sharedManager].licenseKey` as well as a valid prod intel key set in `[BRScanManager sharedManager].prodIntelKey` in order to receive any results
 *  @param completion Callback will be executed as soon as each order is ready to be returned
 *
 *      * `BRAccountLinkingRetailer retailer` - the retailer for this order
 *      * `BRScanResults *results` - the current order
 *      * `NSInteger ordersRemainingInAccount` - the number of orders remaining in the current account
 *      * `UIViewController *verificationViewController` - UIViewController for additional user input like 2FA when required
 *      * `BRAccountLinkingError error` - any error that was encountered while attempting to grab orders
 */
- (void)grabNewOrdersWithCompletion:(void(^)(BRAccountLinkingRetailer retailer,
                                             BRScanResults * _Nullable results,
                                             NSInteger ordersRemainingInAccount,
                                             UIViewController * _Nullable verificationViewController,
                                             BRAccountLinkingError error))completion;

/**
 *  Same as above except allows you to grab orders only for a single retailer
 */
- (void)grabNewOrdersForRetailer:(BRAccountLinkingRetailer)retailer
                  withCompletion:(void(^)(BRAccountLinkingRetailer retailer,
                                          BRScanResults * _Nullable results,
                                          NSInteger ordersRemainingInAccount,
                                          UIViewController * _Nullable verificationViewController,
                                          BRAccountLinkingError error))completion;

@end

NS_ASSUME_NONNULL_END
