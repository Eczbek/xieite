#ifndef DETAIL_XTE_HEADER_LITERAL_INFO
#	define DETAIL_XTE_HEADER_LITERAL_INFO
#
#	include "../util/number_types.hpp"
#	include <meta>
#	include <ranges>

namespace xte::literal::info {
	[[nodiscard]] consteval std::meta::info operator""_info(unsigned long long x) noexcept {
		return std::meta::reflect_constant(x);
	}

	[[nodiscard]] consteval std::meta::info operator""_info(long double x) noexcept {
		return std::meta::reflect_constant(x);
	}

	[[nodiscard]] consteval std::meta::info operator""_info(const char* string, xte::uz size) noexcept {
		return std::meta::reflect_constant_string(std::ranges::subrange(string, string + size));
	}
}

#endif
