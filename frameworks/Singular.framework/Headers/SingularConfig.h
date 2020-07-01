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
{
    NSString* apikey;
    NSString* secret;
    NSDictionary* launchOptions;
    NSUserActivity* userActivity;
    NSURL* openUrl;
    void(^singularLinksHandler)(SingularLinkParams*);
    long shortLinkResolveTimeOut;
    NSArray* supportedDomains;
    NSDictionary* globalProperties;
    BOOL overrideExisitingProperties;
}

@property NSString* apikey;
@property NSString* secret;
@property NSDictionary *launchOptions;
@property NSUserActivity* userActivity;
@property NSURL* openUrl;
@property void(^singularLinksHandler)(SingularLinkParams*);
@property long shortLinkResolveTimeOut;
@property NSArray* supportedDomains;
@property (readonly) NSMutableDictionary* globalProperties;

-(id)initWithApiKey:(NSString*)apikey andSecret:(NSString*)secret;
-(void)setGlobalProperty:(NSString*)key withValue:(NSString*)value overrideExisting:(BOOL)overrideExisiting;

@end
