#ifndef XIEITE_HEADER_MATH_SIGN_CAST
#	define XIEITE_HEADER_MATH_SIGN_CAST

#	include <concepts>
#	include <type_traits>
#	include "../types/try_signed.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<std::integral Target, std::integral Source>
	[[nodiscard]] constexpr Target signCast(const Source value) noexcept {
		return static_cast<Target>(static_cast<std::conditional_t<std::signed_integral<Target>, xieite::types::TrySigned<Source>, xieite::types::TryUnsigned<Source>>>(value));
	}
}

#endif
