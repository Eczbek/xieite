#ifndef DETAIL_XIEITE_HEADER_MATH_SIGN_CAST
#	define DETAIL_XIEITE_HEADER_MATH_SIGN_CAST
#
#	include <concepts>
#	include <type_traits>
#	include "../trait/try_signed.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<std::integral Int>
	constexpr auto sign_cast = []<std::integral OtherInt>(OtherInt x) static noexcept {
		return static_cast<Int>(static_cast<std::conditional_t<std::signed_integral<Int>, xieite::try_signed<OtherInt>, xieite::try_unsigned<OtherInt>>>(x));
	};
}

#endif
