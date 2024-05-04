#ifndef XIEITE_HEADER_TRAITS_IS_DURATION
#	define XIEITE_HEADER_TRAITS_IS_DURATION

#	include <chrono>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/ratio.hpp"

namespace xieite::traits {
	template<typename>
	struct IsDuration
	: std::false_type {};

	template<xieite::concepts::Arithmetic Arithmetic_, xieite::concepts::Ratio Ratio_>
	struct IsDuration<std::chrono::duration<Arithmetic_, Ratio_>>
	: std::true_type {};
}

#endif
