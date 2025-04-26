#ifndef DETAIL_XIEITE_HEADER_MATH_DJB2
#	define DETAIL_XIEITE_HEADER_MATH_DJB2
#
#	include <cstddef>
#	include <string_view>
#	include "../math/sign_cast.hpp"

namespace xieite {
	[[nodiscard]] constexpr std::size_t djb2(std::string_view strv) noexcept {
		std::size_t result = 5381;
		for (char c : strv) {
			result = result * 33 + xieite::sign_cast<std::size_t>(c);
		}
		return result;
	}
}

#endif
