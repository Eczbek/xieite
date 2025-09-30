#ifndef DETAIL_XTE_HEADER_CORE_TYPES
#	define DETAIL_XTE_HEADER_CORE_TYPES
#
#	include "../preproc/feature.hpp"
#	include <cstdint>

namespace xte {
	using uz = decltype(0uz);
	using iz = decltype(0z);
}

#	if XTE_FEATURE_INT_8

namespace xte {
	using u8 = ::std::uint8_t;
	using i8 = ::std::int8_t;
}

#	endif
#
#	if XTE_FEATURE_INT_16

namespace xte {
	using u16 = ::std::uint16_t;
	using i16 = ::std::int16_t;
}

#	endif
#
#	if XTE_FEATURE_INT_32

namespace xte {
	using u32 = ::std::uint32_t;
	using i32 = ::std::int32_t;
}

#	endif
#
#	if XTE_FEATURE_INT_64

namespace xte {
	using u64 = ::std::uint64_t;
	using i64 = ::std::int64_t;
}

#	endif
#
#	if XTE_FEATURE_INT_128

namespace xte {
	__extension__ using u128 = unsigned __int128;
	__extension__ using i128 = __int128;
}

#	endif
#
#	if XTE_FEATURE_FLOAT_16

namespace xte {
	using f16 = decltype(0.0f16);
}

#	endif
#
#	if XTE_FEATURE_FLOAT_32

namespace xte {
	using f32 = decltype(0.0f32);
}

#	endif
#
#	if XTE_FEATURE_FLOAT_64

namespace xte {
	using f64 = decltype(0.0f64);
}

#	endif
#
#	if XTE_FEATURE_FLOAT_128

namespace xte {
	using f128 = decltype(0.0f128);
}

#	endif
#
#	if XTE_FEATURE_BFLOAT_16

namespace xte {
	using bf16 = decltype(0.0bf16);
}

#	endif
#endif
