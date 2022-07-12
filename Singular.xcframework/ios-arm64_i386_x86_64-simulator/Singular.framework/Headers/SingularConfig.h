//
//  SingularConfig.h
//  Singular
//
//  Created by Eyal Rabinovich on 03/06/2020.
//

#import <Foundation/Foundation.h>

// avoid circular include of SingularLinkParams
#ifndef SingularLinkParams
#import "SingularLinkParams.h"
#endif

@interface SingularConfig : NSObject

// General Fields
@property (strong)NSString* apikey;
@property (strong)NSString* secret;
@property (assign)BOOL clipboardAttribution;

// Singular Links fields
@property (strong)NSDictionary *launchOptions;
@property (strong)NSUserActivity* userActivity;
@property (strong)NSURL* openUrl;
@property (assign)void(^singularLinksHandler)(SingularLinkParams*);
@property (assign)long shortLinkResolveTimeOut;
@property (strong)NSArray* supportedDomains;
@property (strong)NSArray* espDomains;

// Global Properties fields
@property (strong, readonly) NSMutableDictionary* globalProperties;

// SKAN fields
@property (assign)BOOL skAdNetworkEnabled;
@property (assign)BOOL manualSkanConversionManagement;
@property (assign)void(^conversionValueUpdatedCallback)(NSInteger);
@property (assign)NSInteger waitForTrackingAuthorizationWithTimeoutInterval;

-(id)initWithApiKey:(NSString*)apikey andSecret:(NSString*)secret;

-(void)setGlobalProperty:(NSString*)key withValue:(NSString*)value overrideExisting:(BOOL)overrideExisiting;
-(NSString*)toJsonString;

@end
