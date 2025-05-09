#ifndef DETAIL_XIEITE_HEADER_PP_ARROW
#	define DETAIL_XIEITE_HEADER_PP_ARROW
#
#	include "../pp/each.hpp"
#	include "../pp/eval.hpp"
#	include "../pp/if.hpp"
#	include "../pp/opt.hpp"
#	include "../pp/paren.hpp"
#	include "../pp/unwrap.hpp"
#	include "../pp/wrapped.hpp"
#
#	define XIEITE_ARROW(...) \
	noexcept __VA_OPT__( \
		(noexcept(__VA_ARGS__)) \
		-> decltype(auto) \
		requires(requires { __VA_ARGS__; }) \
	) { return __VA_ARGS__; }
#	define XIEITE_ARROW_RET(...) \
	noexcept __VA_OPT__( \
		(noexcept(__VA_ARGS__)) \
		requires(requires { __VA_ARGS__; }) \
	) { return __VA_ARGS__; }
#	define XIEITE_ARROW_IF(cond_, then_, ...) \
	noexcept((!static_cast<bool>(cond_) || noexcept(then_)) __VA_OPT__(&& noexcept(__VA_ARGS__))) \
	-> decltype(auto) \
	requires((!static_cast<bool>(cond_) || requires { then_; }) __VA_OPT__(&& requires { __VA_ARGS__; })) \
	{ if constexpr (static_cast<bool>(cond_)) { then_; } return __VA_ARGS__; }
#	define XIEITE_ARROW_CHOOSE(cond_, then_, ...) \
	noexcept((static_cast<bool>(cond_) && noexcept(then_)) __VA_OPT__(|| (!static_cast<bool>(cond_) && noexcept(__VA_ARGS__)))) \
	-> decltype(auto) \
	requires((static_cast<bool>(cond_) && requires { then_; }) __VA_OPT__(|| (!static_cast<bool>(cond_) && requires { __VA_ARGS__; }))) \
	{ if constexpr (static_cast<bool>(cond_)) { return XIEITE_UNWRAP(then_); } else { return __VA_ARGS__; } }
#	define XIEITE_ARROW_TRY(body_, ...) \
	XIEITE_EVAL( \
		noexcept __VA_OPT__((DETAIL_XIEITE_ARROW_TRY(requires noexcept, __VA_ARGS__))) \
		-> decltype(auto) \
		requires(DETAIL_XIEITE_ARROW_TRY(,, body_, __VA_ARGS__)) \
		try { return XIEITE_UNWRAP(body_); } DETAIL_XIEITE_ARROW_CATCH(__VA_ARGS__) \
	)
#	define XIEITE_ARROW_DECL(params_, ...) \
	XIEITE_EVAL( \
		noexcept(requires DETAIL_XIEITE_ARROW_PARAMS(XIEITE_UNWRAP(params_)) { requires(noexcept(__VA_ARGS__)); }) \
		-> decltype(auto) \
		requires(requires DETAIL_XIEITE_ARROW_PARAMS(XIEITE_UNWRAP(params_)) { __VA_ARGS__; }) \
		{ return __VA_ARGS__; } \
	)
#	define XIEITE_ARROW_CTOR(body_, ...) \
	XIEITE_EVAL( \
		noexcept(XIEITE_OPT(body_)(noexcept(XIEITE_UNWRAP(body_)) &&)() DETAIL_XIEITE_ARROW_NOEX(&&, __VA_ARGS__)) \
		requires(requires { XIEITE_OPT(body_)(XIEITE_UNWRAP(body_);)() DETAIL_XIEITE_ARROW_NOEX(;, __VA_ARGS__); }) \
		: DETAIL_XIEITE_ARROW_INIT(__VA_ARGS__) \
		{ XIEITE_UNWRAP(body_); } \
	)
#
#	define DETAIL_XIEITE_ARROW_PARAMS(...) __VA_OPT__((DETAIL_XIEITE_EACH_HELPER(DETAIL_XIEITE_ARROW_PARAM, __VA_ARGS__)))
#	define DETAIL_XIEITE_ARROW_PARAM(param_) XIEITE_IF(XIEITE_WRAPPED(param_))(decltype param_&&... XIEITE_UNWRAP(param_))(decltype(param_)&& param_)
#	define DETAIL_XIEITE_ARROW_TRY(noex_, ex_, body_, ...) XIEITE_OPT(body_)(requires XIEITE_OPT(ex_)((XIEITE_UNWRAP(ex_)))() { noex_(XIEITE_UNWRAP(body_)); })(true) __VA_OPT__(&& DETAIL_XIEITE_ARROW_TRY_NEXT XIEITE_PAREN() (noex_, __VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_TRY_NEXT() DETAIL_XIEITE_ARROW_TRY
#	define DETAIL_XIEITE_ARROW_CATCH(ex_, body_, ...) catch (XIEITE_UNWRAP(XIEITE_OPT(ex_)(ex_, ...)())) { return XIEITE_UNWRAP(body_); } __VA_OPT__(DETAIL_XIEITE_ARROW_CATCH_NEXT XIEITE_PAREN() (__VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_CATCH_NEXT() DETAIL_XIEITE_ARROW_CATCH
#	define DETAIL_XIEITE_ARROW_NOEX(delim_, var_, value_, ...) XIEITE_IF(XIEITE_WRAPPED(var_))(XIEITE_IF(XIEITE_WRAPPED(XIEITE_UNWRAP(var_)))((... && noexcept(XIEITE_UNWRAP(XIEITE_UNWRAP(var_)) XIEITE_UNWRAP(value_))))(noexcept(XIEITE_UNWRAP(var_) XIEITE_UNWRAP(value_))))(noexcept(decltype(this->var_) XIEITE_UNWRAP(value_))) __VA_OPT__(delim_ DETAIL_XIEITE_ARROW_NOEX_NEXT XIEITE_PAREN() (delim_, __VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_NOEX_NEXT() DETAIL_XIEITE_ARROW_NOEX
#	define DETAIL_XIEITE_ARROW_INIT(var_, value_, ...) XIEITE_UNWRAP(XIEITE_UNWRAP(var_)) XIEITE_UNWRAP(value_)XIEITE_IF(XIEITE_WRAPPED(XIEITE_UNWRAP(var_)))(...)()__VA_OPT__(, DETAIL_XIEITE_ARROW_INIT_NEXT XIEITE_PAREN() (__VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_INIT_NEXT() DETAIL_XIEITE_ARROW_INIT
#endif

// XIEITE_ARROW_DECL()
// - https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117061
// - https://github.com/llvm/llvm-project/issues/111840
