#include <xte/literal/numbers.hpp>
#include <xte/preproc/feature.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/numbers.hpp>

using namespace xte::literal::numbers;

#if XTE_FEATURE_INT_8
static_assert(xte::is_same<decltype(0_u8), xte::u8>);
static_assert(xte::is_same<decltype(0_i8), xte::i8>);
#endif

#if XTE_FEATURE_INT_16
static_assert(xte::is_same<decltype(0_u16), xte::u16>);
static_assert(xte::is_same<decltype(0_i16), xte::i16>);
#endif

#if XTE_FEATURE_INT_32
static_assert(xte::is_same<decltype(0_u32), xte::u32>);
static_assert(xte::is_same<decltype(0_i32), xte::i32>);
#endif

#if XTE_FEATURE_INT_64
static_assert(xte::is_same<decltype(0_u64), xte::u64>);
static_assert(xte::is_same<decltype(0_i64), xte::i64>);
#endif
