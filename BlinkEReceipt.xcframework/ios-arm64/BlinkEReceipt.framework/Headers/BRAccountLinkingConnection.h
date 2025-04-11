//
//  BRAccountLinkingConnection.h
//  WindfallSDK-Dev
//
//  Created by stanislav on 2/7/23.
//  Copyright © 2023 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRAccountLinkingConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

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
    BRAccountLinkingRetailerTarget = 1,
    BRAccountLinkingRetailerWalgreens = 10,
    BRAccountLinkingRetailerWalmart = 11,
    BRAccountLinkingRetailerWalmartCA = 5849,
    BRAccountLinkingRetailerWegmans = 52,
    BRAccountLinkingRetailerUberEats = 9137,
    BRAccountLinkingRetailerAmazonCA = 12099,
    BRAccountLinkingRetailerAmazonUK = 10078,
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
    BRAccountLinkingRetailerAmazonFR = 12688,
    BRAccountLinkingRetailerAmazonES = 12686,
    BRAccountLinkingRetailerAmazonDE = 12687,
    BRAccountLinkingRetailerAmazonAU = 12948,
    BRAccountLinkingRetailerColesAU = 7610,
    BRAccountLinkingRetailerWoolworthsAU = 8646,
    BRAccountLinkingRetailerTemu = 12881,
    BRAccountLinkingRetailerAliExpress = 13246
};

@interface BRAccountLinkingConnection : NSObject

@property (nonatomic, readonly) BRAccountLinkingRetailer retailer;
@property (nonatomic, copy, readonly, nullable) NSString *username;
@property (nonatomic, readonly) NSTimeInterval lastExecutionTime;
@property (nonatomic, readonly) NSUInteger lastExecutionCode;

/**
 *  Set this property to YES, if you want users to authenticate with merchant's webpage directly
 *
 *  Default: YES
 */
@property (nonatomic) BOOL webviewAuthEnabled;

/**
 *  It represents the logged in status of the connection
 *
 * @note Check the `isAuthenticated` before calling `loginUserForLinkedRetailer`
 *
 */
@property (nonatomic, readonly) BOOL isAuthenticated;

// A configuration object that defines the behavior when searching for new orders
@property (nonatomic, strong, nonnull) BRAccountLinkingConfiguration *configuration;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithRetailer:(BRAccountLinkingRetailer)retailer;

- (instancetype)initWithRetailer:(BRAccountLinkingRetailer)retailer username:(NSString * _Nullable)username password:(NSString * _Nullable)password;

@end

NS_ASSUME_NONNULL_END
