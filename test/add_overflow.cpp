#include "test.hpp"

import std;
import xieite;

constexpr std::array tests = {
	// Any single integer should never overflow
	TEST(!xieite::add_overflow(0)),
	TEST(!xieite::add_overflow(1)),
	TEST(!xieite::add_overflow(-1)),
	TEST(!xieite::add_overflow(347856982734569)),
	TEST(!xieite::add_overflow(-927356873485)),

	// Adding zero should never overflow
	TEST(!xieite::add_overflow(0, 0)),
	TEST(!xieite::add_overflow(1, 0)),
	TEST(!xieite::add_overflow(-1, 0)),
	TEST(!xieite::add_overflow(834765823745698, 0)),
	TEST(!xieite::add_overflow(-738456827844756, 0)),

	// Subtracting one from a positive integer should never overflow
	TEST(!xieite::add_overflow(1, -1)),
	TEST(!xieite::add_overflow(473865873543, -1)),

	// Adding one to a negative integer should never overflow
	TEST(!xieite::add_overflow(-1, 1)),
	TEST(!xieite::add_overflow(-8734560273489826, 1)),

	// Cases that should overflow
	TEST(xieite::add_overflow<std::uint8_t>(255, 1)),
	TEST(xieite::add_overflow<std::int8_t>(127, 1)),
	TEST(xieite::add_overflow<std::int8_t>(-128, -1)),
	TEST(xieite::add_overflow<std::uint16_t>(65535, 1)),
	TEST(xieite::add_overflow<std::int16_t>(32767, 1)),
	TEST(xieite::add_overflow<std::int16_t>(-32768, -1)),
	TEST(xieite::add_overflow<std::uint32_t>(4294967295, 1)),
	TEST(xieite::add_overflow<std::int32_t>(2147483647, 1)),
	TEST(xieite::add_overflow<std::int32_t>(-2147483648, -1)),
	TEST(xieite::add_overflow<std::uint64_t>(18446744073709551615ull, 1)),
	TEST(xieite::add_overflow<std::int64_t>(9223372036854775807, 1)),
	TEST(xieite::add_overflow<std::int64_t>(-9223372036854775807-1, -1))
};

int main() {
	for (auto test : tests) {
		std::print("{}\n", test);
	}
}
