#ifndef DETAIL_XIEITE_HEADER_FN_REPEAT
#	define DETAIL_XIEITE_HEADER_FN_REPEAT
#
#	include <concepts>
#	include "../meta/make_seq.hpp"
#	include "../meta/seq.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<std::integral auto n>
	constexpr void repeat(auto&& fn, auto&&... args)
		XIEITE_ARROW_RET((
			[]<auto... i>(xieite::seq<i...>, auto&& fn, auto&&... args) static
				XIEITE_ARROW((..., fn.template operator()<i>(args...)))
		)(xieite::make_seq<n>, XIEITE_FWD(fn), XIEITE_FWD(args)...))

	template<typename... Ts>
	constexpr void repeat(auto&& fn, auto&&... args)
		XIEITE_ARROW_RET(xieite::repeat<sizeof...(Ts)>(XIEITE_FWD(fn), XIEITE_FWD(args)...))
}

#endif
