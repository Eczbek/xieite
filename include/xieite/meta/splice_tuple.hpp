#ifndef DETAIL_XIEITE_HEADER_META_SPLICE_TUPLE
#	define DETAIL_XIEITE_HEADER_META_SPLICE_TUPLE
#
#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../fn/unroll.hpp"
#	include "../meta/fwd_tuple.hpp"
#	include "../meta/tuple_size.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_spec.hpp"

namespace xieite {
	template<std::size_t start, std::size_t end = start, xieite::is_tuple_like Tuple0, xieite::is_tuple_like Tuple1 = std::tuple<>>
	[[nodiscard]] constexpr auto splice_tuple(Tuple0&& tuple0, Tuple1&& tuple1 = {}) noexcept {
		static_assert(start <= xieite::tuple_size<Tuple0>, "start index must be within tuple size");
		static_assert(end <= xieite::tuple_size<Tuple0>, "end index must be within tuple size");
		return std::tuple_cat(
			xieite::unroll<start>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<i>(std::move(tuple0))...);
			}),
			xieite::fwd_tuple(XIEITE_FWD(tuple1)),
			xieite::unroll<(xieite::tuple_size<Tuple0> - end)>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<(end + i)>(std::move(tuple0))...);
			})
		);
	}
}

#endif
