#include <xieite/fwd.hpp>
#include "../test.hpp"

import std;

constexpr std::array tests = {
	TEST(requires { XIEITE_FWD_PRVALUE([] {}); }),
	TEST(std::same_as<decltype(XIEITE_FWD_PRVALUE(void())), void>)
};

int main() {
	for (auto test : tests) {
		std::print("{}\n", test);
	}
}
