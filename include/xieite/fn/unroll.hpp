#ifndef DETAIL_XIEITE_HEADER_FN_UNROLL
#	define DETAIL_XIEITE_HEADER_FN_UNROLL
#
#	include <concepts>
#	include "../meta/make_seq.hpp"
#	include "../meta/seq.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<std::integral auto n>
	[[nodiscard]] constexpr auto unroll(auto&& fn, auto&&... args)
		XIEITE_ARROW((
			[]<auto... i>(xieite::seq<i...>, auto&& fn, auto&&... args) static
				XIEITE_ARROW(XIEITE_FWD(fn).template operator()<i...>(XIEITE_FWD(args)...))
		)(xieite::make_seq<n>, XIEITE_FWD(fn), XIEITE_FWD(args)...))

	template<typename... Ts>
	[[nodiscard]] constexpr auto unroll(auto&& fn, auto&&... args)
		XIEITE_ARROW(xieite::unroll<sizeof...(Ts)>(XIEITE_FWD(fn), XIEITE_FWD(args)...))
}

#endif
