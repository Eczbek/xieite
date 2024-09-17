#pragma once

#define XIEITE_VERSION_MAJOR 33
#define XIEITE_VERSION_MINOR 0
#define XIEITE_VERSION_PATCH 1

#define XIEITE_VERSION_EQUAL(major, minor, patch) ((XIEITE_VERSION_MAJOR == (major)) && (XIEITE_VERSION_MINOR == (minor)) && (XIEITE_VERSION_PATCH == (patch)))
#define XIEITE_VERSION_LEAST(major, minor, patch) ((XIEITE_VERSION_MAJOR > (major)) || (XIEITE_VERSION_MAJOR == (major)) && ((XIEITE_VERSION_MINOR > (minor) || (XIEITE_VERSION_MINOR == (minor)) && (XIEITE_VERSION_PATCH >= (patch)))))
#define XIEITE_VERSION_MOST(major, minor, patch) ((XIEITE_VERSION_MAJOR < (major)) || (XIEITE_VERSION_MAJOR == (major)) && ((XIEITE_VERSION_MINOR < (minor) || (XIEITE_VERSION_MINOR == (minor)) && (XIEITE_VERSION_PATCH <= (patch)))))
