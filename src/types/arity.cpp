export module xieite:types.arity;

import std;
import :concepts.Aggregate;

export namespace xieite::types {
	template<xieite::concepts::Aggregate Type>
	constexpr std::size_t arity = ([](this const auto self, std::size_t offset = 0, const auto... current) {
		if constexpr (requires { Type { current..., Any() }; } || requires { Type { current..., { Any(), Any() } }; }) {
			([&offset, current...](this const auto self, const auto... pre) {
				if constexpr (requires { Type { current..., pre..., Any() }; }) {
					self(pre..., Any());
				} else {
					([&offset, current..., pre...](this const auto self, const auto... post) {
						if constexpr (requires { Type { current..., { Any(), Any() }, post..., Any() }; }) {
							self(post..., Any());
						} else if constexpr (sizeof...(pre) != (sizeof...(post) + 1)) {
							([&offset, current...](this const auto self, const auto... inner) {
								if constexpr (requires { Type { current..., { inner..., Any() } }; }) {
									self(inner..., Any());
								} else {
									offset += sizeof...(inner) - 1;
								}
							})();
						}
					})();
				}
			})();
			return self(offset, current..., Any());
		} else {
			return sizeof...(current) - offset;
		}
	})();
}

// Stolen from lapinozz (https://github.com/lapinozz)
