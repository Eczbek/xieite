#ifndef XIEITE_HEADER_FUNCTORS_UNSIGNED_CAST
#	define XIEITE_HEADER_FUNCTORS_UNSIGNED_CAST

#	include <concepts>
#	include <type_traits>
#	include "../types/maybe_signed.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::functors {
	template<std::integral Target>
	struct UnsignedCast {
		template<std::integral Source>
		[[nodiscard]] constexpr Target operator()(const Source source) noexcept {
			return static_cast<Target>(static_cast<std::conditional_t<std::signed_integral<Target>, xieite::types::MaybeSigned<Source>, xieite::types::MaybeUnsigned<Source>>>(source));
		}
	};
}

#endif
