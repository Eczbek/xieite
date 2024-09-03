#pragma once

#define XIEITE_TRY_RETURN(...) \
	if constexpr (requires { __VA_ARGS__; }) { \
		return __VA_ARGS__; \
	}

// Thanks to Tsche (https://github.com/Tsche) for this cool idea
