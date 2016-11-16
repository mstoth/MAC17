#ifndef	SUUPDATEDOWNLOAD_h
#define	SUUPDATEDOWNLOAD_h	1

#import <Cocoa/Cocoa.h>

typedef enum {
	SUUpdateDownloadTypeEndUserPackage, /* End user package wil be downloaded into the "Downloads" directory. */
	SUUpdateDownloadTypeAutoupdatePackage /* Autoupdate package will be downloaded into a temporary directory and unpacked. */
} SUUpdateDownloadType;

enum {
	SUUpdateDownloadCancel,
	SUUpdateDownloadShowInFinder,
	SUUpdateDownloadInstall,
	SUUpdateDownloadInstallAndRelaunch
};
typedef NSInteger SUUpdateDownloadAction;

@class SUDownloadWindowController;
@protocol SUUpdateDownloadDelegate;

@interface SUUpdateDownload : NSObject <NSURLDownloadDelegate> {
@private
	id<SUUpdateDownloadDelegate> _delegate;
	SUUpdateDownloadType _downloadType;
	NSURLDownload *_download;
	NSURLResponse *_response;
	NSString *_checksum;
	NSString *_destinationPath;
	NSString *_uncompressedPackagePath;
	SUDownloadWindowController *_downloadWindowController;
	NSTask *_task;
}

- (id)initWithDownloadType:(SUUpdateDownloadType)type
								URL:(NSURL *)url
								userAgent:(NSString *)userAgent
								checksum: (NSString*) checksum /* can be nil */
								delegate:(id<SUUpdateDownloadDelegate>)delegate;

- (id<SUUpdateDownloadDelegate>)delegate;
- (void)setDelegate:(id<SUUpdateDownloadDelegate>)delegate;

- (BOOL)shouldTerminate;
- (void)showDownloadWindow;

- (SUUpdateDownloadType)downloadType;

- (NSString *)destinationPath;
- (NSString *)uncompressedPackagePath;

@end

@protocol SUUpdateDownloadDelegate
- (void)updateDownload:(SUUpdateDownload *)download didFinishWithAction:(SUUpdateDownloadAction)action;
- (void)updateDownload:(SUUpdateDownload *)download didFailWithError:(NSError *)error;
@end

#endif
