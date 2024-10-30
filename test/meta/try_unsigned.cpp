#include "../test.hpp"

import std;
import xieite;

constexpr std::array tests = {
	TEST(std::same_as<xieite::try_unsigned<bool>, bool>),
	TEST(std::same_as<xieite::try_unsigned<char>, unsigned char>),
	TEST(std::same_as<xieite::try_unsigned<unsigned char>, unsigned char>),
	TEST(std::same_as<xieite::try_unsigned<signed char>, unsigned char>),
	TEST(std::same_as<xieite::try_unsigned<wchar_t>, wchar_t>),
	TEST(std::same_as<xieite::try_unsigned<char8_t>, char8_t>),
	TEST(std::same_as<xieite::try_unsigned<char16_t>, char16_t>),
	TEST(std::same_as<xieite::try_unsigned<char32_t>, char32_t>),
	TEST(std::same_as<xieite::try_unsigned<short int>, unsigned short int>),
	TEST(std::same_as<xieite::try_unsigned<unsigned short int>, unsigned short int>),
	TEST(std::same_as<xieite::try_unsigned<int>, unsigned int>),
	TEST(std::same_as<xieite::try_unsigned<unsigned int>, unsigned int>),
	TEST(std::same_as<xieite::try_unsigned<long int>, unsigned long int>),
	TEST(std::same_as<xieite::try_unsigned<unsigned long int>, unsigned long int>),
	TEST(std::same_as<xieite::try_unsigned<long long int>, unsigned long long int>),
	TEST(std::same_as<xieite::try_unsigned<unsigned long long int>, unsigned long long int>),
	TEST(std::same_as<xieite::try_unsigned<std::uint8_t>, std::uint8_t>),
	TEST(std::same_as<xieite::try_unsigned<std::int8_t>, std::uint8_t>),
	TEST(std::same_as<xieite::try_unsigned<std::uint16_t>, std::uint16_t>),
	TEST(std::same_as<xieite::try_unsigned<std::int16_t>, std::uint16_t>),
	TEST(std::same_as<xieite::try_unsigned<std::uint32_t>, std::uint32_t>),
	TEST(std::same_as<xieite::try_unsigned<std::int32_t>, std::uint32_t>),
	TEST(std::same_as<xieite::try_unsigned<std::uint64_t>, std::uint64_t>),
	TEST(std::same_as<xieite::try_unsigned<std::int64_t>, std::uint64_t>),
	TEST(std::same_as<xieite::try_unsigned<float>, float>),
	TEST(std::same_as<xieite::try_unsigned<double>, double>),
	TEST(std::same_as<xieite::try_unsigned<long double>, long double>),
	TEST(std::same_as<xieite::try_unsigned<std::float16_t>, std::float16_t>),
	TEST(std::same_as<xieite::try_unsigned<std::float32_t>, std::float32_t>),
	TEST(std::same_as<xieite::try_unsigned<std::float64_t>, std::float64_t>),
	TEST(std::same_as<xieite::try_unsigned<std::float128_t>, std::float128_t>),
	TEST(std::same_as<xieite::try_unsigned<std::bfloat16_t>, std::bfloat16_t>),

	// Other random types
	TEST(std::same_as<xieite::try_unsigned<void>, void>),
	TEST(std::same_as<xieite::try_unsigned<int&>, int&>),
	TEST(std::same_as<xieite::try_unsigned<char***>, char***>),
	TEST(std::same_as<xieite::try_unsigned<std::nullptr_t>, std::nullptr_t>)
};

int main() {
	for (auto test : tests) {
		std::print("{}\n", test);
	}
}
