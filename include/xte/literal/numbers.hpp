#ifndef DETAIL_XTE_HEADER_LITERAL_NUMBERS
#	define DETAIL_XTE_HEADER_LITERAL_NUMBERS
#
#	include "../data/fixed_array.hpp"
#	include "../data/string_view.hpp"
#	include "../data/uppercase.hpp"
#	include "../literal/radix.hpp"
#	include "../preproc/feature.hpp"
#	include "../util/numbers.hpp"
#	include <ranges>

namespace xte::literal::numbers {
	[[nodiscard]] consteval auto operator""_u(unsigned long long x) noexcept {
		return static_cast<unsigned int>(x);
	}

	[[nodiscard]] consteval auto operator""_i(unsigned long long x) noexcept {
		return static_cast<int>(x);
	}

	[[nodiscard]] consteval auto operator""_ul(unsigned long long x) noexcept {
		return static_cast<unsigned long>(x);
	}

	[[nodiscard]] consteval auto operator""_il(unsigned long long x) noexcept {
		return static_cast<long>(x);
	}

	[[nodiscard]] consteval auto operator""_ull(unsigned long long x) noexcept {
		return static_cast<unsigned long long>(x);
	}

	[[nodiscard]] consteval auto operator""_ill(unsigned long long x) noexcept {
		return static_cast<long long>(x);
	}

	[[nodiscard]] consteval auto operator""_us(unsigned long long x) noexcept {
		return static_cast<unsigned short>(x);
	}

	[[nodiscard]] consteval auto operator""_is(unsigned long long x) noexcept {
		return static_cast<short>(x);
	}

#	if XTE_FEATURE_INT_PTR
	[[nodiscard]] constexpr auto operator""_uptr(unsigned long long x) noexcept {
		return static_cast<xte::uptr>(x);
	}

	[[nodiscard]] constexpr auto operator""_iptr(unsigned long long x) noexcept {
		return static_cast<xte::iptr>(x);
	}
#	endif

	[[nodiscard]] constexpr auto operator""_uptrdiff(unsigned long long x) noexcept {
		return static_cast<xte::uptrdiff>(x);
	}

	[[nodiscard]] constexpr auto operator""_iptrdiff(unsigned long long x) noexcept {
		return static_cast<xte::iptrdiff>(x);
	}

	[[nodiscard]] constexpr auto operator""_umax(unsigned long long x) noexcept {
		return static_cast<xte::umax>(x);
	}

	[[nodiscard]] constexpr auto operator""_imax(unsigned long long x) noexcept {
		return static_cast<xte::imax>(x);
	}

	[[nodiscard]] consteval bool operator""_b(unsigned long long x) noexcept {
		return x;
	}

	[[nodiscard]] consteval auto operator""_c(unsigned long long x) noexcept {
		return static_cast<char>(x);
	}

	[[nodiscard]] consteval auto operator""_uc(unsigned long long x) noexcept {
		return static_cast<unsigned char>(x);
	}

	[[nodiscard]] consteval auto operator""_ic(long double x) noexcept {
		return static_cast<signed char>(x);
	}

	[[nodiscard]] consteval auto operator""_cw(unsigned long long x) noexcept {
		return static_cast<wchar_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c8(unsigned long long x) noexcept {
		return static_cast<char8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c16(unsigned long long x) noexcept {
		return static_cast<char16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c32(unsigned long long x) noexcept {
		return static_cast<char32_t>(x);
	}

#	if XTE_FEATURE_INT_8
	[[nodiscard]] constexpr xte::u8 operator""_u8(unsigned long long x) noexcept {
		return static_cast<xte::u8>(x);
	}

	[[nodiscard]] constexpr xte::i8 operator""_i8(unsigned long long x) noexcept {
		return static_cast<xte::i8>(x);
	}
#	endif
#	if XTE_FEATURE_INT_16
	[[nodiscard]] constexpr xte::u16 operator""_u16(unsigned long long x) noexcept {
		return static_cast<xte::u16>(x);
	}

	[[nodiscard]] constexpr xte::i16 operator""_i16(unsigned long long x) noexcept {
		return static_cast<xte::i16>(x);
	}
#	endif
#	if XTE_FEATURE_INT_32
	[[nodiscard]] constexpr xte::u32 operator""_u32(unsigned long long x) noexcept {
		return static_cast<xte::u32>(x);
	}

	[[nodiscard]] constexpr xte::i32 operator""_i32(unsigned long long x) noexcept {
		return static_cast<xte::i32>(x);
	}
#	endif
#	if XTE_FEATURE_INT_64
	[[nodiscard]] constexpr xte::u64 operator""_u64(unsigned long long x) noexcept {
		return static_cast<xte::u64>(x);
	}

	[[nodiscard]] constexpr xte::i64 operator""_i64(unsigned long long x) noexcept {
		return static_cast<xte::i64>(x);
	}
#	endif
#	if XTE_FEATURE_INT_128
	template<char... digits>
	requires(!!sizeof...(digits))
	[[nodiscard]] consteval xte::u128 operator""_u128() noexcept {
		static constexpr xte::uz radix = xte::literal::radix::operator""_radix<digits...>();
		xte::u128 result = 0;
		for (xte::uz digit : xte::fixed_array { digits... } | std::views::drop(2 * ((radix == 16) || (radix == 2)))) {
			if (digit == '\'') {
				continue;
			}
			xte::uz index = xte::string_view("0123456789ABCDEF").slice(0, radix).find(xte::uppercase(digit));
			if (!~index) {
				break;
			}
			(result *= static_cast<xte::u128>(radix)) += static_cast<xte::u128>(index);
		}
		return result;
	}

	template<char... digits>
	requires(!!sizeof...(digits))
	[[nodiscard]] consteval xte::i128 operator""_i128() noexcept {
		return static_cast<xte::i128>(xte::literal::numbers::operator""_u128<digits...>());
	}
#	endif
}

#endif
