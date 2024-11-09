#include "../test.hpp"

import std;
import xieite;

constexpr std::array tests = {
	TEST(std::same_as<xieite::try_unsign<bool>, bool>),
	TEST(std::same_as<xieite::try_unsign<char>, unsigned char>),
	TEST(std::same_as<xieite::try_unsign<unsigned char>, unsigned char>),
	TEST(std::same_as<xieite::try_unsign<signed char>, unsigned char>),
	TEST(std::same_as<xieite::try_unsign<wchar_t>, wchar_t>),
	TEST(std::same_as<xieite::try_unsign<char8_t>, char8_t>),
	TEST(std::same_as<xieite::try_unsign<char16_t>, char16_t>),
	TEST(std::same_as<xieite::try_unsign<char32_t>, char32_t>),
	TEST(std::same_as<xieite::try_unsign<short int>, unsigned short int>),
	TEST(std::same_as<xieite::try_unsign<unsigned short int>, unsigned short int>),
	TEST(std::same_as<xieite::try_unsign<int>, unsigned int>),
	TEST(std::same_as<xieite::try_unsign<unsigned int>, unsigned int>),
	TEST(std::same_as<xieite::try_unsign<long int>, unsigned long int>),
	TEST(std::same_as<xieite::try_unsign<unsigned long int>, unsigned long int>),
	TEST(std::same_as<xieite::try_unsign<long long int>, unsigned long long int>),
	TEST(std::same_as<xieite::try_unsign<unsigned long long int>, unsigned long long int>),
	TEST(std::same_as<xieite::try_unsign<std::uint8_t>, std::uint8_t>),
	TEST(std::same_as<xieite::try_unsign<std::int8_t>, std::uint8_t>),
	TEST(std::same_as<xieite::try_unsign<std::uint16_t>, std::uint16_t>),
	TEST(std::same_as<xieite::try_unsign<std::int16_t>, std::uint16_t>),
	TEST(std::same_as<xieite::try_unsign<std::uint32_t>, std::uint32_t>),
	TEST(std::same_as<xieite::try_unsign<std::int32_t>, std::uint32_t>),
	TEST(std::same_as<xieite::try_unsign<std::uint64_t>, std::uint64_t>),
	TEST(std::same_as<xieite::try_unsign<std::int64_t>, std::uint64_t>),
	TEST(std::same_as<xieite::try_unsign<float>, float>),
	TEST(std::same_as<xieite::try_unsign<double>, double>),
	TEST(std::same_as<xieite::try_unsign<long double>, long double>),
	TEST(std::same_as<xieite::try_unsign<std::float16_t>, std::float16_t>),
	TEST(std::same_as<xieite::try_unsign<std::float32_t>, std::float32_t>),
	TEST(std::same_as<xieite::try_unsign<std::float64_t>, std::float64_t>),
	TEST(std::same_as<xieite::try_unsign<std::float128_t>, std::float128_t>),
	TEST(std::same_as<xieite::try_unsign<std::bfloat16_t>, std::bfloat16_t>),

	// Other random types
	TEST(std::same_as<xieite::try_unsign<void>, void>),
	TEST(std::same_as<xieite::try_unsign<int&>, int&>),
	TEST(std::same_as<xieite::try_unsign<char***>, char***>),
	TEST(std::same_as<xieite::try_unsign<std::nullptr_t>, std::nullptr_t>)
};

int main() {
	for (auto test : tests) {
		std::print("{}\n", test);
	}
}
