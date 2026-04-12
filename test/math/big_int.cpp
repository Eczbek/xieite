#include <xte/data/array.hpp>
#include <xte/math/big_int.hpp>
#include <xte/math/width.hpp>
#include <xte/preproc/feature.hpp>
#include <xte/util/types.hpp>
#include <ranges>

static_assert(xte::big_int() == 0);
static_assert(xte::big_int(0) == 0);
static_assert(xte::big_int(123) == 123);
#if XTE_FEATURE_INT_8
static_assert(xte::big_int<xte::u8>(257) == 257);
#endif
static_assert(xte::big_int<unsigned char>(xte::big_int<unsigned long long>(123456789)) == 123456789);
static_assert(xte::big_int<unsigned long long>(xte::big_int<unsigned char>(123456789)) == 123456789);
static_assert((sizeof(int) == sizeof(long long)) || (xte::big_int<unsigned>(std::from_range, { 0u, 1u }) == (-1u + 1ull)));
static_assert(xte::big_int("") == 0);
static_assert(xte::big_int("0") == 0);
static_assert(xte::big_int("123") == 123);
static_assert(xte::big_int("FF", 16) == 255);
static_assert(static_cast<unsigned>(xte::big_int(123)) == 123);
static_assert(static_cast<unsigned>(xte::big_int("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 16)) == -1u);
static_assert(!xte::big_int(0));
static_assert(!!xte::big_int(123));
static_assert(!(xte::big_int(0) < 0));
static_assert(xte::big_int(123) == 123);
static_assert(xte::big_int("FFFFFFFFFFFFFFFFFFF", 16) > xte::big_int("FFFF", 16));
static_assert(xte::big_int(123) > -123);
static_assert(xte::big_int(-123) < 0);
static_assert(xte::big_int(1) != 0);
static_assert(+xte::big_int(123) == 123);
static_assert((xte::big_int(0) + 0) == 0);
static_assert((xte::big_int(0) + 123) == 123);
static_assert((sizeof(char) == sizeof(long long)) || (xte::big_int<unsigned char>(static_cast<unsigned char>(-1)) + 1) == (static_cast<unsigned char>(-1) + 1ull));
static_assert((xte::big_int(-123) + -1) == -124);
static_assert((xte::big_int(1 + -2)) == -1);
static_assert((xte::big_int(-1 - -2)) == 1);
static_assert(-xte::big_int(0) == 0);
static_assert(-xte::big_int(123) == -123);
static_assert((xte::big_int(123) - 123) == 0);
static_assert((xte::big_int(1) - 123) == -122);
static_assert((xte::big_int(-5) + 4) == -1);
static_assert((xte::big_int(0) * 0) == 0);
static_assert((xte::big_int(123) * 0) == 0);
static_assert((xte::big_int(0) * 123) == 0);
static_assert((xte::big_int(2) * 2) == 4);
static_assert((xte::big_int<unsigned char>(999999999ull) * 999999999ull) == 999999998000000001ull);
static_assert((xte::big_int(360) / 2) == 180);
static_assert((xte::big_int(360) / 3) == 120);
static_assert((xte::big_int(360) / 5) == 72);
static_assert((xte::big_int(360) / 15) == 24);
static_assert((xte::big_int(12345) / -1) == -12345);
static_assert((xte::big_int(1575) / 10) == 157);
static_assert((xte::big_int<unsigned char>(999999999ull) / 13) == 76923076ull);
static_assert((xte::big_int(12345) % 2) == 1);
static_assert((xte::big_int(12345) % 3) == 0);
static_assert((xte::big_int(12345) % 17) == 3);
static_assert((xte::big_int(12345) % -62) == 7);
static_assert((xte::big_int(-12345) % -904) == -593);
static_assert((xte::big_int<unsigned char>(999999999ull) % 6217) == 1766);
static_assert(~xte::big_int(345) == -346);
static_assert(~xte::big_int(1) == -2);
static_assert(~xte::big_int(-1) == 0);
static_assert((xte::big_int(1957) & 9274) == 1056);
static_assert((xte::big_int(9602) | 7247) == 15823);
static_assert((xte::big_int(19634) ^ 27592) == 10106);
static_assert((xte::big_int(1) << 0) == 1);
static_assert((xte::big_int(1) << 1) == 2);
static_assert((xte::big_int(1) << 2) == 4);
static_assert((xte::big_int<unsigned>(1) << xte::width<unsigned>) == xte::big_int<unsigned>(std::from_range, { 0u, 1u }));
static_assert((xte::big_int(1) >> -1) == 2);
static_assert((xte::big_int(256) >> 0) == 256);
static_assert((xte::big_int(256) >> 1) == 128);
static_assert((xte::big_int(256) >> 2) == 64);
static_assert((xte::big_int<unsigned>(std::from_range, { 0u, 1u }) >> xte::width<unsigned>) == 1);
static_assert((xte::big_int(256) << -1) == 128);
static_assert(xte::big_int(0).abs() == 0);
static_assert(xte::big_int(123).abs() == 123);
static_assert(xte::big_int(-123).abs() == 123);
static_assert(xte::big_int(2).pow(0) == 1);
static_assert(xte::big_int(2).pow(1) == 2);
static_assert(xte::big_int(2).pow(2) == 4);
static_assert(xte::big_int(2).pow(64) == (xte::big_int(1) << 64));
static_assert(xte::big_int(2).pow(128) == (xte::big_int(1) << 128));
static_assert(xte::big_int(123).pow(20) == xte::big_int("628206215175202159781085149496179361969201"));
static_assert(xte::big_int(99).pow(99) == xte::big_int(std::from_range, { 11052210921748023483ull, 5342752518335406880ull, 18273117834117442446ull, 16806157478442079400ull, 5211608751722454046ull, 8940752602480459803ull, 4625783107637031297ull, 14385845698021359473ull, 2377983349987779313ull, 12684730458741789166ull, 81037ull }));
static_assert(xte::big_int(256).root(2) == 16);
static_assert(xte::big_int(256).root(4) == 4);
static_assert(xte::big_int(256).log(2) == 8);
static_assert(xte::big_int(256).log(2) == 8);
static_assert(xte::big_int(256).log(4) == 4);
static_assert(xte::big_int(12345).str() == "12345");
static_assert(xte::big_int(-12345).str() == "-12345");

using namespace xte::literal::big_int;
static_assert(255_big == 255);
static_assert(0xFF_big == 255);
static_assert(0XFF_big == 255);
static_assert(0b11111111_big == 255);
static_assert(0B11111111_big == 255);
