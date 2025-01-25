#pragma once

#include "../meta/arity.hpp"
#include "../trait/is_tuple_like.hpp"

namespace xieite {
	template<typename T>
	concept is_pair_like = xieite::is_tuple_like<T> && (xieite::arity<T> == 2);
}
