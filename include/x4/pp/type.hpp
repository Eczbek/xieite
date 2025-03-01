#pragma once

#ifdef __cplusplus
#	define X4TYPE(...) decltype(__VA_ARGS__)
#else
#	define X4TYPE(...) typeof(__VA_ARGS__)
#endif
