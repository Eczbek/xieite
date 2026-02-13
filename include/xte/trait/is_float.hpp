#ifndef DETAIL_XTE_HEADER_TRAIT_IS_FLOAT
#	define DETAIL_XTE_HEADER_TRAIT_IS_FLOAT
#
#	include "../preproc/feature.hpp"
#	include "../preproc/if.hpp"
#	include "../trait/is_same_any_ignore_cv.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<typename T>
	concept is_float = xte::is_same_any_ignore_cv<T,
		float,
		double,
		long double
		XTE_IF(XTE_FEATURE_FLOAT_16)(, xte::f16)()
		XTE_IF(XTE_FEATURE_FLOAT_32)(, xte::f32)()
		XTE_IF(XTE_FEATURE_FLOAT_64)(, xte::f64)()
		XTE_IF(XTE_FEATURE_FLOAT_128)(, xte::f128)()
		XTE_IF(XTE_FEATURE_BFLOAT_16)(, xte::bf16)()
	>;
}

#endif
