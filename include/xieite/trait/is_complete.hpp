#pragma once

#include "../meta/t.hpp"

namespace xieite {
	template<typename T, auto = [] {}>
	concept is_complete = requires { ([]<typename U, auto = sizeof(U)>(xieite::t<U>) {})(xieite::t<T>()); };
}

// TODO: Check for correctness
