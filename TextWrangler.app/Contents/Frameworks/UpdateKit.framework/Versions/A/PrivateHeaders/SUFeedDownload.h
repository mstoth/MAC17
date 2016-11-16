#import <Cocoa/Cocoa.h>

@protocol SUFeedDownloadDelegate;

@interface SUFeedDownload : NSObject {
@private
	id<SUFeedDownloadDelegate> _delegate;
	NSURLConnection *_connection;
	NSURLResponse *_response;
	NSMutableData *_data;
}

- (id)initWithFeedURL:(NSURL *)feedURL userAgent:(NSString *)userAgent delegate:(id<SUFeedDownloadDelegate>)delegate;

- (id<SUFeedDownloadDelegate>)delegate;
- (void)setDelegate:(id<SUFeedDownloadDelegate>)delegate;

- (NSURLResponse *)response;
- (NSData *)data;

@end

@protocol SUFeedDownloadDelegate
- (void)feedDownloadDidFinish:(SUFeedDownload *)download;
- (void)feedDownload:(SUFeedDownload *)download didFailWithError:(NSError *)error;
@end