#pragma once

#include <utility>
#include "../meta/seq.hpp"

namespace xieite {
	template<auto n>
	constexpr decltype(([]<typename T, T... i>(std::integer_sequence<T, i...>) {
		return xieite::seq<i...>();
	})(std::make_integer_sequence<decltype(n), n>())) make_seq;
}
