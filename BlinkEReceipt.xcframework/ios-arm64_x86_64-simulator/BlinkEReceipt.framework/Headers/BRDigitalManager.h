//
//  BRDigitalManager.h
//  BlinkReceipt
//
//  Created by Belinda Natividad on 10/24/24.
//  Copyright © 2024 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BRDigitalManager : NSObject

///---------------------
/// @name Class Methods
///---------------------

+ (instancetype)shared;


/**
 *  Collect a push notification token
 *  @param deviceToken This token is sent to the server to generate remote notifications
 */
- (void)enableSilentPushWithToken:(NSData * _Nonnull)deviceToken;

/**
 *  Call this method to handle incoming remote notifications
 *  @param userInfo A dictionary object containing the notification payload
 */
- (void)didReceiveRemoteNotificationWithUserInfo:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;

@end

NS_ASSUME_NONNULL_END
