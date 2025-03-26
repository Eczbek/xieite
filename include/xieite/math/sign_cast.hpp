#ifndef DETAIL_XIEITE_HEADER_MATH_SIGN_CAST
#	define DETAIL_XIEITE_HEADER_MATH_SIGN_CAST
#
#	include <concepts>
#	include <type_traits>
#	include "../meta/try_sign.hpp"
#	include "../trait/try_unsign.hpp"

namespace xieite {
	template<std::integral T>
	constexpr auto sign_cast = []<std::integral U>(U n) static noexcept {
		return static_cast<T>(static_cast<std::conditional_t<std::signed_integral<T>, xieite::try_sign<U>, xieite::try_unsign<U>>>(n));
	};
}

#endif
