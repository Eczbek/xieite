#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ORDER
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ORDER
#
#	include <compare>
#	include <type_traits>
#	include "../trait/is_same_any.hpp"

namespace xieite {
	template<typename T>
	concept is_order = xieite::is_same_any<std::remove_cv_t<T>, std::strong_ordering, std::weak_ordering, std::partial_ordering>;
}

#endif
