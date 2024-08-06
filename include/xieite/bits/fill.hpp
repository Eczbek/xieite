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

		template<std::integral Integral_>
		constexpr Fill(const Integral_ value) noexcept
		: value(static_cast<std::byte>(value)) {}

		template<typename Type_>
		[[nodiscard]] /* implicit */ constexpr operator Type_() const noexcept {
			return std::bit_cast<Type_>(([this]<std::size_t... i_>(std::index_sequence<i_...>) {
				return std::array<std::byte, sizeof(Type_)> {
					(void(i_), this->value)...
				};
			})(std::make_index_sequence<sizeof(Type_)>()));
		}
	};
}

#endif
