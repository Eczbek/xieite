#pragma once

#include "../pp/diag.hpp"

#define X4FOR(...) \
	for (struct { \
		int count; \
		bool check; \
		bool once; \
		bool broke; \
	} DETAIL_X4i = {}; (DETAIL_X4i.count < 2) && !DETAIL_X4i.check;) \
		X4DIAGPUSH_GCC() \
		X4DIAGOFF_GCC("-Wdangling-else") \
		X4DIAGPUSH_CLANG() \
		X4DIAGOFF_CLANG("-Wdangling-else") \
		if (!DETAIL_X4i.count++) \
			for (__VA_ARGS__) \
				if (X4DETAI_i.check) { \
					break; \
				} else \
					for (DETAIL_X4i.once = true; (DETAIL_X4i.broke = DETAIL_X4i.check, DETAIL_X4i.check = DETAIL_X4i.once), DETAIL_X4i.once && !DETAIL_X4i.broke; DETAIL_X4i.check = DETAIL_X4i.once = false) \
						X4DIAGPOP_GCC() \
						X4DIAGPOP_CLANG()
#define X4WHL(...) X4FOR (; (__VA_ARGS__);)
