#include "test.hpp"

import std;
import xieite;

constexpr std::array tests = {
	TEST(xieite::is_arith<bool>),
	TEST(xieite::is_arith<char>),
	TEST(xieite::is_arith<unsigned char>),
	TEST(xieite::is_arith<signed char>),
	TEST(xieite::is_arith<wchar_t>),
	TEST(xieite::is_arith<char8_t>),
	TEST(xieite::is_arith<char16_t>),
	TEST(xieite::is_arith<char32_t>),
	TEST(xieite::is_arith<short int>),
	TEST(xieite::is_arith<unsigned short int>),
	TEST(xieite::is_arith<int>),
	TEST(xieite::is_arith<unsigned int>),
	TEST(xieite::is_arith<long int>),
	TEST(xieite::is_arith<unsigned long int>),
	TEST(xieite::is_arith<long long int>),
	TEST(xieite::is_arith<unsigned long long int>),
	TEST(xieite::is_arith<std::uint8_t>),
	TEST(xieite::is_arith<std::int8_t>),
	TEST(xieite::is_arith<std::uint16_t>),
	TEST(xieite::is_arith<std::int16_t>),
	TEST(xieite::is_arith<std::uint32_t>),
	TEST(xieite::is_arith<std::int32_t>),
	TEST(xieite::is_arith<std::uint64_t>),
	TEST(xieite::is_arith<std::int64_t>),
	TEST(xieite::is_arith<float>),
	TEST(xieite::is_arith<double>),
	TEST(xieite::is_arith<long double>),
	TEST(xieite::is_arith<std::float16_t>),
	TEST(xieite::is_arith<std::float32_t>),
	TEST(xieite::is_arith<std::float64_t>),
	TEST(xieite::is_arith<std::float128_t>),
	TEST(xieite::is_arith<std::bfloat16_t>),

	// Other random types
	TEST(!xieite::is_arith<void>),
	TEST(!xieite::is_arith<int&>),
	TEST(!xieite::is_arith<char***>),
	TEST(!xieite::is_arith<decltype([] {})>),
	TEST(!xieite::is_arith<std::nullptr_t>)
};

int main() {
	for (auto test : tests) {
		std::print("{}\n", test);
	}
}
