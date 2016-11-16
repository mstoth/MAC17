#import <Cocoa/Cocoa.h>
#import "SUUpdateDownload.h"

/* The didCloseSelector should be of the form:
      
	  -(void)downloadWindowControllerDidClose:(SUDownloadWindowController *)controller returnCode:(SUUpdateDownloadAction)action;
	
   NSOKButton will be sent in the "Install & Relaunch" or "Show in Finder" cases.
   NSCancelButton will be sent in the "Cancel" case.
*/

typedef enum {
	SUDownloadWindowConfigurationNone = 0,
	SUDownloadWindowConfigurationConnecting,
	SUDownloadWindowConfigurationDownloading,
	SUDownloadWindowConfigurationRevealInFinder,
	SUDownloadWindowConfigurationExtractingPackage,
	SUDownloadWindowConfigurationInstallAndRelaunch
} SUDownloadWindowConfiguration;

@interface SUDownloadWindowController : NSWindowController {
@private
	IBOutlet NSTextField *_primaryTextField;
	IBOutlet NSTextField *_secondaryTextField;
	IBOutlet NSProgressIndicator *_progressIndicator;
	IBOutlet NSButton *_pushButton;
	
	id _delegate;
	SEL _didCloseSelector;
	SUDownloadWindowConfiguration _currentConfiguration;
	long long _downloadLengthInBytes;
	long long _bytesTransferred;
	BOOL _hasOutstandingUserAttentionRequest;
	NSInteger _userAttentionRequest;
}

- (id)initWithDelegate:(id)delegate didCloseSelector:(SEL)didCloseSelector;

- (IBAction)pushButtonAction:(id)sender;

- (BOOL)shouldTerminate;

- (void)configureForConnectingStep;

- (void)configureForDownloadStepWithExpectedDownloadLength:(long long)downloadLengthInBytes;
- (void)didReceiveBytesWithLength:(NSUInteger)byteLength;

- (void)configureForShowInFinderStep;
- (void)configureForExtractPackageStep;
- (void)configureForInstallAndRelaunchStep;

@end
