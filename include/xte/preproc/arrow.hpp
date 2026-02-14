#ifndef DETAIL_XTE_HEADER_PREPROC_ARROW
#	define DETAIL_XTE_HEADER_PREPROC_ARROW
#
#	include "../preproc/any.hpp"
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
		{ __VA_OPT__(return __VA_ARGS__;) }
#	define XTE_ARROW_RETURN(...) \
		noexcept __VA_OPT__((noexcept(__VA_ARGS__)) \
		requires(requires { __VA_ARGS__; })) \
		{ __VA_OPT__(return __VA_ARGS__;) }
#	define XTE_ARROW_IF(_cond, _then, ...) \
		noexcept((!static_cast<bool>(_cond) || noexcept(_then)) __VA_OPT__(&& noexcept(__VA_ARGS__))) \
		-> decltype(auto) \
		requires((!static_cast<bool>(_cond) || requires { _then; }) __VA_OPT__(&& requires { __VA_ARGS__; })) \
		{ if constexpr (static_cast<bool>(_cond)) { _then; } return __VA_ARGS__; }
#	define XTE_ARROW_CHOOSE(_cond, _then, ...) \
		noexcept((static_cast<bool>(_cond) && noexcept(_then)) __VA_OPT__(|| (!static_cast<bool>(_cond) && noexcept(__VA_ARGS__)))) \
		-> decltype(auto) \
		requires((static_cast<bool>(_cond) && requires { _then; }) __VA_OPT__(|| (!static_cast<bool>(_cond) && requires { __VA_ARGS__; }))) \
		{ if constexpr (static_cast<bool>(_cond)) { return XTE_UNWRAP(_then); } else { return __VA_ARGS__; } }
#	define XTE_ARROW_CAST(_attr_spec, _arg, ...) \
		__VA_OPT__(XTE_IF(XTE_ANY(_arg))(template<typename DETAIL_XTE_Arg>)() XTE_UNWRAP(_attr_spec)) operator \
		decltype(XTE_IF(XTE_ANY(__VA_ARGS__))(XTE_IF(XTE_ANY(_arg))(([](XTE_UNWRAP(_arg)) -> decltype(auto) { return __VA_ARGS__; })(static_cast<DETAIL_XTE_Arg(*)()>(nullptr)()))(__VA_ARGS__))(void())) \
		XTE_IF(XTE_ANY(_arg))((__VA_OPT__(this DETAIL_XTE_Arg&& DETAIL_XTE_arg)))(() const) \
		noexcept __VA_OPT__((requires { XTE_IF(XTE_ANY(_arg))(([](XTE_UNWRAP(_arg)) requires(noexcept(__VA_ARGS__)) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); }) \
		requires(requires { XTE_IF(XTE_ANY(_arg))(([](XTE_UNWRAP(_arg)) requires(requires { __VA_ARGS__; }) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); })) \
		{ return XTE_IF(XTE_ANY(_arg))(([](XTE_UNWRAP(_arg)) -> decltype(auto) { return __VA_ARGS__; })(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); }
#	define XTE_ARROW_CTOR(_body, ...) \
		XTE_EVAL(noexcept(XTE_IF(XTE_ANY(_body))(noexcept(_body) __VA_OPT__(&&))() __VA_OPT__(DETAIL_XTE_ARROW_NOEX(&&, __VA_ARGS__))) \
		requires(requires { XTE_IF(XTE_ANY(_body))(_body;)() __VA_OPT__(DETAIL_XTE_ARROW_NOEX(;, __VA_ARGS__);) }) \
		__VA_OPT__(: DETAIL_XTE_ARROW_INIT(__VA_ARGS__)) \
		{ _body; })
#
#	define DETAIL_XTE_ARROW_NOEX(_delim, _target, _init, ...) \
		XTE_IF(XTE_WRAPPED(_target)) \
			(XTE_IF(XTE_WRAPPED(XTE_UNWRAP(_target))) \
				((... && noexcept(XTE_UNWRAP(XTE_UNWRAP(_target)) XTE_UNWRAP(_init)))) \
				(noexcept(XTE_UNWRAP(_target) XTE_UNWRAP(_init)))) \
			(noexcept(decltype(this->_target) XTE_UNWRAP(_init))) \
			__VA_OPT__(_delim DETAIL_XTE_ARROW_NOEX_NEXT XTE_PAREN() (_delim, __VA_ARGS__))
#	define DETAIL_XTE_ARROW_NOEX_NEXT() DETAIL_XTE_ARROW_NOEX
#	define DETAIL_XTE_ARROW_INIT(_target, _init, ...) \
		XTE_UNWRAP(XTE_UNWRAP(_target)) XTE_UNWRAP(_init) XTE_IF(XTE_WRAPPED(XTE_UNWRAP(_target)))(...)() \
		__VA_OPT__(, DETAIL_XTE_ARROW_INIT_NEXT XTE_PAREN() (__VA_ARGS__))
#	define DETAIL_XTE_ARROW_INIT_NEXT() DETAIL_XTE_ARROW_INIT
#endif
