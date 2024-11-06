export module xieite:byte_fill;

import std;
import :unroll;

export namespace xieite {
	struct byte_fill {
		unsigned char value;

		template<std::integral T>
		explicit constexpr byte_fill(T value) noexcept
		: value(static_cast<unsigned char>(value)) {}

		template<typename T>
		[[nodiscard]] constexpr operator T() const noexcept {
			return xieite::unroll<sizeof(T)>([this]<std::size_t... i> -> T {
				return std::bit_cast<T>(std::array<unsigned char, sizeof(T)> { (void(i), this->value)... });
			});
		}
	};
}
