#ifndef XIEITE_HEADER_STRINGS_JOIN
#	define XIEITE_HEADER_STRINGS_JOIN

#	include <ranges>
#	include <string>
#	include <string_view>
#	include "../macros/forward.hpp"

namespace xieite::strings {
	template<std::ranges::range Range>
	requires(std::constructible_from<std::string, std::ranges::range_const_reference_t<Range>>)
	[[nodiscard]] constexpr std::string join(Range&& range, const std::string_view delimiter = "") noexcept {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		std::string result = std::string(*iterator);
		while (++iterator != end) {
			result += std::string(delimiter) + std::string(*iterator);
		}
		return result;
	}

	template<std::ranges::range Range>
	requires(std::constructible_from<std::string, std::ranges::range_const_reference_t<Range>>)
	[[nodiscard]] constexpr std::string join(Range&& range, const char delimiter) noexcept {
		return xieite::strings::join(XIEITE_FORWARD(range), std::string_view(&delimiter, 1));
	}
}

#endif
