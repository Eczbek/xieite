export module xieite:cmp_ignore_case;

import std;
import :id;
import :toupper;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::strong_ordering cmp_ignore_case(std::basic_string_view<Ch, Traits> left, xieite::id<std::basic_string_view<Ch, Traits>> right) noexcept {
		const std::size_t size = std::min(left.size(), right.size());
		for (std::size_t i = 0; i < size; ++i) {
			if (std::strong_ordering order = xieite::toupper(left[i]) <=> xieite::toupper(right[i]); !std::is_eq(order)) {
				return order;
			}
		}
		return std::strong_ordering::equal;
	}
}
