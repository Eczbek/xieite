export module xieite:arity;

import std;
import :any;

export namespace xieite {
	template<typename T>
	constexpr std::size_t arity = ([] {
		if constexpr (requires { std::tuple_size<T>::value; }) {
			return std::tuple_size_v<T>;
		} else if constexpr (std::is_aggregate_v<T>) {
			return ([](this auto self, std::size_t offset = 0, auto... curr) {
				if constexpr (requires { T { curr..., xieite::any() }; } || requires { T { curr..., { xieite::any(), xieite::any() } }; }) {
					([&offset, curr...](this auto self, auto... pre) {
						if constexpr (requires { T { curr..., pre..., xieite::any() }; }) {
							self(pre..., xieite::any());
						} else {
							([&offset, curr..., pre...](this auto self, auto... post) {
								if constexpr (requires { T { curr..., { xieite::any(), xieite::any() }, post..., xieite::any() }; }) {
									self(post..., xieite::any());
								} else if constexpr (sizeof...(pre) != (sizeof...(post) + 1)) {
									([&offset, curr...](this auto self, auto... inner) {
										if constexpr (requires { T { curr..., { inner..., xieite::any() } }; }) {
											self(inner..., xieite::any());
										} else {
											offset += sizeof...(inner) - 1;
										}
									})();
								}
							})();
						}
					})();
					return self(offset, curr..., xieite::any());
				} else {
					return sizeof...(curr) - offset;
				}
			})();
		} else {
			static_assert(false, "must not take arity of non-tuple-like nor aggregate type");
		}
	})();
}

// Stolen from lapinozz (https://github.com/lapinozz)
