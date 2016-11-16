#import <Cocoa/Cocoa.h>

/* The feed should have two top level entries:
	- the options dictionary (currently unused)
	- the updates array (and array of entry dictionaries)
	
   N.B. For all keys, the name used in the plist is the contant name without the trailing "Key".
*/
extern NSString * const SUFeedOptionsKey;
extern NSString * const SUFeedEntriesKey;

/* Entry keys */
extern NSString * const SUFeedEntryVersionKey; /* The build number (float) of the version being offered */
extern NSString * const SUFeedEntryShortVersionStringKey; /* The display name of the current version; e.g. 1.5 */
extern NSString * const SUFeedEntryMinimumSystemVersionKey; /* A string in the format "x.y.z" => "10.5.0" for the base supported system. */
extern NSString * const SUFeedEntryFreeUpgradeBaseKey; /* See note below */
extern NSString * const SUFeedEntryMarketingBaseKey; /* See note below */
extern NSString * const SUFeedEntryMarketingBaseShortVersionStringKey; /* The display name of the marketing base; e.g. 1.5 */
extern NSString * const SUFeedEntryDescriptionRTFDKey; /* NSData RTFD blob for the rich text plus graphics that appears in the update panel */
extern NSString * const SUFeedEntryDescriptionRTFKey; /* NSData RTF blob for the rich text that appears in the update panel */
extern NSString * const SUFeedEntryDescriptionStringKey; /* String for the text that appears in the update panel */
extern NSString * const SUFeedEntryPaidUpgradeDescriptionRTFDKey; /* NSData RTFD blob for the rich text plus graphics that appears in the update panel */
extern NSString * const SUFeedEntryPaidUpgradeDescriptionRTFKey; /* NSData RTF blob for the rich text that appears in the update panel */
extern NSString * const SUFeedEntryPaidUpgradeDescriptionStringKey; /* String for the text that appears in the update panel */
extern NSString * const SUFeedEntryPaidUpgradeDescriptionLinkKey; /* More Info link back to our web site */
extern NSString * const SUFeedEntryUpdateURLKey; /* URL for the autoupdate package, should be a .zip archive */
extern NSString * const SUFeedEntryDownloadURLKey; /* End user download link, should typically be a .dmg */
extern NSString * const SUFeedEntryUpdateChecksumKey; /* SHA-256 checksum of the update (zip) file */
extern NSString * const SUFeedEntryDownloadChecksumKey; /* SHA-256 checksum of the download (dmg) file */

/* About version number and base version numbers:

   SUFeedEntryVersion:
      The version number in the Info.plist and SUUpdate feed should be build numbers (floating point values.)

   SUFeedEntryShortVersionString:
      The short version string is the human readable, marketing, version of the release. e.g. 1.5.2
	  
   SUFeedEntryFreeUpgradeBase:
      The minimum version number which qualifies for a free upgrade. For example, if 2.5 is a free update from 2.0, this value should be the build number of 2.0.
	  
   SUFeedEntryMarketingBase:
      The version (build number) marketing base of the currently line of development, e.g. 9.0 for 9.0.x, 9.2 for 9.2.x
	  This is used when presenting paid upgrade notices via the Software Update mechanism.
   
   SUFeedEntryMarketingBaseShortVersionString:
      The short version string is the human readable string of the marketing base. e.g. 9.0
*/