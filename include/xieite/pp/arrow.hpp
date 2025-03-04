#pragma once

#include "../pp/each.hpp"
#include "../pp/eval.hpp"
#include "../pp/if.hpp"
#include "../pp/scan.hpp"
#include "../pp/unwrap.hpp"
#include "../pp/wrapped.hpp"

#define XIEITE_ARROW(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	-> decltype(auto) \
	requires(requires { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
#define XIEITE_ARROW_RET(...) \
	noexcept(noexcept(__VA_ARGS__)) \
	requires(requires { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
#define XIEITE_ARROW_DECL(params_, ...) \
	noexcept(requires (XIEITE_EACH(DETAIL_XIEITE_ARROW_DECL, XIEITE_UNWRAP(params_))) { requires(noexcept(__VA_ARGS__)); }) \
	-> decltype(auto) \
	requires(requires (XIEITE_EACH(DETAIL_XIEITE_ARROW_DECL, XIEITE_UNWRAP(params_))) { __VA_ARGS__; }) \
	{ return __VA_ARGS__; }
#define XIEITE_ARROW_INIT(...) \
	noexcept(XIEITE_EVAL(DETAIL_XIEITE_ARROW_CHECK(&&, __VA_ARGS__))) \
	requires(requires { XIEITE_EVAL(DETAIL_XIEITE_ARROW_CHECK(;, __VA_ARGS__)); }) \
	: XIEITE_EVAL(DETAIL_XIEITE_ARROW_INIT(__VA_ARGS__))

#define DETAIL_XIEITE_ARROW_DECL(param_) XIEITE_IF(XIEITE_WRAPPED(param_))(decltype param_&&... XIEITE_UNWRAP(param_), decltype(param_)&& param_)
#define DETAIL_XIEITE_ARROW_CHECK(delim_, var_, value_, ...) XIEITE_IF(XIEITE_WRAPPED(var_))(XIEITE_IF(XIEITE_WRAPPED(XIEITE_UNWRAP(var_)))((... && noexcept(XIEITE_UNWRAP(XIEITE_UNWRAP(var_)) XIEITE_UNWRAP(value_))), noexcept(XIEITE_UNWRAP(var_) XIEITE_UNWRAP(value_))), noexcept(decltype(var_) XIEITE_UNWRAP(value_))) __VA_OPT__(delim_ DETAIL_XIEITE_ARROW_CHECK_NEXT XIEITE_SCAN(()) (delim_, __VA_ARGS__))
#define DETAIL_XIEITE_ARROW_CHECK_NEXT() DETAIL_XIEITE_ARROW_CHECK
#define DETAIL_XIEITE_ARROW_INIT(var_, value_, ...) XIEITE_UNWRAP(XIEITE_UNWRAP(var_)) XIEITE_UNWRAP(value_) XIEITE_IF(XIEITE_WRAPPED(XIEITE_UNWRAP(var_)))(...) __VA_OPT__(, DETAIL_XIEITE_ARROW_INIT_NEXT XIEITE_SCAN(()) (__VA_ARGS__))
#define DETAIL_XIEITE_ARROW_INIT_NEXT() DETAIL_XIEITE_ARROW_INIT
