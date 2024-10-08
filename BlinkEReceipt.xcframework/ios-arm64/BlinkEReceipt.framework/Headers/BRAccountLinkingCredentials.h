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
    BRAccountLinkingRetailerBJs = 45,
    BRAccountLinkingRetailerCVS = 3,
    BRAccountLinkingRetailerChewy = 9947,
    BRAccountLinkingRetailerCostco = 2,
    BRAccountLinkingRetailerDicksSportingGoods = 6162,
    BRAccountLinkingRetailerDollarGeneral = 4,
    BRAccountLinkingRetailerDollarTree = 5,
    BRAccountLinkingRetailerDominosPizza = 8366,
    BRAccountLinkingRetailerDoordash = 10241,
    BRAccountLinkingRetailerDrizly = 10934,
    BRAccountLinkingRetailerFamilyDollar = 165,
    BRAccountLinkingRetailerFoodLion = 142,
    BRAccountLinkingRetailerGrubhub = 10208,
    BRAccountLinkingRetailerHomeDepot = 15,
    BRAccountLinkingRetailerInstacart = 8652,
    BRAccountLinkingRetailerKroger = 6,
    BRAccountLinkingRetailerLowes = 16,
    BRAccountLinkingRetailerMeijer = 19,
    BRAccountLinkingRetailerPublix = 7,
    BRAccountLinkingRetailerSamsClub = 9,
    BRAccountLinkingRetailerSeamless = 10068,
    BRAccountLinkingRetailerSephora = 171,
    BRAccountLinkingRetailerShipt = 9016,
    BRAccountLinkingRetailerShoprite = 22,
    BRAccountLinkingRetailerStarbucks = 6677,
    BRAccountLinkingRetailerTacoBell = 8598,
    BRAccountLinkingRetailerTarget = 1,
    BRAccountLinkingRetailerWalgreens = 10,
    BRAccountLinkingRetailerWalmart = 11,
    BRAccountLinkingRetailerWalmartCA = 5849,
    BRAccountLinkingRetailerWegmans = 52,
    BRAccountLinkingRetailerUberEats = 9137,
    BRAccountLinkingRetailerAmazonBeta = 100001,
    BRAccountLinkingRetailerAmazonBetaCA = 12099,
    BRAccountLinkingRetailerAmazonBetaUK = 10078,
    BRAccountLinkingRetailerSprouts = 54,
    BRAccountLinkingRetailerGap = 6457,
    BRAccountLinkingRetailerUlta = 8662,
    BRAccountLinkingRetailerFood4Less = 31,
    BRAccountLinkingRetailerFredMeyer = 53,
    BRAccountLinkingRetailerHarrisTeeter = 33,
    BRAccountLinkingRetailerRalphs = 40,
    BRAccountLinkingRetailerAlbertsons = 20,
    BRAccountLinkingRetailerJewelOsco = 23,
    BRAccountLinkingRetailerSafeway = 8,
    BRAccountLinkingRetailerVons = 63,
    BRAccountLinkingRetailerAcmeMarkets = 17,
    BRAccountLinkingRetailerPostmates = 19671,
    BRAccountLinkingRetailerTemuUK = 12819,
    BRAccountLinkingRetailerUberEatsUK = 12850,
    BRAccountLinkingRetailerSheinUS = 12882,
    BRAccountLinkingRetailerSheinUK = 12848,
    BRAccountLinkingRetailerSheinES = 12691,
    BRAccountLinkingRetailerAliExpressUK = 12849,
    BRAccountLinkingRetailerCostcoCA = 5718,
    BRAccountLinkingRetailerAsdaUK = 6036,
    BRAccountLinkingRetailerSainsburyUK = 6048,
    BRAccountLinkingRetailerTescoUK = 6051,
    BRAccountLinkingRetailerCarrefourES = 6059,
    BRAccountLinkingRetailerPcExpressCA = 12749,
    BRAccountLinkingRetailerAmazonBetaFR = 12688,
    BRAccountLinkingRetailerAmazonBetaES = 12686,
    BRAccountLinkingRetailerAmazonBetaDE = 12687,
    BRAccountLinkingRetailerAmazonBetaAU = 12948,
    BRAccountLinkingRetailerColesAU = 7610,
    BRAccountLinkingRetailerWoolworthsAU = 8646,
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
