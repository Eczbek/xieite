export module xieite:ext_bit_cast;

import std;
import :unroll;

export namespace xieite {
	template<typename T, typename U>
	[[nodiscard]] constexpr T ext_bit_cast(const U& value) noexcept {
		return xieite::unroll<std::min(sizeof(T), sizeof(U))>([&value]<std::size_t... i> {
			const auto bits = std::bit_cast<std::array<char, sizeof(U)>>(value);
			return std::bit_cast<T>(std::array<char, sizeof(T)> { bits[i]... });
		});
	}
}
