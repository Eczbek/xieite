#ifndef DETAIL_XTE_HEADER_PREPROC_DEFINE_CAST
#	define DETAIL_XTE_HEADER_PREPROC_DEFINE_CAST
#
#	include "../preproc/any.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/if.hpp"
#	include "../preproc/unwrap.hpp"
#
#	define XTE_DEFINE_CAST(ATTR_SPEC, THIS, ...) \
		__VA_OPT__(XTE_IF(XTE_ANY(THIS))(template<typename DETAIL_XTE_Arg>)() XTE_UNWRAP(ATTR_SPEC)) operator \
		decltype(XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) -> decltype(auto) { return (__VA_ARGS__); })(static_cast<[:^^DETAIL_XTE_Arg():]*>(nullptr)()))(__VA_ARGS__)) \
		XTE_IF(XTE_ANY(THIS))((__VA_OPT__(this DETAIL_XTE_Arg&& DETAIL_XTE_arg)))(() const) \
		noexcept __VA_OPT__((noexcept(XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) noexcept(noexcept(__VA_ARGS__)) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__))) \
		requires(requires { XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) requires(requires { __VA_ARGS__; }) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); })) \
		{ return XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) -> decltype(auto) { return (__VA_ARGS__); })(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); }
#endif
