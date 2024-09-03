export module xieite:math.minimum;

import std;
import :concepts.Arithmetic;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic... Arithmetics>
	requires(sizeof...(Arithmetics) > 0)
	[[nodiscard]] constexpr std::common_type_t<Arithmetics...> minimum(const Arithmetics... values) noexcept {
		return std::ranges::min(std::array<std::common_type_t<Arithmetics...>, sizeof...(Arithmetics)> {
			static_cast<std::common_type_t<Arithmetics...>>(values)...
		});
	}
}
