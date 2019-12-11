//
//  Singular.h
//  Singular SDK for iOS public API
//
//  Copyright © 2010-2016 Singular Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

// avoid circular include of SingularLinkParams
#ifndef SingularLinkParams
#import "SingularLinkParams.h"
#endif


@interface Singular : NSObject

+ (void)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret ;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andLaunchOptions:(NSDictionary *)launchOptions withSingularLinkHandler:(void(^)(SingularLinkParams*))handler;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret
    andLaunchOptions:(NSDictionary *)launchOptions withSingularLinkHandler:(void(^)(SingularLinkParams*))handler andShortLinkResolveTimeout:(long)timeoutSec;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andLaunchOptions:(NSDictionary *)launchOptions withSingularLinkHandler:(void(^)(SingularLinkParams*))handler andSupportedDomains:(NSArray*)domains;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andLaunchOptions:(NSDictionary *)launchOptions withSingularLinkHandler:(void(^)(SingularLinkParams*))handler andShortLinkResolveTimeout:(long)timeoutSec andSupportedDomains:(NSArray*)domains;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andUserActivity:(NSUserActivity *)userActivity withSingularLinkHandler:(void(^)(SingularLinkParams*))handler;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andUserActivity:(NSUserActivity *)userActivity withSingularLinkHandler:(void(^)(SingularLinkParams*))handler andShortLinkResolveTimeout:(long)timeoutSec;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andUserActivity:(NSUserActivity *)userActivity withSingularLinkHandler:(void(^)(SingularLinkParams*))handler andSupportedDomains:(NSArray*)domains;
+ (BOOL)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andUserActivity:(NSUserActivity *)userActivity withSingularLinkHandler:(void(^)(SingularLinkParams*))handler andShortLinkResolveTimeout:(long)timeoutSec andSupportedDomains:(NSArray*)domains;
+ (void)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andLaunchOptions:(NSDictionary *)launchOptions;
+ (void)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andLaunchURL:(NSURL *)url;
+ (void)reStartSession:(NSString *)apiKey withKey:(NSString *)apiSecret;
+ (BOOL)sessionStarted;
+ (void)endSession;
+ (void)event:(NSString *)name;
+ (void)event:(NSString *)name withArgs:(NSDictionary *)args;
+ (void)eventWithArgs:(NSString *)name, ...; // use only subclasses of
                                              // NSObject, not primitive types
                                              // like int
+ (void)setDeviceCustomUserId:(NSString *) customUserId;

+ (void)registerDeviceTokenForUninstall:(NSData *)deviceToken;
+ (void)registerDeferredDeepLinkHandler:(void (^)(NSString *deeplink))handler;
+ (int)setDeferredDeepLinkTimeout:(int)duration;

+ (Singular *) shared;
+ (NSTimeInterval) sessionDuration;
+ (NSDate *) sessionStartDate;
+ (NSString *) sessionID;
+ (NSString *) version;
+ (NSString *) singularID;
+ (NSString *)singularKeyspace;
+ (void) setBufferLimit:(int)size;
@property(strong, nonatomic, readonly) NSString *applicationName;
@property(strong, nonatomic, readonly) NSString *applicationIdentifier;
+ (BOOL) processJSRequestWK:(WKWebView *)webView withURL:(NSURLRequest *)url;
@property(nonatomic) int minSessionDuration;  // Default: 5
+ (void) setMinSessionDuration:(int)seconds;

// IAP
+ (void)initializeApStore;
+ (void)setAllowAutoIAPComplete:(BOOL)boolean;
+ (void)iapComplete:(id)transaction;
+ (void)iapComplete:(id)transaction withName:(NSString*)name;
+ (void)iapComplete:(id)transaction withAttributes:(id)value, ...;
+ (void)iapComplete:(id)transaction withName:(NSString*)name withAttributes:(id)value, ...;

// DEMO
+ (void)setGender:(NSString *)gender;
+ (void)setAge:(id)age;

// BATCHING
+ (int)batchInterval;
+ (void)setBatchInterval:(int)interval;
+ (BOOL)batchesEvents;
+ (void)setBatchesEvents:(BOOL)boolean;
+ (void)sendAllBatches;

//ANIMESH UPDATE
// REVENUE
+ (void)revenue:(id)transaction;
+ (void)revenue:(id)transaction withAttributes:(NSDictionary*)attributes;
+ (void)revenue:(NSString *)currency amount:(double)amount;
+ (void)revenue:(NSString *)currency amount:(double)amount withAttributes:(NSDictionary*)attributes;
+ (void)revenue:(NSString *)currency amount:(double)amount productSKU:(NSString *)productSKU productName:(NSString *)productName productCategory:(NSString *)productCategory productQuantity:(int)productQuantity productPrice:(double)productPrice;

+ (void)customRevenue:(NSString*)eventname transaction:(id)transaction;
+ (void)customRevenue:(NSString*)eventname transaction:(id)transaction withAttributes:(NSDictionary*)attributes;
+ (void)customRevenue:(NSString*)eventname currency:(NSString *)currency amount:(double)amount;
+ (void)customRevenue:(NSString*)eventname currency:(NSString *)currency amount:(double)amount withAttributes:(NSDictionary*)attributes;
+ (void)customRevenue:(NSString*)eventname currency:(NSString *)currency amount:(double)amount productSKU:(NSString *)productSKU productName:(NSString *)productName productCategory:(NSString *)productCategory productQuantity:(int)productQuantity productPrice:(double)productPrice;

+ (void)setCustomUserId:(NSString*)customUserId;
+ (void)unsetCustomUserId;

+ (void)setSessionTimeout:(int)timeout;

+ (void)setUnityVersion:(NSString*)version;

/* GDPR helpers */

+ (void)trackingOptIn;
+ (void)trackingUnder13;
+ (void)stopAllTracking;
+ (void)resumeAllTracking;
+ (BOOL)isAllTrackingStopped;

@end
