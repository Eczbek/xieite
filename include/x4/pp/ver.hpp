#pragma once

#define X4VERMAJOR 9999999
#define X4VERMINOR 9999999
#define X4VERPATCH 9999999

#define X4VEREQ(major, ...) DETAIL_X4VER(__VA_ARGS__, DETAIL_X4VEREQ(major, __VA_ARGS__), DETAIL_X4VEREQ(major, __VA_ARGS__, 0), DETAIL_X4VEREQ(major, 0, 0))
#define X4VERLEAST(major, ...) DETAIL_X4VER(__VA_ARGS__, DETAIL_X4VERLEAST(major, __VA_ARGS__), DETAIL_X4VERLEAST(major, __VA_ARGS__, 0), DETAIL_X4VERLEAST(major, 0, 0))
#define X4VERMOST(major, ...) DETAIL_X4VER(__VA_ARGS__, DETAIL_X4VERMOST(major, __VA_ARGS__), DETAIL_X4VERMOST(major, __VA_ARGS__, 0), DETAIL_X4VERMOST(major, 0, 0))
#define DETAIL_X4VER(_0, _1, _2, x, ...) x
#define DETAIL_X4VEREQ(major, minor, patch) ((X4VERMAJOR == (major)) && (X4VERMINOR == (minor)) && (X4VERPATCH == (patch)))
#define DETAIL_X4VERLEAST(major, minor, patch) (((X4VERMAJOR > (major)) || (X4VERMAJOR == (major)) && ((X4VERMINOR > (minor)) || (X4VERMINOR == (minor)) && (X4VERPATCH >= (patch)))))
#define DETAIL_X4VERMOST(major, minor, patch) (((X4VERMAJOR < (major)) || (X4VERMAJOR == (major)) && ((X4VERMINOR < (minor)) || (X4VERMINOR == (minor)) && (X4VERPATCH <= (patch)))))
