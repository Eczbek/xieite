export module xieite:math.factorial;

import std;
import :concepts.Arithmetic;
import :containers.makeArray;
import :math.multiplicationOverflows;

template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr std::vector<Arithmetic> get() noexcept {
	std::vector<Arithmetic> result = { 1 };
	for (Arithmetic i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
		result.push_back(i * result[i - 1]);
	}
	return result;
}

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	inline constexpr auto factorial = xieite::containers::makeArray<Arithmetic, get<Arithmetic>().size()>(get<Arithmetic>());
}

// TODO: remove `inline` once wreien fixes related bug next week
