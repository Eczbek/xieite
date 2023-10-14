#ifndef XIEITE_HEADER_UNITS_CONVERT
#	define XIEITE_HEADER_UNITS_CONVERT

#	include <ratio>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/ratio.hpp"
#	include "../math/result.hpp"

namespace xieite::units {
	template<xieite::concepts::Ratio Source, xieite::concepts::Ratio Target, xieite::concepts::Arithmetic Value>
	[[nodiscard]] constexpr xieite::math::Result<Value> convert(const Value value) noexcept {
		return static_cast<xieite::math::Result<Value>>(value) * Source::num * Target::den / Source::den / Target::num;
	}
}

#endif
