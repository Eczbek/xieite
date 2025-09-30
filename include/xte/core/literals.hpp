#ifndef DETAIL_XTE_HEADER_CORE_LITERALS
#	define DETAIL_XTE_HEADER_CORE_LITERALS
#
#	include "../core/types.hpp"
#	include "../preproc/feature.hpp"
#
#	if XTE_FEATURE_INT_8

namespace xte::literals {
	[[nodiscard]] constexpr xte::u8 operator""_u8(unsigned long long x) noexcept {
		return static_cast<xte::u8>(x);
	}

	[[nodiscard]] constexpr xte::i8 operator""_i8(unsigned long long x) noexcept {
		return static_cast<xte::i8>(x);
	}
}

#endif
#
#	if XTE_FEATURE_INT_16

namespace xte::literals {
	[[nodiscard]] constexpr xte::u16 operator""_u16(unsigned long long x) noexcept {
		return static_cast<xte::u16>(x);
	}

	[[nodiscard]] constexpr xte::i16 operator""_i16(unsigned long long x) noexcept {
		return static_cast<xte::i16>(x);
	}
}

#	endif
#
#	if XTE_FEATURE_INT_32

namespace xte::literals {
	[[nodiscard]] constexpr xte::u32 operator""_u32(unsigned long long x) noexcept {
		return static_cast<xte::u32>(x);
	}

	[[nodiscard]] constexpr xte::i32 operator""_i32(unsigned long long x) noexcept {
		return static_cast<xte::i32>(x);
	}
}

#	endif
#
#	if XTE_FEATURE_INT_64

namespace xte::literals {
	[[nodiscard]] constexpr xte::u64 operator""_u64(unsigned long long x) noexcept {
		return static_cast<xte::u64>(x);
	}

	[[nodiscard]] constexpr xte::i64 operator""_i64(unsigned long long x) noexcept {
		return static_cast<xte::i64>(x);
	}
}

#	endif
#endif
