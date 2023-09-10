#ifndef XIEITE_HEADER__MATH__HEXADECIMAL
#	define XIEITE_HEADER__MATH__HEXADECIMAL

#	include "../math/Base.hpp"

namespace xieite::math {
	inline constexpr xieite::math::Base hexadecimal = xieite::math::Base(16, "0123456789abcdef", '-', false);
}

#endif
