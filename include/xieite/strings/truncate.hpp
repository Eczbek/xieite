#ifndef XIEITE_HEADER__STRINGS__TRUNCATE
#	define XIEITE_HEADER__STRINGS__TRUNCATE

#	include <cstddef>
#	include <string>

namespace xieite::strings {
	constexpr std::string truncate(const std::string& string, const std::size_t length, const std::string& suffix = "") noexcept {
		return (string.size() <= length) ? string : ((suffix.size() > length) ? suffix.substr(0, length) : (string.substr(0, length - suffix.size()) + suffix));
	}
}

#endif
