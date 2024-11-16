#pragma once

#define XIEITE_ARROW(...) \
	noexcept(/* noexcept((__VA_ARGS__))*/ false) \
	-> decltype(/* (__VA_ARGS__) */ auto) \
	{ return (__VA_ARGS__); }
#define XIEITE_ARROW_CTOR(...) \
	noexcept(/* noexcept((__VA_ARGS__))*/ false) \
	: __VA_ARGS__ {}

// Temporary workarounds for `noexcept` specifier and `decltype` trailing return type due to compiler bugs:
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117061
// https://github.com/llvm/llvm-project/issues/111840
