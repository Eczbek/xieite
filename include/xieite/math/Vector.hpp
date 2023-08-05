#ifndef XIEITE_HEADER__MATH__VECTOR
#	define XIEITE_HEADER__MATH__VECTOR

#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2 = Arithmetic1, xieite::concepts::Arithmetic Arithmetic3 = Arithmetic2>
	struct Vector {
		Arithmetic1 x;
		Arithmetic2 y;
		Arithmetic3 z;

		constexpr Vector(const Arithmetic1 x = 0, const Arithmetic2 y = 0, const Arithmetic3 z = 0) noexcept
		: x(x), y(y), z(z) {}

		template<xtypename OtherArithmetic1, typename OtherArithmetic2, typename OtherArithmetic3>
		[[nodiscard]]
		constexpr bool operator==(const xieite::math::Vector<OtherArithmetic1, OtherArithmetic2, OtherArithmetic3>& vector) noexcept {
			return ((this->x == vector.x) && (this->y == vector.y) && (this->z == vector.z));
		}
	};
}

#endif
