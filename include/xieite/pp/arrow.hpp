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
#	define XIEITE_ARROW_NOEX(...) \
		noexcept __VA_OPT__( \
			-> decltype(auto) \
			requires(requires { __VA_ARGS__; }) \
		) { return __VA_ARGS__; }
#	define XIEITE_ARROW_IF(_cond, _then, ...) \
		noexcept((!static_cast<bool>(_cond) || noexcept(_then)) __VA_OPT__(&& noexcept(__VA_ARGS__))) \
		-> decltype(auto) \
		requires((!static_cast<bool>(_cond) || requires { _then; }) __VA_OPT__(&& requires { __VA_ARGS__; })) \
		{ if constexpr (static_cast<bool>(_cond)) { _then; } return __VA_ARGS__; }
#	define XIEITE_ARROW_CHOOSE(_cond, _then, ...) \
		noexcept((static_cast<bool>(_cond) && noexcept(_then)) __VA_OPT__(|| (!static_cast<bool>(_cond) && noexcept(__VA_ARGS__)))) \
		-> decltype(auto) \
		requires((static_cast<bool>(_cond) && requires { _then; }) __VA_OPT__(|| (!static_cast<bool>(_cond) && requires { __VA_ARGS__; }))) \
		{ if constexpr (static_cast<bool>(_cond)) { return XIEITE_UNWRAP(_then); } else { return __VA_ARGS__; } }
#	define XIEITE_ARROW_TRY(_body, ...) \
		XIEITE_EVAL( \
			noexcept __VA_OPT__((DETAIL_XIEITE_ARROW_TRY(requires noexcept, __VA_ARGS__))) \
			-> decltype(auto) \
			requires(DETAIL_XIEITE_ARROW_TRY(,, _body, __VA_ARGS__)) \
			try { return XIEITE_UNWRAP(_body); } DETAIL_XIEITE_ARROW_CATCH(__VA_ARGS__) \
		)
#	define XIEITE_ARROW_DECL(_params, ...) \
		XIEITE_EVAL( \
			noexcept(requires DETAIL_XIEITE_ARROW_PARAMS(XIEITE_UNWRAP(_params)) { requires(noexcept(__VA_ARGS__)); }) \
			-> decltype(auto) \
			requires(requires DETAIL_XIEITE_ARROW_PARAMS(XIEITE_UNWRAP(_params)) { __VA_ARGS__; }) \
			{ return __VA_ARGS__; } \
		)
#	define XIEITE_ARROW_CTOR(_body, ...) \
		XIEITE_EVAL( \
			noexcept(XIEITE_OPT(_body)(noexcept(XIEITE_UNWRAP(_body)) &&)() DETAIL_XIEITE_ARROW_NOEX(&&, __VA_ARGS__)) \
			requires(requires { XIEITE_OPT(_body)(XIEITE_UNWRAP(_body);)() DETAIL_XIEITE_ARROW_NOEX(;, __VA_ARGS__); }) \
			: DETAIL_XIEITE_ARROW_INIT(__VA_ARGS__) \
			{ XIEITE_UNWRAP(_body); } \
		)
#
#	define DETAIL_XIEITE_ARROW_PARAMS(...) __VA_OPT__((DETAIL_XIEITE_EACH_HELPER(DETAIL_XIEITE_ARROW_PARAM, __VA_ARGS__)))
#	define DETAIL_XIEITE_ARROW_PARAM(_param) XIEITE_IF(XIEITE_WRAPPED(_param))(decltype _param&&... XIEITE_UNWRAP(_param))(decltype(_param)&& _param)
#	define DETAIL_XIEITE_ARROW_TRY(_noex, _except, _body, ...) XIEITE_OPT(_body)(requires XIEITE_OPT(_except)((XIEITE_UNWRAP(_except)))() { _noex(XIEITE_UNWRAP(_body)); })(true) __VA_OPT__(&& DETAIL_XIEITE_ARROW_TRY_NEXT XIEITE_PAREN() (_noex, __VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_TRY_NEXT() DETAIL_XIEITE_ARROW_TRY
#	define DETAIL_XIEITE_ARROW_CATCH(_except, _body, ...) catch (XIEITE_UNWRAP(XIEITE_OPT(_except)(_except)(...))) { return XIEITE_UNWRAP(_body); } __VA_OPT__(DETAIL_XIEITE_ARROW_CATCH_NEXT XIEITE_PAREN() (__VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_CATCH_NEXT() DETAIL_XIEITE_ARROW_CATCH
#	define DETAIL_XIEITE_ARROW_NOEX(_delim, _var, _value, ...) XIEITE_IF(XIEITE_WRAPPED(_var))(XIEITE_IF(XIEITE_WRAPPED(XIEITE_UNWRAP(_var)))((... && noexcept(XIEITE_UNWRAP(XIEITE_UNWRAP(_var)) XIEITE_UNWRAP(_value))))(noexcept(XIEITE_UNWRAP(_var) XIEITE_UNWRAP(_value))))(noexcept(decltype(this->_var) XIEITE_UNWRAP(_value))) __VA_OPT__(_delim DETAIL_XIEITE_ARROW_NOEX_NEXT XIEITE_PAREN() (_delim, __VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_NOEX_NEXT() DETAIL_XIEITE_ARROW_NOEX
#	define DETAIL_XIEITE_ARROW_INIT(_var, _value, ...) XIEITE_UNWRAP(XIEITE_UNWRAP(_var)) XIEITE_UNWRAP(_value)XIEITE_IF(XIEITE_WRAPPED(XIEITE_UNWRAP(_var)))(...)()__VA_OPT__(, DETAIL_XIEITE_ARROW_INIT_NEXT XIEITE_PAREN() (__VA_ARGS__))
#	define DETAIL_XIEITE_ARROW_INIT_NEXT() DETAIL_XIEITE_ARROW_INIT
#endif
