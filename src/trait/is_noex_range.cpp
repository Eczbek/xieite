export module xieite:is_noex_range;

import std;
import :is_noex_iter;
import :is_noex_sentinel;

export namespace xieite {
	template<typename T>
	concept is_noex_range =
		std::ranges::range<T>
		&& xieite::is_noex_iter<std::ranges::iterator_t<T>>
		&& xieite::is_noex_sentinel<std::ranges::sentinel_t<T>, std::ranges::iterator_t<T>>
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
