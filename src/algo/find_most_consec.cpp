module;

#include <xieite/arrow.hpp>
#include <xieite/fn.hpp>

export module xieite:find_most_consec;

import std;
import :find_most_consec_if;
import :is_invoc;

export namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::equal_to>
	requires(std::ranges::sized_range<R>)
	[[nodiscard]] constexpr auto find_most_consec(R& range, std::ranges::range_common_reference_t<R> value, F&& comp = {})
	XIEITE_ARROW(xieite::find_most_consec_if(range, XIEITE_FN(std::invoke_r<bool>(comp, value, $0))))
}
