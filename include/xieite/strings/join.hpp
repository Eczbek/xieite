#ifndef XIEITE_HEADER_STRINGS_JOIN
#	define XIEITE_HEADER_STRINGS_JOIN

#	include <concepts>
#	include <ranges>
#	include <string>
#	include "../macros/forward.hpp"

namespace xieite::strings {
	template<std::ranges::range Range>
	requires(std::constructible_from<std::string, std::ranges::range_const_reference_t<Range>>)
	[[nodiscard]] constexpr std::string join(Range&& range, const std::string& delimiter = "") noexcept {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		std::string result = std::string(*iterator);
		while (++iterator != end) {
			result += delimiter + std::string(*iterator);
		}
		return result;
	}

	template<std::ranges::range Range>
	requires(std::constructible_from<std::string, std::ranges::range_const_reference_t<Range>>)
	[[nodiscard]] constexpr std::string join(Range&& range, const char delimiter) noexcept {
		return xieite::strings::join(XIEITE_FORWARD(range), std::string(1, delimiter));
	}
}

#endif
