#ifndef DETAIL_XTE_HEADER_PREPROC_LIFT
#	define DETAIL_XTE_HEADER_PREPROC_LIFT
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include <meta>
#
#	define XTE_LIFT(...) DETAIL_XTE_LIFT(, ..., static, __VA_ARGS__)
#	define XTE_LIFT_ONE(...) DETAIL_XTE_LIFT(, , static, __VA_ARGS__)
#	define XTE_LIFT_LOCAL(...) DETAIL_XTE_LIFT(&, ..., , __VA_ARGS__)
#	define XTE_LIFT_INFIX(...) DETAIL_XTE_LIFT_INFIX(, __VA_ARGS__)
#	define XTE_LIFT_MEMBER(...) DETAIL_XTE_LIFT_INFIX(..., __VA_ARGS__)
#
#	define DETAIL_XTE_LIFT(_capture, _ellipsis, _specs, ...) \
		([_capture][[nodiscard]](auto&&_ellipsis DETAIL_XTE_args) _specs XTE_ARROW( \
			__VA_ARGS__(XTE_FWD(DETAIL_XTE_args)_ellipsis) \
		))
#	define DETAIL_XTE_LIFT_INFIX(_ellipsis, ...) \
		([][[nodiscard]](auto&& DETAIL_XTE_lhs, auto&&_ellipsis DETAIL_XTE_rhs) XTE_ARROW( \
			XTE_FWD(DETAIL_XTE_lhs)__VA_ARGS__(XTE_FWD(DETAIL_XTE_rhs)_ellipsis) \
		))
#endif
