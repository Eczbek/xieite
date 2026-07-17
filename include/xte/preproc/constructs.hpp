#ifndef DETAIL_XTE_HEADER_PREPROC_CONSTRUCTS
#	define DETAIL_XTE_HEADER_PREPROC_CONSTRUCTS
#
#	include "../preproc/any.hpp"
#	include "../preproc/eval.hpp"
#	include "../preproc/if.hpp"
#	include "../preproc/paren.hpp"
#	include "../preproc/unwrap.hpp"
#	include "../preproc/wrapped.hpp"
#
#	define XTE_CONSTRUCTS(BODY, ...) \
		XTE_EVAL(noexcept(XTE_IF(XTE_ANY(BODY))(noexcept(BODY) __VA_OPT__(&&))() __VA_OPT__(DETAIL_XTE_CONSTRUCTS_NOEX(&&, __VA_ARGS__))) \
		requires(requires { XTE_IF(XTE_ANY(BODY))(BODY;)() __VA_OPT__(DETAIL_XTE_CONSTRUCTS_NOEX(;, __VA_ARGS__);) }) \
		__VA_OPT__(: DETAIL_XTE_CONSTRUCTS_INIT(__VA_ARGS__))) \
		{ BODY XTE_IF(XTE_ANY(BODY))(;)() }
#
#	define DETAIL_XTE_CONSTRUCTS_NOEX(DELIM, TARGET, INIT, ...) \
		XTE_IF(XTE_WRAPPED(TARGET)) \
			(XTE_IF(XTE_WRAPPED(XTE_UNWRAP(TARGET))) \
				((... && noexcept(XTE_UNWRAP(XTE_UNWRAP(TARGET)) XTE_UNWRAP(INIT)))) \
				(noexcept(XTE_UNWRAP(TARGET) XTE_UNWRAP(INIT)))) \
			(noexcept(decltype(this->TARGET) XTE_UNWRAP(INIT))) \
			__VA_OPT__(DELIM DETAIL_XTE_ARROW_NOEX_ XTE_PAREN() (DELIM, __VA_ARGS__))
#	define DETAIL_XTE_ARROW_NOEX_() DETAIL_XTE_CONSTRUCTS_NOEX
#	define DETAIL_XTE_CONSTRUCTS_INIT(TARGET, INIT, ...) \
		XTE_UNWRAP(XTE_UNWRAP(TARGET)) XTE_UNWRAP(INIT) XTE_IF(XTE_WRAPPED(XTE_UNWRAP(TARGET)))(...)() \
		__VA_OPT__(, DETAIL_XTE_ARROW_INIT_ XTE_PAREN() (__VA_ARGS__))
#	define DETAIL_XTE_ARROW_INIT_() DETAIL_XTE_CONSTRUCTS_INIT
#endif
