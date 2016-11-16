#import <Cocoa/Cocoa.h>

typedef enum {
	SUUpdatePerformUpgrade, /* The user wishes to upgrade; in-place and automatically if possible, by downloading otherwise. */
	SUUpdateMoreInformation, /* The user is taken to the more information page for paid upgrades. */
	SUUpdateAskAgainLater, /* The user will be offered the free upgrade or paid upgrade again on the next check. */
	SUUpdateSkipThisVersion, /* This free or paid upgrade is skipped; currently only used for paid upgrades. */
	SUUpdateChangeSoftwareUpdatePreferences /* Open the preference pane which allows configuration of Software Update preferences */
} SUUpdateWindowDidCloseAction;

typedef enum {
	SUFreeUpdate,
	SUPaidUpgrade
} SUUpgradeType;

@interface SUUpdateWindowController : NSWindowController {
@private
	IBOutlet NSButton *_OKButton;
	IBOutlet NSButton *_skipThisVersionButton;
	IBOutlet NSButton *_changeSoftwareUpdatePreferencesButton;
	IBOutlet NSTextField *_promptTitleField;
	IBOutlet NSTextView *_descriptionTextView;

	NSDictionary *_feedEntry;
	SUUpgradeType _upgradeType;
	BOOL _hasOutstandingUserAttentionRequest;
	NSInteger _userAttentionRequest;
}

- (id)initWithFeedEntry:(NSDictionary *)feedData upgradeType:(SUUpgradeType)upgradeType;

- (NSDictionary *)feedEntry;

- (IBAction)ok:(id)sender;
- (IBAction)cancel:(id)sender;
- (IBAction)changeSoftwareUpdatePreferences:(id)sender;
- (IBAction)skipThisVersion:(id)sender;

@end

extern NSString * const SUUpdateWindowDidCloseNotification;
extern NSString * const SUUpdateWindowDidCloseActionKey;
