#pragma once

#define X4AR(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	-> decltype(auto) \
	requires(requires { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
#define X4ARRET(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	requires(requires { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
#define X4ARCTOR(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	: __VA_ARGS__ {}
#define X4ARPARAM(params_, ...) \
	noexcept(requires params_ { requires(noexcept(__VA_ARGS__)); }) \
	-> decltype(auto) \
	requires(requires params_ { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
