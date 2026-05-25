#ifndef DETAIL_XTE_HEADER_PREPROC_LIFT
#	define DETAIL_XTE_HEADER_PREPROC_LIFT
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include <meta>
#
#	define XTE_LIFT(...) DETAIL_XTE_LIFT(, ..., static, __VA_ARGS__)
#	define XTE_LIFT_UNARY(...) DETAIL_XTE_LIFT(, , static, __VA_ARGS__)
#	define XTE_LIFT_LOCAL(...) DETAIL_XTE_LIFT(&, ..., , __VA_ARGS__)
#	define XTE_LIFT_INFIX(...) DETAIL_XTE_LIFT_INFIX(, __VA_ARGS__)
#	define XTE_LIFT_MEMBER(...) DETAIL_XTE_LIFT_INFIX(..., __VA_ARGS__)
#	define XTE_LIFT_VAR(...) \
		([][[nodiscard]](auto&& DETAIL_XTE_obj) static noexcept { \
			return (XTE_FWD(DETAIL_XTE_obj)__VA_ARGS__); \
		})
#
#	define DETAIL_XTE_LIFT(CAPTURE, ELLIPSIS, SPEC, ...) \
		([CAPTURE][[nodiscard]](auto&&ELLIPSIS DETAIL_XTE_args) SPEC XTE_ARROW( \
			__VA_ARGS__(XTE_FWD(DETAIL_XTE_args)ELLIPSIS) \
		))
#	define DETAIL_XTE_LIFT_INFIX(ELLIPSIS, ...) \
		([][[nodiscard]](auto&& DETAIL_XTE_lhs, auto&&ELLIPSIS DETAIL_XTE_rhs) XTE_ARROW( \
			XTE_FWD(DETAIL_XTE_lhs)__VA_ARGS__(XTE_FWD(DETAIL_XTE_rhs)ELLIPSIS) \
		))
#endif
