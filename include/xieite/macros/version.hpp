#ifndef XIEITE_HEADER_MACROS_VERSION
#	define XIEITE_HEADER_MACROS_VERSION

#	define XIEITE_VERSION_MAJOR 12
#	define XIEITE_VERSION_MINOR 2
#	define XIEITE_VERSION_PATCH 5

#	define XIEITE_VERSION_EQUAL(major_, minor_, patch_) ((XIEITE_VERSION_MAJOR == (major_)) && (XIEITE_VERSION_MINOR == (minor_)) && (XIEITE_VERSION_PATCH == (patch_)))
#	define XIEITE_VERSION_LEAST(major_, minor_, patch_) ((XIEITE_VERSION_MAJOR > (major_)) || (XIEITE_VERSION_MAJOR == (major_)) && ((XIEITE_VERSION_MINOR > (minor_) || (XIEITE_VERSION_MINOR == (minor_)) && (XIEITE_VERSION_PATCH >= (patch_)))))
#	define XIEITE_VERSION_MOST(major_, minor_, patch_) ((XIEITE_VERSION_MAJOR < (major_)) || (XIEITE_VERSION_MAJOR == (major_)) && ((XIEITE_VERSION_MINOR < (minor_) || (XIEITE_VERSION_MINOR == (minor_)) && (XIEITE_VERSION_PATCH <= (patch_)))))

#endif
