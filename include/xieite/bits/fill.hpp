#ifndef XIEITE_HEADER_BITS_FILL
#	define XIEITE_HEADER_BITS_FILL

#	include <array>
#	include <bit>
#	include <concepts>
#	include <cstddef>

namespace xieite::bits {
	struct Fill {
		std::byte value;

		template<std::integral Integral_>
		constexpr Fill(const Integral_ value) noexcept
		: value(static_cast<std::byte>(value)) {}

		template<typename Type_>
		[[nodiscard]] /* implicit */ constexpr operator Type_() const noexcept {
			std::array<std::byte, sizeof(Type_)> bytes;
			for (std::size_t i = 0; i < sizeof(Type_); ++i) {
				bytes[i] = this->value;
			}
			return std::bit_cast<Type_>(bytes);
		}
	};
}

#endif
