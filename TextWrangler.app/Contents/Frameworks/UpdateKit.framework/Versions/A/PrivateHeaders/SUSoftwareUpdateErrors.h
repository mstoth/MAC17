#import <Cocoa/Cocoa.h>

extern NSString * const SUSoftwareUpdateErrorDomain;

enum {

	SUSoftwareUpdateCheckFailedError = 1000, /* Generic failure - look at underlying error key */
	SUSoftwareUpdateCouldNotExtractUpdatePackage,
	SUSoftwareUpdatePackageFailedChecksum,
};
