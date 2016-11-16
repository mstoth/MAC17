#import "SUFeedDownload.h"
#import "SUUpdateDownload.h"

@class SUUpdateWindowController;

typedef enum {
	SUSoftwareUpdateStateIdle,
	SUSoftwareUpdateStateDownloadingFeed,
	SUSoftwareUpdateStateParsingFeed,
	SUSoftwareUpdateStateDisplayingUpdateAvailableUI,
	SUSoftwareUpdateStateDownloadingUpdate
} SUSoftwareUpdateState;

@protocol SUSoftwareUpdateDelegate;

@interface SUSoftwareUpdate : NSObject<SUFeedDownloadDelegate, SUUpdateDownloadDelegate> {
@private
	id<SUSoftwareUpdateDelegate> _delegate;
	BOOL _hasPerformedStartupActions;
	NSUInteger _checkIntervalInDays;
	SUSoftwareUpdateState _softwareUpdateState;
	BOOL _isManualCheck;
	SUFeedDownload *_feedDownload;
	SUUpdateDownload *_updateDownload;
	SUUpdateWindowController *_updateWindowController;
	NSTimer *_idleTimer;
}

+ (id)sharedSoftwareUpdater;

- (id<SUSoftwareUpdateDelegate>)delegate;
- (void)setDelegate:(id<SUSoftwareUpdateDelegate>)delegate;

/* Should only be called by Carbon applications for manual initialization */
- (void)performStartupActions;

/* Should be called by the application delegate's -applicationShouldTerminate: method. */
- (BOOL)shouldTerminate; 

- (NSURL *)feedURL;
- (NSString *)userAgent;
- (NSString *)helpAnchor;

/* Can we install an update without authorization? */
- (BOOL)canInstallUpdate; 

- (BOOL)canCheckForUpdates; /* KVO compliant */
- (IBAction)checkForUpdates:(id)sender;

- (BOOL)openSoftwareUpdatePreferences;

//	should be used at startup; may not have effect after first check
- (void)changeCheckInterval: (NSUInteger)checkIntervalInDays;

//	this is suitable for use from timers; generally you should pass NO in that case
- (void)startSoftwareUpdateCheck:(BOOL)manualCheck;

@end

@protocol SUSoftwareUpdateDelegate <NSObject>

- (void)openSoftwareUpdatePreferences:(SUSoftwareUpdate *)softwareUpdater;
- (void)getQuitEventClass:(AEEventClass *)eventClass eventID:(AEEventID *)eventID;
- (NSString*)feedURLString;
- (NSString*)licenseHash;

@end

/* User defaults keys */

extern NSString * const SUSoftwareUpdateEnabled; /* BOOL value */
extern NSString * const SUSoftwareUpdateCheckInterval; /* Integer value; unit is days */
