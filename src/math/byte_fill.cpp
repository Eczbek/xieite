export module xieite:byte_fill;

import std;
import :unroll;

export namespace xieite {
	struct byte_fill {
		std::byte value;

		template<std::integral T>
		explicit constexpr byte_fill(T value) noexcept
		: value(static_cast<std::byte>(value)) {}

		template<typename T>
		[[nodiscard]] constexpr operator T() const noexcept {
			return xieite::unroll<sizeof(T)>([this]<std::size_t... i> {
				return std::bit_cast<T>(std::array<std::byte, sizeof(T)> { (void(i), this->value)... });
			});
		}
	};
}
