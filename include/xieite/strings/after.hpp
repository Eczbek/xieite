#ifndef XIEITE_HEADER_STRINGS_AFTER
#	define XIEITE_HEADER_STRINGS_AFTER

#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../concepts/string_view.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView after(const StringView string, const StringView start) noexcept {
		const std::size_t index = string.find(start);
		return (index == StringView::npos) ? "" : string.substr(index + start.size());
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView after(const StringView string, const StringView::value_type start) noexcept {
		const std::size_t index = string.find(start);
		return (index == StringView::npos) ? "" : string.substr(index + 1);
	}
}

#endif
