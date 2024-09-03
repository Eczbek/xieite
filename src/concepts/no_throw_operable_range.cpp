export module xieite:concepts.NoThrowOperableRange;

import std;
import :concepts.NoThrowOperableIterator;

export namespace xieite::concepts {
	template<typename Range>
	concept NoThrowOperableRange = std::ranges::range<Range> && xieite::concepts::NoThrowOperableIterator<std::ranges::iterator_t<Range>> && requires(Range range) {
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
