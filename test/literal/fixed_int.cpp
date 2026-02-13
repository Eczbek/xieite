#include <xte/literal/fixed_int.hpp>
#include <xte/preproc/feature.hpp>

using namespace xte::literal::fixed_int;

#if XTE_FEATURE_INT_8
[[maybe_unused]] constexpr auto u8 = 0_u8;
[[maybe_unused]] constexpr auto i8 = 0_i8;
#endif

#if XTE_FEATURE_INT_16
[[maybe_unused]] constexpr auto u16 = 0_u16;
[[maybe_unused]] constexpr auto i16 = 0_i16;
#endif

#if XTE_FEATURE_INT_32
[[maybe_unused]] constexpr auto u32 = 0_u32;
[[maybe_unused]] constexpr auto i32 = 0_i32;
#endif

#if XTE_FEATURE_INT_64
[[maybe_unused]] constexpr auto u64 = 0_u64;
[[maybe_unused]] constexpr auto i64 = 0_i64;
#endif
