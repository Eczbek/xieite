#pragma once

#include <cstddef>
#include <type_traits>
#include "../meta/any.hpp"
#include "../meta/tupsz.hpp"
#include "../pp/diag.hpp"
#include "../trait/istuplike.hpp"

X4DIAGPUSH_CLANG()
X4DIAGOFF_CLANG("-Wunused-lambda-capture")

namespace x4 {
	template<typename T>
	constexpr std::size_t arity = ([] static -> std::size_t {
		if constexpr (x4::istuplike<T>) {
			return x4::tupsz<T>;
		} else if constexpr (using U = std::remove_cvref_t<T>; std::is_aggregate_v<U>) {
			return ([](this auto self, std::size_t offset = 0, auto... curr) /* -> std::size_t */ {
				if constexpr (requires { U { curr..., x4::any() }; } || requires { U { curr..., { x4::any(), x4::any() } }; }) {
					([&offset, curr...](this auto self, auto... pre) -> void {
						if constexpr (requires { U { curr..., pre..., x4::any() }; }) {
							self(pre..., x4::any());
						} else {
							([&offset, curr..., pre...](this auto self, auto... post) -> void {
								if constexpr (requires { U { curr..., { x4::any(), x4::any() }, post..., x4::any() }; }) {
									self(post..., x4::any());
								} else if constexpr (sizeof...(pre) != (sizeof...(post) + 1)) {
									([&offset, curr...](this auto self, auto... inner) -> void {
										if constexpr (requires { U { curr..., { inner..., x4::any() } }; }) {
											self(inner..., x4::any());
										} else {
											offset += sizeof...(inner) - 1;
										}
									})();
								}
							})();
						}
					})();
					return self(offset, curr..., x4::any());
				} else {
					return sizeof...(curr) - offset;
				}
			})();
		} else {
			static_assert(false, "must not take arity of non-tuple-like nor aggregate type");
		}
	})();
}

X4DIAGPOP_CLANG()
