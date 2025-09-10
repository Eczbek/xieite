#ifndef DETAIL_XIEITE_HEADER_META_ARITY
#	define DETAIL_XIEITE_HEADER_META_ARITY
#
#	include <cstddef>
#	include <type_traits>
#	include "../meta/any.hpp"
#	include "../meta/tuple_size.hpp"
#	include "../pp/diagnostic.hpp"
#	include "../trait/is_tuple_like.hpp"

XIEITE_DIAGNOSTIC_PUSH_CLANG()
XIEITE_DIAGNOSTIC_OFF_CLANG("-Wunused-but-set-variable")
XIEITE_DIAGNOSTIC_OFF_CLANG("-Wunused-lambda-capture")

namespace xieite {
	template<typename T>
	constexpr std::size_t arity = ([] static -> std::size_t {
		if constexpr (xieite::is_tuple_like<T>) {
			return xieite::tuple_size<T>;
		} else if constexpr (using U = std::remove_cvref_t<T>; std::is_aggregate_v<U>) {
			return ([offset = 0uz](this auto self0, auto... args0) -> std::size_t {
				if constexpr (requires { T { args0..., { xieite::any(), xieite::any() } }; }) {
					([&offset](this auto self1, auto... args1) -> void {
						if constexpr (requires { T { args1..., xieite::any() }; }) {
							self1(args1..., xieite::any());
						} else {
							([&offset](this auto self2, auto... args2) -> void {
								if constexpr (requires { T { args0..., { xieite::any(), xieite::any() }, args2..., xieite::any() }; }) {
									self2(args2..., xieite::any());
								} else if constexpr (sizeof...(args1) != (sizeof...(args0) + sizeof...(args2) + 1)) {
									([&offset](this auto self3, auto... args3) -> void {
										if constexpr (requires { T { args0..., { args3..., xieite::any() } }; }) {
											self3(args3..., xieite::any());
										} else {
											offset += sizeof...(args3) - 1;
										}
									})();
								}
							})();
						}
					})();
					return self0(args0..., xieite::any());
				} else if constexpr (requires { T { args0..., xieite::any() }; }) {
					return self0(args0..., xieite::any());
				} else {
					return sizeof...(args0) - offset;
				}
			})();
		} else {
			static_assert(false, "must not take arity of non-tuple-like nor aggregate type");
		}
	})();
}

XIEITE_DIAGNOSTIC_POP_CLANG()

#endif

// Algorithm borrowed from lapinozz (https://github.com/lapinozz)
