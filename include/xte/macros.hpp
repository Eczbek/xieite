#ifndef DETAIL_XTE_HEADER_PREPROC_FWD
#	define DETAIL_XTE_HEADER_PREPROC_FWD
#
#	include "./preproc.hpp"
#
#	define XTE_FWD(PARM) static_cast<decltype(PARM)&&>(PARM)
#
#	define XTE_TEMPLATE template for ([[maybe_unused]] char XTE_TEMPLATE : "")
#
#	define XTE_DECLARE(DECL, ...) \
		requires(requires { __VA_ARGS__; }) \
		XTE_UNWRAP(DECL) = __VA_ARGS__
#
#	define XTE_DECLARE_TYPE(DECL, ...) \
		requires(requires { typename[:^^__VA_ARGS__:]; }) \
		XTE_UNWRAP(DECL) : __VA_ARGS__
#
#	define XTE_RETURNS(...) \
		noexcept __VA_OPT__((noexcept(__VA_ARGS__)) \
		-> decltype(auto) \
		requires(requires { __VA_ARGS__; })) \
		{ __VA_OPT__(return (__VA_ARGS__);) }
#
#	define XTE_RETURNS_FIXED(...) \
		noexcept __VA_OPT__((noexcept(__VA_ARGS__)) \
		requires(requires { __VA_ARGS__; })) \
		{ __VA_OPT__(return (__VA_ARGS__);) }
#
#	define XTE_RETURNS_IF(COND, THEN, ...) \
		noexcept(([] { if constexpr (COND) if constexpr (!noexcept(THEN)) return false; return true __VA_OPT__(&& noexcept(__VA_ARGS__)); })()) \
		-> decltype(auto) \
		requires(([] { if constexpr (COND) if constexpr (!requires { THEN; }) return false; return true __VA_OPT__(&& requires { __VA_ARGS__; }); })()) \
		{ if constexpr (COND) { THEN; } __VA_OPT__(return (__VA_ARGS__);) }
#
#	define XTE_RETURNS_CHOOSE(COND, THEN, ...) \
		noexcept(([] { if constexpr (COND) return noexcept(THEN); else return true __VA_OPT__(&& noexcept(__VA_ARGS__)); })()) \
		-> decltype(auto) \
		requires(([] { if constexpr (COND) return requires { THEN; }; else return true __VA_OPT__(&& requires { __VA_ARGS__; }); })()) \
		{ if constexpr (COND) return (THEN); __VA_OPT__(else return (__VA_ARGS__);) }
#
#	define XTE_RETURNS_FIRST(LIST) \
		noexcept(([] { DETAIL_XTE_RETURNS_FIRST_NOEX_0 LIST() return true; })()) \
		-> decltype(auto) \
		requires(DETAIL_XTE_RETURNS_FIRST_REQ_0 LIST() false) \
		{ DETAIL_XTE_RETURNS_FIRST_BODY_0 LIST() {} }
#
#	define XTE_CONSTRUCTS(INIT_SEQ, ...) \
		noexcept(DETAIL_XTE_CONSTRUCTS_NOEX_0 INIT_SEQ() true __VA_OPT__(&& noexcept(__VA_ARGS__))) \
		requires(requires { DETAIL_XTE_CONSTRUCTS_NOEX_0 INIT_SEQ() true; __VA_OPT__(__VA_ARGS__;) }) \
		XTE_IF(XTE_ANY(INIT_SEQ))(: DETAIL_XTE_CONSTRUCTS_INIT_0 INIT_SEQ())() \
		{ __VA_OPT__(__VA_ARGS__;) }

#
#	define XTE_DEFINE_CAST(ATTR_SPEC, THIS, ...) \
	__VA_OPT__(XTE_IF(XTE_ANY(THIS))(template<typename DETAIL_XTE_arg_type>)() XTE_UNWRAP(ATTR_SPEC)) operator \
	decltype(XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) -> decltype(auto) { return (__VA_ARGS__); })(static_cast<[:^^DETAIL_XTE_arg_type():]*>(nullptr)()))(__VA_ARGS__)) \
	XTE_IF(XTE_ANY(THIS))((__VA_OPT__(this DETAIL_XTE_arg_type&& DETAIL_XTE_arg)))(() const) \
	noexcept __VA_OPT__((noexcept(XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) noexcept(noexcept(__VA_ARGS__)) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__))) \
	requires(requires { XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) requires(requires { __VA_ARGS__; }) {})(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); })) \
	{ return XTE_IF(XTE_ANY(THIS))(([](XTE_UNWRAP(THIS)) -> decltype(auto) { return (__VA_ARGS__); })(XTE_FWD(DETAIL_XTE_arg)))(__VA_ARGS__); }
#
#	define XTE_LIFT(...) DETAIL_XTE_LIFT(, ..., static, __VA_ARGS__)
#
#	define XTE_LIFT_UNARY(...) DETAIL_XTE_LIFT(, , static, __VA_ARGS__)
#
#	define XTE_LIFT_LOCAL(...) DETAIL_XTE_LIFT(&, ..., , __VA_ARGS__)
#
#	define XTE_LIFT_INFIX(...) DETAIL_XTE_LIFT_INFIX(, __VA_ARGS__)
#
#	define XTE_LIFT_MEMBER(...) DETAIL_XTE_LIFT_INFIX(..., __VA_ARGS__)
#
#	define XTE_LIFT_VAR(...) \
		([][[nodiscard]](auto&& DETAIL_XTE_obj) static noexcept { \
			return (XTE_FWD(DETAIL_XTE_obj)__VA_ARGS__); \
		})
#
#	define DETAIL_XTE_RETURNS_FIRST_NOEX(...) \
		if constexpr (requires { __VA_ARGS__; }) return noexcept(__VA_ARGS__);
#	define DETAIL_XTE_RETURNS_FIRST_BODY(...) \
		if constexpr (requires { __VA_ARGS__; }) return (__VA_ARGS__);
#	define DETAIL_XTE_RETURNS_FIRST_NOEX_0(...) \
		__VA_OPT__(DETAIL_XTE_RETURNS_FIRST_NOEX(__VA_ARGS__) else DETAIL_XTE_RETURNS_FIRST_NOEX_1)
#	define DETAIL_XTE_RETURNS_FIRST_NOEX_1(...) \
		__VA_OPT__(DETAIL_XTE_RETURNS_FIRST_NOEX(__VA_ARGS__) else DETAIL_XTE_RETURNS_FIRST_NOEX_0)
#	define DETAIL_XTE_RETURNS_FIRST_REQ_0(...) \
		__VA_OPT__(requires { __VA_ARGS__; } || DETAIL_XTE_RETURNS_FIRST_REQ_1)
#	define DETAIL_XTE_RETURNS_FIRST_REQ_1(...) \
		__VA_OPT__(requires { __VA_ARGS__; } || DETAIL_XTE_RETURNS_FIRST_REQ_0)
#	define DETAIL_XTE_RETURNS_FIRST_BODY_0(...) \
		__VA_OPT__(DETAIL_XTE_RETURNS_FIRST_BODY(__VA_ARGS__) else DETAIL_XTE_RETURNS_FIRST_BODY_1)
#	define DETAIL_XTE_RETURNS_FIRST_BODY_1(...) \
		__VA_OPT__(DETAIL_XTE_RETURNS_FIRST_BODY(__VA_ARGS__) else DETAIL_XTE_RETURNS_FIRST_BODY_0)
#	define DETAIL_XTE_CONSTRUCTS_NOEX(TARGET, ...) \
		XTE_IF(XTE_WRAPPED(TARGET)) \
			(XTE_IF(XTE_WRAPPED(XTE_UNWRAP(TARGET))) \
				((... && noexcept(XTE_UNWRAP(XTE_UNWRAP(TARGET))__VA_ARGS__))) \
				(noexcept(XTE_UNWRAP(TARGET)__VA_ARGS__))) \
			(noexcept(decltype(this->TARGET)__VA_ARGS__))
#	define DETAIL_XTE_CONSTRUCTS_INIT(TARGET, ...) \
		XTE_UNWRAP(XTE_UNWRAP(TARGET))__VA_ARGS__ XTE_IF(XTE_WRAPPED(XTE_UNWRAP(TARGET)))(...)()
#	define DETAIL_XTE_CONSTRUCTS_NOEX_0(...) \
		__VA_OPT__(DETAIL_XTE_CONSTRUCTS_NOEX(__VA_ARGS__) && DETAIL_XTE_CONSTRUCTS_NOEX_1)
#	define DETAIL_XTE_CONSTRUCTS_NOEX_1(...) \
		__VA_OPT__(DETAIL_XTE_CONSTRUCTS_NOEX(__VA_ARGS__) && DETAIL_XTE_CONSTRUCTS_NOEX_0)
#	define DETAIL_XTE_CONSTRUCTS_INIT_0(...) \
		__VA_OPT__(DETAIL_XTE_CONSTRUCTS_INIT(__VA_ARGS__) DETAIL_XTE_CONSTRUCTS_INIT_1)
#	define DETAIL_XTE_CONSTRUCTS_INIT_1(...) \
		__VA_OPT__(, DETAIL_XTE_CONSTRUCTS_INIT(__VA_ARGS__) DETAIL_XTE_CONSTRUCTS_INIT_2)
#	define DETAIL_XTE_CONSTRUCTS_INIT_2(...) \
		__VA_OPT__(, DETAIL_XTE_CONSTRUCTS_INIT(__VA_ARGS__) DETAIL_XTE_CONSTRUCTS_INIT_1)
#	define DETAIL_XTE_LIFT(CAPTURE, ELLIPSIS, SPEC, ...) \
		([CAPTURE][[nodiscard]](auto&&ELLIPSIS DETAIL_XTE_args) SPEC XTE_RETURNS( \
			__VA_ARGS__(XTE_FWD(DETAIL_XTE_args)ELLIPSIS) \
		))
#	define DETAIL_XTE_LIFT_INFIX(ELLIPSIS, ...) \
		([][[nodiscard]](auto&& DETAIL_XTE_lhs, auto&&ELLIPSIS DETAIL_XTE_rhs) XTE_RETURNS( \
			XTE_FWD(DETAIL_XTE_lhs)__VA_ARGS__(XTE_FWD(DETAIL_XTE_rhs)ELLIPSIS) \
		))
#endif
