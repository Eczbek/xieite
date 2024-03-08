#ifndef XIEITE_HEADER_STRINGS_SPLIT
#	define XIEITE_HEADER_STRINGS_SPLIT

#	include <ranges>
#	include <string_view>
#	include <vector>
#	include "../concepts/string_view.hpp"
#	include "../functors/static_cast.hpp"
#	include "../strings/unview.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr std::vector<StringView> split(const StringView string, const StringView delimiter) noexcept {
		const auto subranges = std::views::split(string, delimiter);
		std::vector<StringView> result = std::vector<StringView>(std::ranges::size(subranges));
		std::ranges::transform(subranges, result.begin(), xieite::functors::StaticCast<StringView>());
		return result;
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr std::vector<StringView> split(const StringView string, const StringView::value_type delimiter) noexcept {
		const xieite::strings::Unview<StringView> delimiterString = xieite::strings::Unview<StringView>(1, delimiter);
		return xieite::strings::split(string, delimiterString);
	}
}

#endif
