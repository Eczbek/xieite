#include <xte/math/wide_uint.hpp>
#include <xte/util/types.hpp>

using namespace xte::literal::wide_uint;

static_assert(xte::wide_uint<xte::u8>(256).hi == 1);

static_assert(static_cast<unsigned>(xte::wide_uint<xte::u32>(1'0)) == 10u);

static_assert(static_cast<unsigned>(xte::wide_uint<xte::u32>(0) | 1) == 1u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u32>(0) | 2) == 2u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u32>(0) | 999) == 999u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u32>(16) | 8) == 24u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u32>(-1) | 783465982745) == -1u);

static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1)) == 1u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(2)) == 2u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(4)) == 4u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(8)) == 8u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(16)) == 16u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(32)) == 32u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(64)) == 64u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(128)) == 128u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(256)) == 256u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(512)) == 512u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1024)) == 1024u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(2048)) == 2048u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(4096)) == 4096u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(8192)) == 8192u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(16384)) == 16384u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(32768)) == 32768u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65536l)) == 0u);

static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 0) == 1u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 1) == 2u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 2) == 4u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 3) == 8u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 4) == 16u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 5) == 32u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 6) == 64u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 7) == 128u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 8) == 256u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 9) == 512u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 10) == 1024u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 11) == 2048u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 12) == 4096u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 13) == 8192u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 14) == 16384u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 15) == 32768u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(1) << 16) == 0u);

static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 0) == 65535u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 1) == 32767u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 2) == 16383u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 3) == 8191u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 4) == 4095u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 5) == 2047u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 6) == 1023u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 7) == 511u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 8) == 255u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 9) == 127u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 10) == 63u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 11) == 31u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 12) == 15u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 13) == 7u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 14) == 3u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 15) == 1u);
static_assert(static_cast<unsigned>(xte::wide_uint<xte::u8>(65535) >> 16) == 0u);

static_assert(DETAIL_XTE::wide_uint::width<xte::u8> == 8);
static_assert(static_cast<xte::u8>(65535) == 255);
static_assert(static_cast<xte::u8>(DETAIL_XTE::wide_uint::rshift(65535, DETAIL_XTE::wide_uint::width<xte::u8>)) == 255);

static_assert(999'999'999'999'999'999_w128 == xte::wide_uint<xte::u64>(999'999'999'999'999'999ull));
static_assert(999'999'999'999'999'999_w128 * 999'999'999'999'999'999_w128 == 999999999999999998000000000000000001_w128);
