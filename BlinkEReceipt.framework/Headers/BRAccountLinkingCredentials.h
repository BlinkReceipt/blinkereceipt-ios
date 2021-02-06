//
//  BRAccountLinkingCredentials.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 12/2/19.
//  Copyright © 2019 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//lowes, best buy, kohls, csv, chewy, sephora, macys, staples, grubhub

///
typedef NS_ENUM(NSUInteger, BRAccountLinkingRetailer) {
    BRAccountLinkingRetailerAmazon = 8643,
    BRAccountLinkingRetailerBestBuy = 177,
    BRAccountLinkingRetailerCVS = 3,
    BRAccountLinkingRetailerChewy = 9947,
    BRAccountLinkingRetailerGrubhub = 10208,
    BRAccountLinkingRetailerHomeDepot = 15,
    BRAccountLinkingRetailerInstacart = 8652,
    BRAccountLinkingRetailerKohls = 5929,
    BRAccountLinkingRetailerKroger = 6,
    BRAccountLinkingRetailerLowes = 16,
    BRAccountLinkingRetailerMacys = 6802,
    BRAccountLinkingRetailerPublix = 7,
    BRAccountLinkingRetailerSephora = 171,
    BRAccountLinkingRetailerShipt = 9016,
    BRAccountLinkingRetailerStaples = 12,
    BRAccountLinkingRetailerStarbucks = 6677,
    BRAccountLinkingRetailerTarget = 1,
    BRAccountLinkingRetailerWalgreens = 10,
    BRAccountLinkingRetailerWalmart = 11,
    BRAccountLinkingRetailerWalmartGrocery = 8897,
    BRAccountLinkingRetailerWegmans = 52
};

/**
 *  Instantiate a `BRAccountLinkingCredentials` object after collecting the credentials for a given retailer from the user
 */
@interface BRAccountLinkingCredentials : NSObject

///------------------
/// @name Properties
///------------------

@property (strong, nonatomic) NSString *username;

@property (strong, nonatomic) NSString *password;

@property (nonatomic) BRAccountLinkingRetailer retailer;

///---------------------
/// @name Class Methods
///---------------------

/**
 *  Retrieves a friendly name for a given retailer
 *  @param retailer The retailer
 */
+ (NSString*)nameForRetailer:(BRAccountLinkingRetailer)retailer;

@end

NS_ASSUME_NONNULL_END
