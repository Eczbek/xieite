#ifndef XIEITE_HEADER_STRINGS_BEFORE
#	define XIEITE_HEADER_STRINGS_BEFORE

#	include <string>
#	include <string_view>
#	include "../concepts/string_view.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView before(const StringView string, const StringView end) noexcept {
		return string.substr(0, string.find(end));
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView before(const StringView string, const StringView::value_type end) noexcept {
		return string.substr(0, string.find(end));
	}
}

#endif
