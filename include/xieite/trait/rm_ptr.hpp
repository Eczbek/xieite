#pragma once

#include <cstddef>
#include <type_traits>
#include "../fn/unroll.hpp"
#include "../meta/fold.hpp"

namespace xieite {
	template<typename T, std::size_t n = 1>
	using rm_ptr = decltype(([] static {
		if constexpr (n == -1uz) {
			return ([]<typename U = std::remove_reference_t<T>>(this auto self) {
				if constexpr (std::is_pointer_v<U>) {
					return self.template operator()<std::remove_pointer_t<U>>();
				} else {
					return std::type_identity<U>();
				}
			})();
		} else {
			return xieite::unroll<n>([]<std::size_t... i> static {
				return xieite::fold<
					[]<typename U, typename> static {
						return std::remove_pointer<typename U::type>();
					},
					std::remove_reference<T>,
					decltype(i)...
				>();
			});
		}
	})())::type;
}
