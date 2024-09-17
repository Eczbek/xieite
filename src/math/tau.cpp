export module xieite:math.tau;

import :concepts.Arithmetic;
import :math.pi;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	constexpr Arithmetic tau = xieite::math::pi<Arithmetic> * 2;
}
