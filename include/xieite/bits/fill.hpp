#ifndef XIEITE_HEADER_BITS_FILL
#	define XIEITE_HEADER_BITS_FILL

#	include <array>
#	include <bit>
#	include <concepts>
#	include <cstddef>
#	include <utility>

namespace xieite::bits {
	struct Fill {
		std::byte value;

		template<std::integral Integral>
		explicit constexpr Fill(const Integral value) noexcept
		: value(static_cast<std::byte>(value)) {}

		template<typename Type>
		[[nodiscard]] explicit(false) constexpr operator Type() const noexcept {
			return std::bit_cast<Type>(([this]<std::size_t... i>(std::index_sequence<i...>) -> std::array<std::byte, sizeof(Type)> {
				return std::array<std::byte, sizeof(Type)> {
					(void(i), this->value)...
				};
			})(std::make_index_sequence<sizeof(Type)>()));
		}
	};
}

#endif
