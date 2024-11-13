#pragma once

#define XIEITE_VERSION_MAJOR 213
#define XIEITE_VERSION_MINOR 0
#define XIEITE_VERSION_PATCH 1

#define XIEITE_VERSION_EQ(major, ...) XIEITE_DETAIL_VERSION_SEL(__VA_ARGS__, XIEITE_DETAIL_VERSION_EQ(major, __VA_ARGS__), XIEITE_DETAIL_VERSION_EQ(major, __VA_ARGS__, 0), XIEITE_DETAIL_VERSION_EQ(major, 0, 0))
#define XIEITE_VERSION_LEAST(major, ...) XIEITE_DETAIL_VERSION_SEL(__VA_ARGS__, XIEITE_DETAIL_VERSION_LEAST(major, __VA_ARGS__), XIEITE_DETAIL_VERSION_LEAST(major, __VA_ARGS__, 0), XIEITE_DETAIL_VERSION_LEAST(major, 0, 0))
#define XIEITE_VERSION_MOST(major, ...) XIEITE_DETAIL_VERSION_SEL(__VA_ARGS__, XIEITE_DETAIL_VERSION_MOST(major, __VA_ARGS__), XIEITE_DETAIL_VERSION_MOST(major, __VA_ARGS__, 0), XIEITE_DETAIL_VERSION_MOST(major, 0, 0))
#define XIEITE_DETAIL_VERSION_SEL(_0, _1, _2, x, ...) x
#define XIEITE_DETAIL_VERSION_EQ(major, minor, patch) (XIEITE_VERSION_TYPE_##type && (XIEITE_VERSION_MAJOR_##type == (major)) && (XIEITE_VERSION_MINOR_##type == (minor)) && (XIEITE_VERSION_PATCH_##type == (patch)))
#define XIEITE_DETAIL_VERSION_LEAST(major, minor, patch) (XIEITE_VERSION_TYPE_##type && ((XIEITE_VERSION_MAJOR_##type > (major)) || (XIEITE_VERSION_MAJOR_##type == (major)) && ((XIEITE_VERSION_MINOR_##type > (minor)) || (XIEITE_VERSION_MINOR_##type == (minor)) && (XIEITE_VERSION_PATCH_##type >= (patch)))))
#define XIEITE_DETAIL_VERSION_MOST(major, minor, patch) (XIEITE_VERSION_TYPE_##type && ((XIEITE_VERSION_MAJOR_##type < (major)) || (XIEITE_VERSION_MAJOR_##type == (major)) && ((XIEITE_VERSION_MINOR_##type < (minor)) || (XIEITE_VERSION_MINOR_##type == (minor)) && (XIEITE_VERSION_PATCH_##type <= (patch)))))
