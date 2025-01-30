#pragma once

#include "../pp/diag.hpp"

#define XIEITE_FOR(...) \
	for (struct { \
		int count; \
		bool check; \
		bool once; \
		bool broke; \
	} XIEITE_DETAIL_i = {}; (XIEITE_DETAIL_i.count < 2) && !XIEITE_DETAIL_i.check;) \
		XIEITE_DIAG_PUSH_GCC() \
		XIEITE_DIAG_OFF_GCC("-Wdangling-else") \
		XIEITE_DIAG_PUSH_CLANG() \
		XIEITE_DIAG_OFF_CLANG("-Wdangling-else") \
		if (!XIEITE_DETAIL_i.count++) \
			for (__VA_ARGS__) \
				if (XIEITE_DETAI_i.check) { \
					break; \
				} else \
					for (XIEITE_DETAIL_i.once = true; (XIEITE_DETAIL_i.broke = XIEITE_DETAIL_i.check, XIEITE_DETAIL_i.check = XIEITE_DETAIL_i.once), XIEITE_DETAIL_i.once && !XIEITE_DETAIL_i.broke; XIEITE_DETAIL_i.check = XIEITE_DETAIL_i.once = false) \
						XIEITE_DIAG_POP_GCC() \
						XIEITE_DIAG_POP_CLANG()
#define XIEITE_WHL(...) XIEITE_FOR (; (__VA_ARGS__);)

// CREDIT: https://gist.github.com/m1lkweed/4339f3c1196ec3acf995e3d671c1927b
