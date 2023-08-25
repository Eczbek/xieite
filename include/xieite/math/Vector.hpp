#ifndef XIEITE_HEADER__MATH__VECTOR
#	define XIEITE_HEADER__MATH__VECTOR

#	include "../concepts/Numeric.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2 = Number1, xieite::concepts::Numeric Number3 = Number2>
	struct Vector {
		Number1 x;
		Number2 y;
		Number3 z;

		constexpr Vector(const Number1 x = 0, const Number2 y = 0, const Number3 z = 0) noexcept
		: x(x), y(y), z(z) {}

		template<xtypename OtherNumber1, typename OtherNumber2, typename OtherNumber3>
		constexpr bool operator==(const xieite::math::Vector<OtherNumber1, OtherNumber2, OtherNumber3>& vector) noexcept {
			return (this->x == vector.x) && (this->y == vector.y) && (this->z == vector.z);
		}
	};
}

#endif
