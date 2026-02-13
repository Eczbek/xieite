#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_SWAPPABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_SWAPPABLE
#
#	include "../meta/fake.hpp"
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_noex_swappable = noexcept(std::ranges::swap(xte::fake<T>(), xte::fake<T>()));
}

#endif
