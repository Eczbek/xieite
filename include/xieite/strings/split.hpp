#ifndef XIEITE_HEADER_STRINGS_SPLIT
#	define XIEITE_HEADER_STRINGS_SPLIT

#	include <ranges>
#	include <string_view>
#	include <vector>
#	include "../functors/static_cast.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr std::vector<std::string_view> split(const std::string_view string, const std::string_view delimiter) noexcept {
		const auto subranges = std::views::split(string, delimiter);
		std::vector<std::string_view> result = std::vector<std::string_view>(std::ranges::size(subranges));
		std::ranges::transform(subranges, result.begin(), xieite::functors::StaticCast<std::string_view>());
		return result;
	}

	template<xieite::concepts::std::string_view std::string_view = std::string_view>
	[[nodiscard]] constexpr std::vector<std::string_view> split(const std::string_view string, const char delimiter) noexcept {
		return xieite::strings::split(string, std::string_view(&delimiter, 1));
	}
}

#endif
