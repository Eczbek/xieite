#pragma once

#include <cstdint>
#include <ratio>
#include "../meta/t.hpp"
#include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_ratio = requires { ([]<std::intmax_t numer, std::intmax_t denom>(xieite::t<std::ratio<numer, denom>>) {})(xieite::t<xieite::rm_cv<T>>()); };
}
