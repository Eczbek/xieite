#pragma once

#include "../pp/diag.hpp"

#define XIEITE_FOR(...) \
	for (struct { \
		int count; \
		bool check; \
		bool once; \
		bool broke; \
	} DETAIL_XIEITE_i = {}; (DETAIL_XIEITE_i.count < 2) && !DETAIL_XIEITE_i.check;) \
		XIEITE_DIAG_PUSH_GCC() \
		XIEITE_DIAG_OFF_GCC("-Wdangling-else") \
		XIEITE_DIAG_PUSH_CLANG() \
		XIEITE_DIAG_OFF_CLANG("-Wdangling-else") \
		if (!DETAIL_XIEITE_i.count++) \
			for (__VA_ARGS__) \
				if (XIEITE_DETAI_i.check) { \
					break; \
				} else \
					for (DETAIL_XIEITE_i.once = true; (DETAIL_XIEITE_i.broke = DETAIL_XIEITE_i.check, DETAIL_XIEITE_i.check = DETAIL_XIEITE_i.once), DETAIL_XIEITE_i.once && !DETAIL_XIEITE_i.broke; DETAIL_XIEITE_i.check = DETAIL_XIEITE_i.once = false) \
						XIEITE_DIAG_POP_GCC() \
						XIEITE_DIAG_POP_CLANG()
#define XIEITE_WHL(...) XIEITE_FOR (; (__VA_ARGS__);)

// https://gist.github.com/m1lkweed/4339f3c1196ec3acf995e3d671c1927b
