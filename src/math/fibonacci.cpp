export module xieite:math.fibonacci;

import std;
import :concepts.Arithmetic;
import :containers.makeArray;
import :math.additionOverflows;

template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr std::vector<Arithmetic> get() noexcept {
	std::vector<Arithmetic> result = { 0, 1 };
	for (std::size_t i = 2; !xieite::math::additionOverflows(result[i - 1], result[i - 2]); ++i) {
		result.push_back(result[i - 1] + result[i - 2]);
	}
	return result;
}

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	inline constexpr auto fibonacci = xieite::containers::makeArray<Arithmetic, get<Arithmetic>().size()>(get<Arithmetic>());
}

// TODO: remove `inline` once wreien fixes related bug next week
