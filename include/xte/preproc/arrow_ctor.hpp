#ifndef DETAIL_XTE_HEADER_PREPROC_ARROW_CTOR
#	define DETAIL_XTE_HEADER_PREPROC_ARROW_CTOR
#
#	include "../preproc/any.hpp"
#	include "../preproc/eval.hpp"
#	include "../preproc/if.hpp"
#	include "../preproc/paren.hpp"
#	include "../preproc/unwrap.hpp"
#	include "../preproc/wrapped.hpp"
#
#	define XTE_ARROW_CTOR(_body, ...) XTE_EVAL( \
		noexcept(XTE_IF(XTE_ANY(_body))(noexcept(_body) &&)() DETAIL_XTE_ARROW_NOEX(&&, __VA_ARGS__)) \
		requires(requires { XTE_IF(XTE_ANY(_body))(_body;)() DETAIL_XTE_ARROW_NOEX(;, __VA_ARGS__); }) \
		: DETAIL_XTE_ARROW_INIT(__VA_ARGS__) \
		{ _body; } \
	)
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
