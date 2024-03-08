#ifndef XIEITE_HEADER_STRINGS_BETWEEN
#	define XIEITE_HEADER_STRINGS_BETWEEN

#	include <string>
#	include <string_view>
#	include "../concepts/string_view.hpp"
#	include "../strings/after.hpp"
#	include "../strings/before.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView between(const StringView string, const StringView start, const StringView end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView between(const StringView string, const StringView start, const StringView::value_type end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView between(const StringView string, const StringView::value_type start, const StringView end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView between(const StringView string, const StringView::value_type start, const StringView::value_type end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}
}

#endif
