#pragma once

#define XIEITE_FOR(...) \
	for (struct { \
		int count; \
		bool broke; \
		bool once; \
		bool copy; \
	} XIEITE_DETAIL_i = {}; (XIEITE_DETAIL_i.count < 2) && !XIEITE_DETAIL_i.broke;) \
		if (!XIEITE_DETAIL_i.count++) \
			for (__VA_ARGS__) \
				for (XIEITE_DETAIL_i.once = true; (XIEITE_DETAIL_i.copy = XIEITE_DETAIL_i.broke), (XIEITE_DETAIL_i.broke = XIEITE_DETAIL_i.once), XIEITE_DETAIL_i.once && !XIEITE_DETAIL_i.copy; XIEITE_DETAIL_i.broke = XIEITE_DETAIL_i.once = false)
#define XIEITE_WHL(...) XIEITE_FOR (; (__VA_ARGS__);)

// CREDIT: https://gist.github.com/m1lkweed/4339f3c1196ec3acf995e3d671c1927b
