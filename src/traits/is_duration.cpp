export module xieite:traits.IsDuration;

import std;
import :concepts.Arithmetic;
import :concepts.Ratio;

export namespace xieite::traits {
	template<typename>
	struct IsDuration
	: std::false_type {};

	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Ratio Ratio>
	struct IsDuration<std::chrono::duration<Arithmetic, Ratio>>
	: std::true_type {};
}
