#pragma once

#define XIEITE_ARROW(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	-> decltype(auto) \
	requires(requires { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
#define XIEITE_ARROW_RET(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	requires(requires { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
#define XIEITE_ARROW_CTOR(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	: __VA_ARGS__ {}
#define XIEITE_ARROW_PARAM(params_, ...) \
	noexcept(requires params_ { requires(noexcept(__VA_ARGS__)); }) \
	-> decltype(auto) \
	requires(requires params_ { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
