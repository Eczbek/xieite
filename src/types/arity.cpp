export module xieite:types.arity;

import std;
import :types.Any;

export namespace xieite::types {
	template<typename Type>
	constexpr std::size_t arity = ([] {
		if constexpr (requires { std::tuple_size<Type>::value; }) {
			return std::tuple_size_v<Type>;
		} else if constexpr (std::is_aggregate_v<Type>) {
			return ([](this const auto self, std::size_t offset = 0, const auto... current) {
				if constexpr (requires { Type { current..., xieite::types::Any() }; } || requires { Type { current..., { xieite::types::Any(), xieite::types::Any() } }; }) {
					([&offset, current...](this const auto self, const auto... pre) {
						if constexpr (requires { Type { current..., pre..., xieite::types::Any() }; }) {
							self(pre..., xieite::types::Any());
						} else {
							([&offset, current..., pre...](this const auto self, const auto... post) {
								if constexpr (requires { Type { current..., { xieite::types::Any(), xieite::types::Any() }, post..., xieite::types::Any() }; }) {
									self(post..., xieite::types::Any());
								} else if constexpr (sizeof...(pre) != (sizeof...(post) + 1)) {
									([&offset, current...](this const auto self, const auto... inner) {
										if constexpr (requires { Type { current..., { inner..., xieite::types::Any() } }; }) {
											self(inner..., xieite::types::Any());
										} else {
											offset += sizeof...(inner) - 1;
										}
									})();
								}
							})();
						}
					})();
					return self(offset, current..., xieite::types::Any());
				} else {
					return sizeof...(current) - offset;
				}
			})();
		} else {
			static_cast(false, "must not take arity of non-tuple-like nor aggregate type");
		}
	})();
}

// Stolen from lapinozz (https://github.com/lapinozz)
