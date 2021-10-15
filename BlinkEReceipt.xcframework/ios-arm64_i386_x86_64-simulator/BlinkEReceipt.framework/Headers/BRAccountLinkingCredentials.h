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
    BRAccountLinkingRetailerBedBath = 6074,
    BRAccountLinkingRetailerBestBuy = 177,
    BRAccountLinkingRetailerBJs = 45,
    BRAccountLinkingRetailerCVS = 3,
    BRAccountLinkingRetailerChewy = 9947,
    BRAccountLinkingRetailerCostco = 2,
    BRAccountLinkingRetailerDicksSportingGoods = 6162,
    BRAccountLinkingRetailerDollarGeneral = 4,
    BRAccountLinkingRetailerDollarTree = 5,
    BRAccountLinkingRetailerDominosPizza = 8366,
    BRAccountLinkingRetailerDoordash = 10241,
    BRAccountLinkingRetailerFamilyDollar = 165,
    BRAccountLinkingRetailerFoodLion = 142,
    BRAccountLinkingRetailerGiantEagle = 144,
    BRAccountLinkingRetailerGrubhub = 10208,
    BRAccountLinkingRetailerHEB = 44,
    BRAccountLinkingRetailerHyVee = 56,
    BRAccountLinkingRetailerHomeDepot = 15,
    BRAccountLinkingRetailerInstacart = 8652,
    BRAccountLinkingRetailerKohls = 5929,
    BRAccountLinkingRetailerKroger = 6,
    BRAccountLinkingRetailerLowes = 16,
    BRAccountLinkingRetailerMacys = 6802,
    BRAccountLinkingRetailerMarshalls = 5917,
    BRAccountLinkingRetailerMeijer = 19,
    BRAccountLinkingRetailerNike = 8712,
    BRAccountLinkingRetailerPublix = 7,
    BRAccountLinkingRetailerRiteAid = 143,
    BRAccountLinkingRetailerSamsClub = 9,
    BRAccountLinkingRetailerSephora = 171,
    BRAccountLinkingRetailerShipt = 9016,
    BRAccountLinkingRetailerShoprite = 22,
    BRAccountLinkingRetailerStaples = 12,
    BRAccountLinkingRetailerStarbucks = 6677,
    BRAccountLinkingRetailerTacoBell = 8598,
    BRAccountLinkingRetailerTarget = 1,
    BRAccountLinkingRetailerTjMaxx = 5921,
    BRAccountLinkingRetailerWalgreens = 10,
    BRAccountLinkingRetailerWalmart = 11,
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
