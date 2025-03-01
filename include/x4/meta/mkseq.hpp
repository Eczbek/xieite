#pragma once

#include <utility>
#include "../meta/seq.hpp"

namespace x4 {
	template<auto n>
	constexpr decltype(([]<typename T, T... i>(std::integer_sequence<T, i...>) static {
		return x4::seq<i...>();
	})(std::make_integer_sequence<decltype(n), n>())) mkseq;
}
