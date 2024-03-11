#ifndef XIEITE_HEADER_HASHES_DJB2
#	define XIEITE_HEADER_HASHES_DJB2

#	include <cstddef>
#	include <string_view>
#	include "../concepts/string_view.hpp"

namespace xieite::hashes {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr std::size_t djb2(const StringView value) noexcept {
		std::size_t result = 5381;
		for (const typename StringView::value_type character : value) {
			result = result * 33 + character;
		}
		return result;
	}
}

#endif
