#ifndef XIEITE_HEADER_MACROS_TRY_RETURN
#	define XIEITE_HEADER_MACROS_TRY_RETURN

#	define XIEITE_TRY_RETURN(...) \
		if constexpr (requires { \
			__VA_ARGS__; \
		}) { \
			return __VA_ARGS__; \
		}

#endif

// Thanks to Tsche (https://github.com/Tsche) for this cool idea
