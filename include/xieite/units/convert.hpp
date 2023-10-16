#ifndef XIEITE_HEADER_UNITS_CONVERT
#	define XIEITE_HEADER_UNITS_CONVERT

#	include <ratio>
#	include "../concepts/numeric.hpp"
#	include "../concepts/ratio.hpp"
#	include "../math/result.hpp"

namespace xieite::units {
	template<xieite::concepts::Ratio Source, xieite::concepts::Ratio Target, xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> convert(const Number value) noexcept {
		return static_cast<xieite::math::Result<Number>>(value) * Source::num * Target::den / Source::den / Target::num;
	}
}

#endif
