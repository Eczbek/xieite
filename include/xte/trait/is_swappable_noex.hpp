#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SWAPPABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_SWAPPABLE_NOEX
#
#	include "../meta/fake.hpp"
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_swappable_noex = noexcept(std::ranges::swap(xte::fake<T&>(), xte::fake<T&>()));
}

#endif
