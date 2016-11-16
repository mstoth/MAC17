#import <Cocoa/Cocoa.h>

/* The bundle which the Software Update code lives in. */
NSBundle * SUGetFrameworkBundle(void); 

/* Helpers which look up the correct localized string for the Software Update code, whether it is compiled in or in a separate framework.
*/
#define SULocalizedString(key, comment) \
	    [SUGetFrameworkBundle() localizedStringForKey:(key) value:@"" table:nil]

#define SULocalizedStringFromTable(key, tbl, comment) \
	    [SUGetFrameworkBundle() localizedStringForKey:(key) value:@"" table:(tbl)]
