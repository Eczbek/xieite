export module xieite:math.tau;

import :concepts.Arithmetic;
import :math.pi;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	inline constexpr Arithmetic tau = xieite::math::pi<Arithmetic> * 2;
}

// TODO: remove `inline` once wreien fixes related bug next week
