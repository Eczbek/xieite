#ifndef DETAIL_XTE_HEADER_PREPROC_RETURNS
#	define DETAIL_XTE_HEADER_PREPROC_RETURNS
#
#	include "../preproc/each.hpp"
#	include "../preproc/eval.hpp"
#	include "../preproc/paren.hpp"
#
#	define XTE_RETURNS(...) \
		noexcept __VA_OPT__((noexcept(__VA_ARGS__)) \
		-> decltype(auto) \
		requires(requires { __VA_ARGS__; })) \
		{ __VA_OPT__(return (__VA_ARGS__);) }
#	define XTE_RETURNS_IF(COND, THEN, ...) \
		noexcept((!static_cast<bool>(COND) || noexcept(THEN)) __VA_OPT__(&& noexcept(__VA_ARGS__))) \
		-> decltype(auto) \
		requires((!static_cast<bool>(COND) || requires { THEN; }) __VA_OPT__(&& requires { __VA_ARGS__; })) \
		{ if constexpr (static_cast<bool>(COND)) { THEN; } __VA_OPT__(return (__VA_ARGS__);) }
#	define XTE_RETURNS_CHOOSE(COND, THEN, ...) \
		noexcept((static_cast<bool>(COND) && noexcept(THEN)) __VA_OPT__(|| (!static_cast<bool>(COND) && noexcept(__VA_ARGS__)))) \
		-> decltype(auto) \
		requires((static_cast<bool>(COND) && requires { THEN; }) __VA_OPT__(|| (!static_cast<bool>(COND) && requires { __VA_ARGS__; }))) \
		{ if constexpr (static_cast<bool>(COND)) { return (THEN); } __VA_OPT__(else { return (__VA_ARGS__); }) }
#	define XTE_RETURNS_FIRST(...) \
		noexcept(XTE_EACH_DELIM(DETAIL_XTE_RETURNS_FIRST_NOEX, ||, __VA_ARGS__)) \
		-> decltype(auto) \
		requires(XTE_EACH_DELIM(DETAIL_XTE_RETURNS_FIRST_REQ, ||, __VA_ARGS__)) \
		{ XTE_EVAL(DETAIL_XTE_RETURNS_FIRST(__VA_ARGS__)) }
#
#	define DETAIL_XTE_RETURNS_FIRST(BODY, ...) \
		__VA_OPT__(if constexpr (requires { BODY; })) return (BODY); \
		__VA_OPT__(else DETAIL_XTE_RETURNS_FIRST_ XTE_PAREN() (__VA_ARGS__))
#	define DETAIL_XTE_RETURNS_FIRST_() DETAIL_XTE_RETURNS_FIRST
#	define DETAIL_XTE_RETURNS_FIRST_NOEX(...) requires { { __VA_ARGS__ } noexcept; }
#	define DETAIL_XTE_RETURNS_FIRST_REQ(...) requires { __VA_ARGS__; }
#endif
