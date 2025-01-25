#pragma once

#include <cstddef>
#include <type_traits>
#include "../meta/t.hpp"
#include "../trait/cp_ref.hpp"
#include "../trait/is_ptr.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T, std::size_t n = 1>
	using rm_ptr = xieite::cp_ref<T, typename decltype(([]<typename U = xieite::rm_ref<T>, std::size_t m = n>(this auto self) {
		if constexpr (xieite::is_ptr<U> && m) {
			return self.template operator()<std::remove_pointer_t<T>, (m - 1)>();
		} else {
			return xieite::t<U>();
		}
	})())::type>;
}
