#include "../test.hpp"

import std;
import xieite;

constexpr std::array tests = {
	TEST(requires { xieite::rotate_swap<0>(); }),
	TEST(requires { xieite::rotate_swap<1>(); }),
	TEST(requires { xieite::rotate_swap<2>(); }),
	TEST(requires { xieite::rotate_swap<3>(); }),
	TEST(([] -> bool { int a = 1; int b = 2; int c = 3; xieite::rotate_swap<0>(a, b, c); return (a == 1) && (b == 2) && (c == 3); })()),
	TEST(([] -> bool { int a = 1; int b = 2; int c = 3; xieite::rotate_swap<1>(a, b, c); return (a == 2) && (b == 3) && (c == 1); })()),
	TEST(([] -> bool { int a = 1; int b = 2; int c = 3; xieite::rotate_swap<2>(a, b, c); return (a == 3) && (b == 1) && (c == 2); })()),
	TEST(([] -> bool { int a = 1; int b = 2; int c = 3; xieite::rotate_swap<3>(a, b, c); return (a == 1) && (b == 2) && (c == 3); })())
};

int main() {
	for (auto test : tests) {
		std::print("{}\n", test);
	}
}
