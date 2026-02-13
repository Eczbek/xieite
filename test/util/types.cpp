#include <xte/preproc/feature.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/types.hpp>
#include <cstddef>
#include <cstdint>
#include <stdfloat>
#include <type_traits>

static_assert(xte::is_same<xte::uz, std::size_t>);
static_assert(xte::is_same<xte::iz, std::make_signed_t<std::size_t>>);

#if XTE_FEATURE_INT_8
static_assert(xte::is_same<xte::u8, std::uint8_t>);
static_assert(xte::is_same<xte::i8, std::int8_t>);
#endif

#if XTE_FEATURE_INT_16
static_assert(xte::is_same<xte::u16, std::uint16_t>);
static_assert(xte::is_same<xte::i16, std::int16_t>);
#endif

#if XTE_FEATURE_INT_32
static_assert(xte::is_same<xte::u32, std::uint32_t>);
static_assert(xte::is_same<xte::i32, std::int32_t>);
#endif

#if XTE_FEATURE_INT_64
static_assert(xte::is_same<xte::u64, std::uint64_t>);
static_assert(xte::is_same<xte::i64, std::int64_t>);
#endif

#if XTE_FEATURE_INT_128
__extension__ static_assert(xte::is_same<xte::u128, unsigned __int128>);
__extension__ static_assert(xte::is_same<xte::i128, __int128>);
#endif

#if XTE_FEATURE_FLOAT_16
static_assert(xte::is_same<xte::f16, std::float16_t>);
#endif

#if XTE_FEATURE_FLOAT_32
static_assert(xte::is_same<xte::f32, std::float32_t>);
#endif

#if XTE_FEATURE_FLOAT_64
static_assert(xte::is_same<xte::f64, std::float64_t>);
#endif

#if XTE_FEATURE_FLOAT_128
static_assert(xte::is_same<xte::f128, std::float128_t>);
#endif

#if XTE_FEATURE_BFLOAT_16
static_assert(xte::is_same<xte::bf16, std::bfloat16_t>);
#endif
