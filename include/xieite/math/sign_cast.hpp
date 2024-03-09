#ifndef XIEITE_HEADER_MATH_SIGN_CAST
#	define XIEITE_HEADER_MATH_SIGN_CAST

#	include <concepts>
#	include <type_traits>
#	include "../types/maybe_signed.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::integral Target, std::integral Source>
	[[nodiscard]] constexpr Target signCast(const Source value) noexcept {
		return static_cast<Target>(static_cast<std::conditional_t<std::signed_integral<Target>, xieite::types::MaybeSigned<Source>, xieite::types::MaybeUnsigned<Source>>>(value));
	}
}

#endif
