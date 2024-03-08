#ifndef XIEITE_HEADER_STRINGS_JOIN
#	define XIEITE_HEADER_STRINGS_JOIN

#	include <concepts>
#	include <ranges>
#	include <string>
#	include "../concepts/string.hpp"
#	include "../macros/forward.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string, std::ranges::range Range>
	requires(std::constructible_from<String, std::ranges::range_const_reference_t<Range>>)
	[[nodiscard]] constexpr String join(Range&& range, const String& delimiter = "") noexcept {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		String result = String(*iterator);
		while (++iterator != end) {
			result += delimiter + String(*iterator);
		}
		return result;
	}

	template<xieite::concepts::String String = std::string, std::ranges::range Range>
	requires(std::constructible_from<String, std::ranges::range_const_reference_t<Range>>)
	[[nodiscard]] constexpr String join(Range&& range, const String::value_type delimiter) noexcept {
		return xieite::strings::join(XIEITE_FORWARD(range), String(1, delimiter));
	}
}

#endif
