#ifndef DETAIL_XIEITE_HEADER_PP_VER
#	define DETAIL_XIEITE_HEADER_PP_VER
#
#	define XIEITE_VER_MAJOR 0
#	define XIEITE_VER_MINOR 63
#	define XIEITE_VER_PATCH 0
#
#	define XIEITE_VER_EQ(major, ...) DETAIL_XIEITE_VER(__VA_ARGS__, DETAIL_XIEITE_VER_EQ(major, __VA_ARGS__), DETAIL_XIEITE_VER_EQ(major, __VA_ARGS__, 0), DETAIL_XIEITE_VER_EQ(major, 0, 0))
#	define XIEITE_VER_LEAST(major, ...) DETAIL_XIEITE_VER(__VA_ARGS__, DETAIL_XIEITE_VER_LEAST(major, __VA_ARGS__), DETAIL_XIEITE_VER_LEAST(major, __VA_ARGS__, 0), DETAIL_XIEITE_VER_LEAST(major, 0, 0))
#	define XIEITE_VER_MOST(major, ...) DETAIL_XIEITE_VER(__VA_ARGS__, DETAIL_XIEITE_VER_MOST(major, __VA_ARGS__), DETAIL_XIEITE_VER_MOST(major, __VA_ARGS__, 0), DETAIL_XIEITE_VER_MOST(major, 0, 0))
#	define DETAIL_XIEITE_VER(_0, _1, _2, x, ...) x
#	define DETAIL_XIEITE_VER_EQ(major, minor, patch) ((XIEITE_VER_MAJOR == (major)) && (XIEITE_VER_MINOR == (minor)) && (XIEITE_VER_PATCH == (patch)))
#	define DETAIL_XIEITE_VER_LEAST(major, minor, patch) (((XIEITE_VER_MAJOR > (major)) || (XIEITE_VER_MAJOR == (major)) && ((XIEITE_VER_MINOR > (minor)) || (XIEITE_VER_MINOR == (minor)) && (XIEITE_VER_PATCH >= (patch)))))
#	define DETAIL_XIEITE_VER_MOST(major, minor, patch) (((XIEITE_VER_MAJOR < (major)) || (XIEITE_VER_MAJOR == (major)) && ((XIEITE_VER_MINOR < (minor)) || (XIEITE_VER_MINOR == (minor)) && (XIEITE_VER_PATCH <= (patch)))))
#endif
