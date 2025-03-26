#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_REF_TO
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_REF_TO
#
#	include <concepts>
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	concept is_ref_to = std::same_as<xieite::rm_ref<T>, U>;
}

#endif
