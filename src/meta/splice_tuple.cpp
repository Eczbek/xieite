module;

#include <xieite/fwd.hpp>

export module xieite:splice_tuple;

import std;
import :fwd_tuple;
import :is_spec;
import :tuple_size;
import :unroll;

export namespace xieite {
	template<std::size_t start, std::size_t end = start, xieite::is_spec<std::tuple> Tuple0, xieite::is_spec<std::tuple> Tuple1 = std::tuple<>>
	[[nodiscard]] constexpr auto splice_tuple(Tuple0&& tuple0, Tuple1&& tuple1 = {}) noexcept {
		static_assert(start <= xieite::tuple_size<Tuple0>, "start index must be within tuple size");
		static_assert(end <= xieite::tuple_size<Tuple0>, "end index must be within tuple size");
		return std::tuple_cat(
			xieite::unroll<start>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<i>(std::move(tuple0))...);
			}),
			xieite::fwd_tuple(XIEITE_FWD(tuple1)),
			xieite::unroll<xieite::tuple_size<Tuple0> - end>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<end + i>(std::move(tuple0))...);
			})
		);
	}
}
