module;

#include <xieite/arrow.hpp>
#include <xieite/fn.hpp>

export module xieite:find_occur;

import std;
import :find_occur_if;
import :is_invoc;

export namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_reference_t<R>, std::ranges::range_reference_t<R>)> F = std::ranges::equal_to>
	[[nodiscard]] constexpr auto find_occur(R& range, std::size_t n, std::ranges::range_reference_t<R> value, F&& comp = {})
	XIEITE_ARROW(xieite::find_occur_if(range, n, XIEITE_FN(std::invoke_r<bool>(comp, value, $0))))
}
