#pragma once

#include <chrono>
#include "../meta/t.hpp"
#include "../trait/is_arith.hpp"
#include "../trait/is_ratio.hpp"
#include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_dur = requires { ([]<xieite::is_arith U, xieite::is_ratio V>(xieite::t<std::chrono::duration<U, V>>) {})(xieite::t<xieite::rm_cv<T>>()); };
}
