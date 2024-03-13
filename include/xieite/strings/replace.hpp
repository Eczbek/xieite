#ifndef XIEITE_HEADER_STRINGS_REPLACE
#	define XIEITE_HEADER_STRINGS_REPLACE

#	include <string>
#	include "../concepts/string.hpp"
#	include "../strings/view.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String replace(const xieite::strings::View<String> value, const xieite::strings::View<String> replace, const xieite::strings::View<String> with, const std::size_t start = 0) noexcept {
		String result = String(value);
		std::size_t i = start;
		while (true) {
			i = result.find(replace, i);
			if (i == String::npos) {
				break;
			}
			result.replace(i, replace.size(), with);
			i += with.size();
		}
		return result;
	}

	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr std::string replace(const xieite::strings::View<String> value, const typename String::value_type replace, const xieite::strings::View<String> with, const std::size_t start = 0) noexcept {
		const String replaceString = String(1, replace);
		return xieite::strings::replace(value, replaceString, with, start);
	}

	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr std::string replace(const xieite::strings::View<String> value, const xieite::strings::View<String> replace, const typename String::value_type with, const std::size_t start = 0) noexcept {
		const String withString = String(1, with);
		return xieite::strings::replace(value, replace, withString, start);
	}

	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr std::string replace(const xieite::strings::View<String> value, const typename String::value_type replace, const typename String::value_type with, const std::size_t start = 0) noexcept {
		const String replaceString = String(replace);
		const String withString = String(replace);
		return xieite::strings::replace(value, replaceString, withString, start);
	}
}

#endif
