#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ORDER
#	define DETAIL_XTE_HEADER_TRAIT_IS_ORDER
#
#	include "../trait/is_same_any.hpp"
#	include "../trait/remove_cv.hpp"
#	include <compare>

namespace xte {
	template<typename T>
	concept is_order = xte::is_same_any<xte::remove_cv<T>, std::strong_ordering, std::weak_ordering, std::partial_ordering>;
}

#endif
