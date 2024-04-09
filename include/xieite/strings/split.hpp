#ifndef XIEITE_HEADER_STRINGS_SPLIT
#	define XIEITE_HEADER_STRINGS_SPLIT

#	include <ranges>
#	include <string_view>
#	include <vector>

namespace xieite::strings {
	[[nodiscard]] constexpr std::vector<std::string_view> split(const std::string_view string, const std::string_view delimiter, const bool discardEmpty = false) noexcept {
		const auto subranges = std::views::split(string, delimiter);
		std::vector<std::string_view> result;
		result.reserve(std::ranges::size(subranges));
		for (const auto subrange : subranges) {
			if (!discardEmpty || (std::ranges::begin(subrange) != std::ranges::end(subrange))) {
				result.push_back(std::string_view(subrange));
			}
		}
		return result;
	}

	template<xieite::concepts::std::string_view std::string_view = std::string_view>
	[[nodiscard]] constexpr std::vector<std::string_view> split(const std::string_view string, const char delimiter, const bool discardEmpty = false) noexcept {
		return xieite::strings::split(string, std::string_view(&delimiter, 1), discardEmpty);
	}
}

#endif
