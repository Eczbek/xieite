#ifndef XIEITE_HEADER_MATH_SIGN_CAST
#	define XIEITE_HEADER_MATH_SIGN_CAST

#	include <concepts>
#	include <type_traits>
#	include "../types/try_signed.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<std::integral Target_, std::integral Source_>
	[[nodiscard]] constexpr Target_ signCast(const Source_ value) noexcept {
		return static_cast<Target_>(static_cast<std::conditional_t<std::signed_integral<Target_>, xieite::types::TrySigned<Source_>, xieite::types::TryUnsigned<Source_>>>(value));
	}
}

#endif
