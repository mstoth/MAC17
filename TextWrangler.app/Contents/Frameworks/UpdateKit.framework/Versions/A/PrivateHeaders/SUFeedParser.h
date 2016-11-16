#import <Cocoa/Cocoa.h>

@interface SUFeedParser : NSObject {
@private
	NSData *_feedData;
	NSDictionary *_feedOptions;
	NSDictionary *_freeUpgradeEntry;
	NSDictionary *_paidUpgradeEntry;
}

+ (id)feedParserWithData:(NSData *)feedData;

- (BOOL)parse:(NSError **)error;

- (NSDictionary *)feedOptions;

/* If a free or paid upgrade isn't available to the running application, the accessor will return nil.
*/
- (NSDictionary *)freeUpgradeEntry;
- (NSDictionary *)paidUpgradeEntry;

@end

extern NSString * const SUFeedParserErrorDomain;
enum {
	SUFeedParserPListParseError = 1,
	SUFeedParserFeedMalformedError = 2,
	
};
