#ifndef XIEITE_HEADER__STRINGS__SPLIT
#	define XIEITE_HEADER__STRINGS__SPLIT

#	include <ranges>
#	include <string>
#	include <string_view>
#	include <vector>

namespace xieite::strings {
	constexpr std::vector<std::string_view> split(const std::string_view string, const std::string_view delimiter) noexcept {
		std::vector<std::string_view> result;
		const auto subranges = std::views::split(string, delimiter);
		if (subranges) {
			for (const auto slice : subranges) {
				result.push_back(std::string_view(slice));
			}
		}
		return result;
	}

	constexpr std::vector<std::string_view> split(const std::string_view string, const char delimiter) noexcept {
		return xieite::strings::split(string, std::string(1, delimiter));
	}
}

#endif
