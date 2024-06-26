//
//  BRAccountLinkingConfiguration.h
//  WindfallSDK-Dev
//
//  Created by stanislav on 2/21/23.
//  Copyright © 2023 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BRAccountLinkingConfiguration : NSObject

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
@property (nonatomic, strong, nullable) NSDate *dateCutoff;

/**
 *  This property controls how far back in the user's history to search for orders, if a previously returned order has been found
 *
 *  When set to YES, the first scrape will attempt to retrieve orders back to the dayCutoff or dateCutoff. All subsequent scrapes will only go as far back as the last scrape date regardless of whether the first scrape completed.
 *
 *  ex) If the dayCutoff was set to 365 days but the first scrape only went as far back as day 100, then any subsequent scrapes will only return the latest orders within that 100 days.
 *
 *  When set to NO, subsequent scrapes will continue to fetch historical orders until dayCutoff or dateCutoff is reached, and after that, scrapes will only go back to the last scrape date
 *
 *  ex) if the dayCutoff was set to 365 days but the first scrape only went as far back as 100 days, then subsequent scrapes would still attempt to get all of the orders within that 365 day window before starting to grab latest orders.
 *
 *  Default: YES
 */
@property (nonatomic) BOOL returnLatestOrdersOnly;

/**
*  Set this to a different country to access the correct version of the retailer's site, if it exists for that country (currently only supports Amazon UK)
*
*  Default: @"US"
*/
@property (nonatomic, copy, nonnull) NSString *countryCode;

@end

NS_ASSUME_NONNULL_END
