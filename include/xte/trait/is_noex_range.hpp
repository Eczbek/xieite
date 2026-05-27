#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_RANGE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_RANGE
#
#	include "../trait/is_noex_iter.hpp"
#	include "../trait/is_noex_sentinel.hpp"
#	include <ranges>

namespace xte {
	template<typename T>
	concept is_noex_range =
		std::ranges::range<T>
		&& xte::is_noex_iter<std::ranges::iterator_t<T>>
		&& xte::is_noex_sentinel<std::ranges::sentinel_t<T>, std::ranges::iterator_t<T>>
		&& requires(T range) {
			{ std::ranges::begin(range) } noexcept;
			{ std::ranges::end(range) } noexcept;
			{ std::ranges::cbegin(range) } noexcept;
			{ std::ranges::cend(range) } noexcept;
			{ std::ranges::rbegin(range) } noexcept;
			{ std::ranges::rend(range) } noexcept;
			{ std::ranges::crbegin(range) } noexcept;
			{ std::ranges::crend(range) } noexcept;
			{ std::ranges::size(range) } noexcept;
			{ std::ranges::ssize(range) } noexcept;
			{ std::ranges::empty(range) } noexcept;
			{ std::ranges::data(range) } noexcept;
			{ std::ranges::cdata(range) } noexcept;
		};
}

#endif
