#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_REF
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	using rm_ref = std::remove_reference_t<T>;
}

#endif
