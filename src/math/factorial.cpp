export module xieite:math.factorial;

import std;
import :concepts.Arithmetic;
import :containers.makeArray;
import :math.multiplicationOverflows;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	constexpr auto factorial = ([] {
		static constexpr auto get = [] {
			std::vector<Arithmetic> result = { 1 };
			for (Arithmetic i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
				result.push_back(i * result[i - 1]);
			}
			return result;
		};
		return xieite::containers::makeArray<Arithmetic, get().size()>(get());
	})();
}
