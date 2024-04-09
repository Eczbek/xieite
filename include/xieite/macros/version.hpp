#ifndef XIEITE_HEADER_MACROS_VERSION
#	define XIEITE_HEADER_MACROS_VERSION

#	define XIEITE_VERSION_MAJOR 6
#	define XIEITE_VERSION_MINOR 70
#	define XIEITE_VERSION_PATCH 1

#	define XIEITE_VERSION_LEAST(major_, minor_, patch_) ((XIEITE_VERSION_MAJOR > (major_)) || (XIEITE_VERSION_MAJOR == (major_)) && ((XIEITE_VERSION_MINOR > (minor_) || (XIEITE_VERSION_MINOR == (minor_)) && (XIEITE_VERSION_PATCH >= (patch_)))))
#	define XIEITE_VERSION_MOST(major_, minor_, patch_) ((XIEITE_VERSION_MAJOR < (major_)) || (XIEITE_VERSION_MAJOR == (major_)) && ((XIEITE_VERSION_MINOR < (minor_) || (XIEITE_VERSION_MINOR == (minor_)) && (XIEITE_VERSION_PATCH <= (patch_)))))

#endif
