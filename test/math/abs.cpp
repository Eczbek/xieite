#include "../test.hpp"

import std;
import xieite;

constexpr std::array tests = {
	TEST(xieite::abs(0) == 0),
	TEST(xieite::abs(1) == 1),
	TEST(xieite::abs(-1) == 1),
	TEST(xieite::abs<std::uint8_t>(128) == 128),
	TEST(xieite::abs<std::int8_t>(-128) == 128),
	TEST(xieite::abs<std::uint16_t>(32768) == 32768),
	TEST(xieite::abs<std::int16_t>(-32768) == 32768),
	TEST(xieite::abs<std::uint32_t>(2147483648) == 2147483648),
	TEST(xieite::abs<std::int32_t>(-2147483648) == 2147483648),
	TEST(xieite::abs<std::uint64_t>(9223372036854775808ull) == 9223372036854775808ull),
	TEST(xieite::abs<std::int64_t>(-9223372036854775807-1) == 9223372036854775808ull)
};

int main() {
	for (auto test : tests) {
		std::print("{}\n", test);
	}
}
