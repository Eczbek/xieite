#ifndef DETAIL_XIEITE_HEADER_MATH_PI
#	define DETAIL_XIEITE_HEADER_MATH_PI
#
#	include <concepts>
#	include <numbers>

namespace xieite {
	template<typename>
	constexpr double pi = std::numbers::pi;

	template<std::floating_point Float>
	constexpr Float pi<Float> = std::numbers::pi_v<Float>;

	template<std::integral Int>
	constexpr Int pi<Int> = static_cast<Int>(std::numbers::pi);
}

#endif
