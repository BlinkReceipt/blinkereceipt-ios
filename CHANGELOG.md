# 2.10.0
- Better parsing of dates from Gmail headers

# 2.9.0
- Account Linking: Improvements to Starbucks, Walgreens, and Home Depot integrations
- Fix for AOL IMAP setup
- Fix for scenario where prod intel data overwrites original fields parsed from retailer order history

# 2.8.1
- Add new e-receipt properties: `ereceiptEmailSubject`, `ereceiptMerchantEmail`, `ereceiptShippingCosts`, `currencyCode`
- Internal logging to capture unexpected date formats in email headers
- Support parsing Amazon e-gift cards
- Fix Yahoo/AOL IMAP setup

# 2.7.0
- Rename `ereceiptOrderNum` -> `ereceiptOrderNumber` for consistency with Android
- Add `ereceiptEmailProvider` property
- Account Linking: add new retailers
- Account Linking: add method to reset history for individual retailers
- Account Linking: fix to OTA update process
- Account Linking: unlinking methods are now asynchronous to properly account for removal of cookies

# 2.6.0
- Fix date formatting issue in cutoff date for Gmail and Outlook SDK integrations
- Detect CAPTCHA page in Yahoo IMAP setup
- Account Linking: Fix wrong # remaining in `grabNewOrdersWithCompletion:` callback
- Account Linking: Add method to grab orders for a single account
- Account Linking: Fix duplicate data bug
- Account Linking: Better support for parsing subtotal + taxes
- Account Linking: Add many additional retailers
- Account Linking: Fix bug when encountering CAPTCHA during Walmart login
- Account Linking: Improved login speed for most retailers

# 2.5.0
- Add method in `BRAccountLinkingManager` to grab orders for a specific retailer
- Fix bug using incorrect date serialization for computing e-receipt parsing cutoff date
- Fix bug passing back incorrect `ordersRemaining` property in account linking callback

# 2.4.1
- Support internal interface changes in BlinkReceipt SDK v1.15.0

# 2.4.0
- Fix bug detecting the end of 2FA enrollment for Gmail IMAP setup
- Add main SDK version check for standalone build
- Fix bug for certain IMAP accounts failing to return results
- Fix retain cycle in Outlook authentication provider via private fork
- Enable testing of e-receipt scraping using arbitrary senders
- Add `searchUntilDate` property to restrict e-reeipt scraping to specific window
- Fix bug displaying Amazon login page to users in case of verification needed
- Support new Prime Now order detail format

# 2.3.0
- Account linking login improvements

# 2.2.0
- E-receipt aggregation mode
- Add Shipt and Starbucks to Account Linking

# 2.1.0
- Support day & date cutoff for Account Linking
- Populate `BRScanResults.eReceiptEmailId` property correctly to enable deduplication of emails across multiple devices, or app uninstalls/reinstalls
- Add `BRScanResults.eReceiptOrderStatus` property
- Fix crash for existing AOL/Yahoo IMAP users migrating to new version
- Add `BREReceiptManager.senderWhitelist` property to restrict e-receipt senders that are searched for, and speed up processing

# 2.0.2
- Make Gmail IMAP setup more reliable
- Handle Amazon UK 2FA authentication
- Fix bug in verification of Amazon credentials
- Fix bug retrieving user email after Outlook authentication

# 2.0.1
- Automatic migration of Amazon credentials for existing users to Account Linking

# 2.0.0
- Beta release of Account Linking
- Incorporate Amazon parsing into Account Linking
- Support Amazon UK parsing
- Support specific cutoff date for Account Linking and E-Receipts
- Fix IMAP integration crash

# 1.0.4
- Add umbrella header for Swift interoperability with `BlinkEReceiptStatic`

# 1.0.3
- Fix bug due to backwards-incompatible change introduced in BlinkReceipt v1.9.0

# 1.0.2
- Fix podspec versioning to enable functioning with BlinkReceipt v1.9.x

# 1.0.1
- Adjust podspec dependencies to avoid duplicate frameworks

# 1.0.0
- Updated to new Outlook and Gmail SDKs to eliminate dependency on deprecated `UIWebView`
- Beta support for Gmail IMAP linking
- Improved logging for Amazon parsing errors

# 0.0.9
- Better detection of IMAP authentication errors
- Fix bug not clearing Amazon credentials in memory when calling `clearAmazonCredentials`
- New properties for DKIM/ARC authentication and orders fulfilled by 3rd party
- Expose `possible_products` in e-receipt results

# 0.0.8
- Update for compatibility with BlinkReceipt SDK 1.8.6
- Add experimental Gmail IMAP provider

# 0.0.7
- Fix crash due to null values

# 0.0.6
- Fix hang for accounts that have no Prime Now history

# 0.0.5
- Fix issue with Prime Now order parsing
- Speed up parsing of all pages

# 0.0.4
- Add purchase type property for Amazon and e-receipts
- Parsing for Amazon Pantry, Amazon Fresh, and Prime Now orders
- Amazon parsing results are returned incrementally, rather than in one batch at the end
- Faster parsing of Amazon orders