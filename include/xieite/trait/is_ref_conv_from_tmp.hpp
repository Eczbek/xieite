#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_REF_CONV_FROM_TMP
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_REF_CONV_FROM_TMP
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_ref_conv_from_tmp = std::reference_converts_from_temporary_v<T, U>;
}

#endif
