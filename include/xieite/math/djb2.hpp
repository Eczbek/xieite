#ifndef DETAIL_XIEITE_HEADER_MATH_DJB2
#	define DETAIL_XIEITE_HEADER_MATH_DJB2
#
#	include <string_view>

namespace xieite {
	[[nodiscard]] constexpr unsigned long long int djb2(std::string_view strv) noexcept {
		unsigned long long int result = 5381;
		for (char c : strv) {
			(result *= 33) += static_cast<unsigned char>(c);
		}
		return result;
	}
}

#endif
