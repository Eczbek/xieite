#ifndef DETAIL_XTE_HEADER_PREPROC_ARROW
#	define DETAIL_XTE_HEADER_PREPROC_ARROW
#
#	include "../preproc/any.hpp"
#	include "../preproc/each.hpp"
#	include "../preproc/eval.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/if.hpp"
#	include "../preproc/paren.hpp"
#	include "../preproc/unwrap.hpp"
#	include "../preproc/wrapped.hpp"
#
#	define XTE_ARROW(...) \
		noexcept __VA_OPT__((noexcept(__VA_ARGS__)) \
		-> decltype(auto) \
		requires(requires { __VA_ARGS__; })) \
		{ __VA_OPT__(return (__VA_ARGS__);) }
#	define XTE_ARROW_IF(COND, THIS, ...) \
		noexcept((!static_cast<bool>(COND) || noexcept(THIS)) __VA_OPT__(&& noexcept(__VA_ARGS__))) \
		-> decltype(auto) \
		requires((!static_cast<bool>(COND) || requires { THIS; }) __VA_OPT__(&& requires { __VA_ARGS__; })) \
		{ if constexpr (static_cast<bool>(COND)) { THIS; } __VA_OPT__(return (__VA_ARGS__);) }
#	define XTE_ARROW_CHOOSE(COND, THIS, ...) \
		noexcept((static_cast<bool>(COND) && noexcept(THIS)) __VA_OPT__(|| (!static_cast<bool>(COND) && noexcept(__VA_ARGS__)))) \
		-> decltype(auto) \
		requires((static_cast<bool>(COND) && requires { THIS; }) __VA_OPT__(|| (!static_cast<bool>(COND) && requires { __VA_ARGS__; }))) \
		{ if constexpr (static_cast<bool>(COND)) { return (THIS); } __VA_OPT__(else { return (__VA_ARGS__); }) }
#	define XTE_ARROW_FIRST(...) \
		noexcept(XTE_EACH_DELIM(DETAIL_XTE_ARROW_FIRST_NOEX, ||, __VA_ARGS__)) \
		-> decltype(auto) \
		requires(XTE_EACH_DELIM(DETAIL_XTE_ARROW_FIRST_REQ, ||, __VA_ARGS__)) \
		{ XTE_EVAL(DETAIL_XTE_ARROW_FIRST(__VA_ARGS__)) }
#	define XTE_ARROW_CAST(ATTR_SPEC, THIS, ...) \
		__VA_OPT__(XTE_IF(XTE_ANY(THIS))(template<typename DETAIL_XTE_Arg>)() XTE_UNWRAP(ATTR_SPEC)) operator \
		decltype(XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) -> decltype(auto) { return (__VA_ARGS__); })(static_cast<[:^^DETAIL_XTE_Arg():]*>(nullptr)()))(__VA_ARGS__)) \
		XTE_IF(XTE_ANY(THIS))((__VA_OPT__(this DETAIL_XTE_Arg&& DETAIL_XTE_arg)))(() const) \
		noexcept __VA_OPT__((noexcept(XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) noexcept(noexcept(__VA_ARGS__)) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__))) \
		requires(requires { XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) requires(requires { __VA_ARGS__; }) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); })) \
		{ return XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) -> decltype(auto) { return (__VA_ARGS__); })(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); }
#	define XTE_ARROW_CTOR(BODY, ...) \
		XTE_EVAL(noexcept(XTE_IF(XTE_ANY(BODY))(noexcept(BODY) __VA_OPT__(&&))() __VA_OPT__(DETAIL_XTE_ARROW_NOEX(&&, __VA_ARGS__))) \
		requires(requires { XTE_IF(XTE_ANY(BODY))(BODY;)() __VA_OPT__(DETAIL_XTE_ARROW_NOEX(;, __VA_ARGS__);) }) \
		__VA_OPT__(: DETAIL_XTE_ARROW_INIT(__VA_ARGS__))) \
		{ BODY XTE_IF(XTE_ANY(BODY))(;)() }
#
#	define DETAIL_XTE_ARROW_NOEX(DELIM, TARGET, INIT, ...) \
		XTE_IF(XTE_WRAPPED(TARGET)) \
			(XTE_IF(XTE_WRAPPED(XTE_UNWRAP(TARGET))) \
				((... && noexcept(XTE_UNWRAP(XTE_UNWRAP(TARGET)) XTE_UNWRAP(INIT)))) \
				(noexcept(XTE_UNWRAP(TARGET) XTE_UNWRAP(INIT)))) \
			(noexcept(decltype(this->TARGET) XTE_UNWRAP(INIT))) \
			__VA_OPT__(DELIM DETAIL_XTE_ARROW_NOEX_NEXT XTE_PAREN() (DELIM, __VA_ARGS__))
#	define DETAIL_XTE_ARROW_NOEX_NEXT() DETAIL_XTE_ARROW_NOEX
#	define DETAIL_XTE_ARROW_FIRST_NOEX(...) requires { { __VA_ARGS__ } noexcept; }
#	define DETAIL_XTE_ARROW_FIRST_REQ(...) requires { __VA_ARGS__; }
#	define DETAIL_XTE_ARROW_FIRST(BODY, ...) \
		__VA_OPT__(if constexpr (requires { BODY; })) return (BODY); \
		__VA_OPT__(else DETAIL_XTE_ARROW_FIRST_NEXT XTE_PAREN() (__VA_ARGS__))
#	define DETAIL_XTE_ARROW_FIRST_NEXT() DETAIL_XTE_ARROW_FIRST
#	define DETAIL_XTE_ARROW_INIT(TARGET, INIT, ...) \
		XTE_UNWRAP(XTE_UNWRAP(TARGET)) XTE_UNWRAP(INIT) XTE_IF(XTE_WRAPPED(XTE_UNWRAP(TARGET)))(...)() \
		__VA_OPT__(, DETAIL_XTE_ARROW_INIT_NEXT XTE_PAREN() (__VA_ARGS__))
#	define DETAIL_XTE_ARROW_INIT_NEXT() DETAIL_XTE_ARROW_INIT
#endif
