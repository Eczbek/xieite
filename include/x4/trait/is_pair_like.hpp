#pragma once

#include "../meta/arity.hpp"
#include "../trait/istuple_like.hpp"

namespace x4 {
	template<typename T>
	concept ispairlike = x4::istuple_like<T> && (x4::arity<T> == 2);
}
