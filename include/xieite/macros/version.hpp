#ifndef XIEITE_HEADER_MACROS_VERSION
#	define XIEITE_HEADER_MACROS_VERSION

#	define XIEITE_VERSION_MAJOR 6
#	define XIEITE_VERSION_MINOR 43
#	define XIEITE_VERSION_PATCH 0

#	define XIEITE_VERSION_LEAST(major, minor, patch) ((XIEITE_VERSION_MAJOR > (major)) || (XIEITE_VERSION_MAJOR == (major)) && ((XIEITE_VERSION_MINOR > (minor) || (XIEITE_VERSION_MINOR == (minor)) && (XIEITE_VERSION_PATCH >= (patch)))))
#	define XIEITE_VERSION_MOST(major, minor, patch) ((XIEITE_VERSION_MAJOR < (major)) || (XIEITE_VERSION_MAJOR == (major)) && ((XIEITE_VERSION_MINOR < (minor) || (XIEITE_VERSION_MINOR == (minor)) && (XIEITE_VERSION_PATCH <= (patch)))))

#endif
