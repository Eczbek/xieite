#pragma once

#include <ranges>
#include "../trait/isnoexiter.hpp"
#include "../trait/isnoexsentinel.hpp"

namespace x4 {
	template<typename T>
	concept isnoexrange =
		std::ranges::range<T>
		&& x4::isnoexiter<std::ranges::iterator_t<T>>
		&& x4::isnoexsentinel<std::ranges::sentinel_t<T>, std::ranges::iterator_t<T>>
		&& requires (T range) {
			requires(noexcept(std::ranges::begin(range)));
			requires(noexcept(std::ranges::end(range)));
			requires(noexcept(std::ranges::cbegin(range)));
			requires(noexcept(std::ranges::cend(range)));
			requires(noexcept(std::ranges::rbegin(range)));
			requires(noexcept(std::ranges::rend(range)));
			requires(noexcept(std::ranges::crbegin(range)));
			requires(noexcept(std::ranges::crend(range)));
			requires(noexcept(std::ranges::size(range)));
			requires(noexcept(std::ranges::ssize(range)));
			requires(noexcept(std::ranges::empty(range)));
			requires(noexcept(std::ranges::data(range)));
			requires(noexcept(std::ranges::cdata(range)));
		};
}
