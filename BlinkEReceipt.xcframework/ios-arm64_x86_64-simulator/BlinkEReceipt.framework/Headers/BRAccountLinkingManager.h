//
//  BRAccountLinkingManager.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 12/2/19.
//  Copyright © 2019 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BlinkReceipt/BRScanResults.h>
#import "BRAccountLinkingConnection.h"
#import "BRAccountLinkingConnectionIdentifier.h"
#import <BackgroundTasks/BackgroundTasks.h>

NS_ASSUME_NONNULL_BEGIN

///
typedef NS_ENUM(NSUInteger, BRAccountLinkingError) {
    BRAccountLinkingErrorNone,

    /// An attempt was made to grab orders for all merchants or for a specific merchant, but no merchant accounts had been linked
    BRAccountLinkingErrorNoAccountsLinked,
    
    /// An attempt was made to link a merchant, but the same had been linked already
    BRAccountLinkingErrorAccountLinkedAlready,

    /// Login encountered a scenario requiring manual user intervention (CAPTCHA, 2FA, etc)
    BRAccountLinkingErrorVerificationNeeded,

    /// The user successfully completed the authentication manually
    BRAccountLinkingErrorVerificationCompleted,

    /// The user cancelled the manual authentication
    BRAccountLinkingErrorVerificationCancelled,

    /// An attempt was made to grab orders from Amazon (legacy parser) but no Amazon credentials were found
    BRAccountLinkingErrorNoCredentials,

    /// An unexpected error occurred during login or parsing
    BRAccountLinkingErrorInternal,

    /// The structure of the merchant's website or data feed that was encountered during parsing was unexpected
    BRAccountLinkingErrorParsingFail,

    /// Login failed on the merchant's site due to invalid credentials
    BRAccountLinkingErrorInvalidCredentials,

    /// An attempt was made to grab orders for a particular merchant but no linked account for that merchant was found
    BRAccountLinkingErrorRetailerNotFound,
    
    /**
     * Invalid license or prodIntel key.
     *
     * Please contact blinkreceipt@microblink.com to validate your key(s).
     */
    BRAccountLinkingErrorInvalidKey,
    
    /// The operation was cancelled
    BRAccountLinkingErrorCancelled,
    
    /// The feature is not available on your device
    BRAccountLinkingErrorFeatureNotAvailable,
    
    /// Login failed on the merchant's site
    BRAccountLinkingErrorAuthenticationFail,
    
    /// Authentication failed due to WebView being terminated by user
    BRAccountLinkingErrorWebViewClosed,
    
    /// This retailer is not currently supported
    BRAccountLinkingErrorUnsupportedRetailer,
    
    /// The operating system terminated the operation due to not enough time for the app to run in background
    BRAccountLinkingErrorSystemTerminated
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
*  Returns current version
*
*/
@property (copy, nonatomic, readonly) NSString *version;

/**
*  A completion handler to receive updates from a background operation when enabled via `enableBackgroundFetchWithIdentifier`
* `BRAccountLinkingRetailer retailer` - the retailer for this order
* `BRScanResults *results` - the current order
* `BRAccountLinkingError error` - any error that was encountered while attempting to grab orders
* `NSString *sessionId` - a unique session GUID that can be reported for debugging purposes
*/

@property (nonatomic, copy, nullable) void (^backgroundFetchCompletion)(BRAccountLinkingRetailer, BRAccountLinkingError, NSString * _Nullable, BRScanResults * _Nullable);

///---------------
/// @name Methods
///---------------
/**
  *  Link an account for a given retailer
  *  @param connection A retailer's configuration
  *  @param completion Callback will be executed, if additional user input is needed or linking has completed
  *
  *      * `BRAccountLinkingError error` - any error that was encountered while attempting to verify the account
  *      * `UIViewController *userInputViewController` - for 2FA and other scenarios requiring user interaction, this will contain a reference to a view controller that should be shown or dismissed depending on the particular `error` value
  *      * `NSString *sessionId` - a unique session GUID that can be reported for debugging purposes
  *
  *  @return A BRAccountLinkingConnectionIdentifier that can be used to cancel the task
  *
  */
 - (BRAccountLinkingConnectionIdentifier * _Nullable)linkAccountWithConnection:(BRAccountLinkingConnection * _Nonnull)connection
                                                                withCompletion:(void(^)(BRAccountLinkingError error,
                                                                                        UIViewController * _Nullable userInputViewController,
                                                                                        NSString * _Nullable sessionId))completion;
/**
  *  Performs a login for the provided retailer
  *  @param retailer An ID of a linked retailer
  *  @param completion Callback will be executed, if additional user input is needed or linking has completed
  *
  *      * `BRAccountLinkingError error` - any error that was encountered while attempting to verify the account
  *      * `UIViewController *userInputViewController` - for 2FA and other scenarios requiring user interaction, this will contain a reference to a view controller that should be shown or dismissed depending on the particular `error` value
  *      * `NSString *sessionId` - a unique session GUID that can be reported for debugging purposes
  *
  *  @return A BRAccountLinkingConnectionIdentifier that can be used to cancel the task
  *
  */
- (BRAccountLinkingConnectionIdentifier * _Nullable)loginUserForLinkedRetailer:(BRAccountLinkingRetailer)retailer 
                                                                withCompletion:(void(^)(BRAccountLinkingError error,
                                                                                        UIViewController * _Nullable userInputViewController,
                                                                                        NSString * _Nullable sessionId))completion;

/**
 *  Returns a list with connections matching all linked accounts on device
 *  @return An array of `BRAccountLinkingConnection` objects
 */
- (NSArray<BRAccountLinkingConnection *> * _Nonnull)getLinkedConnections;

/**
 *  Resets order history for a particular account connection
 *  @param connection The `BRAccountLinkingConnection` for which to reset the order history
 */
- (void)resetHistoryForConnection:(BRAccountLinkingConnection * _Nonnull)connection;

/**
 *  Unlink a retailer online account
 *  @param retailer The retailer for which to unlink the account
 *  @param completion Unlinking an account involves async operations involving cookies, so this completion indicates when those operations have completed
 */
- (void)unlinkAccountForRetailer:(BRAccountLinkingRetailer)retailer withCompletion:(void(^)(void))completion;

/**
 *  Same as above except allows you to grab orders only for a single retailer
 *  @return A `BRAccountLinkingConnectionIdentifier*` object
 */
- (BRAccountLinkingConnectionIdentifier * _Nullable)grabNewOrdersForRetailer:(BRAccountLinkingRetailer)retailer
                  withCompletion:(void(^)(BRAccountLinkingRetailer retailer,
                                          BRScanResults * _Nullable results,
                                          NSInteger ordersRemainingInAccount,
                                          UIViewController * _Nullable verificationViewController,
                                          BRAccountLinkingError error,
                                          NSString *sessionId))completion;


/**
 *  It cancels any connection that matches provided identifier
 *  @param identifier A BRAccountLinkingConnectionIdentifier object
 */
- (void)cancelConnection:(BRAccountLinkingConnectionIdentifier *)identifier;


/**
 *  Updates linked connection with latest configuration
 *  @param connection A BRAccountLinkingConnection object
 */
- (void)updateConnection:(BRAccountLinkingConnection * _Nonnull)connection;

/**
 * It enables the SDK to check for new orders of all linked retailers periodically in backgorund, If background fetch is enabled by the host app
 * @note The task is set to run every 1h but limittations apply. For more info, check` https://developer.apple.com/documentation/backgroundtasks/bgapprefreshtask?language=objc`
 * @param identifier A string containing the identifier of the task.
 * @note More info about how to generate the identifier string can be found here: https://developer.apple.com/documentation/uikit/app_and_environment/scenes/preparing_your_ui_to_run_in_the_background/using_background_tasks_to_update_your_app?language=objc
 * @note You must enable background fetch inside your application delegate's didFinishLaunchingWithOptions: method. Attempting to enable it after launch or enabling it multiple times will cause a crash
 * @return Any `BRAccountLinkingError` error that was encountered while attempting to enable background fetch
 */
- (BRAccountLinkingError)enableBackgroundFetchWithIdentifier:(NSString * _Nonnull)identifier;

@end

NS_ASSUME_NONNULL_END
