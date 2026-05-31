#ifndef DETAIL_XTE_HEADER_PREPROC_WHILE
#	define DETAIL_XTE_HEADER_PREPROC_WHILE
#
#	include "../preproc/diagnostic.hpp"
#
#	define XTE_WHILE(...) \
		for (int XTE_WHILE = 0; XTE_WHILE < 2; ++XTE_WHILE) \
			XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Wdangling-else") \
			if (!XTE_WHILE) \
				while (__VA_ARGS__) \
					if (XTE_WHILE) break; \
					else for (++XTE_WHILE; XTE_WHILE; --XTE_WHILE) \
						XTE_DIAGNOSTIC_POP_GCC()
#endif
