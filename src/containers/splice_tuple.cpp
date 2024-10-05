module;

#include <xieite/forward.hpp>

export module xieite:containers.spliceTuple;

import std;
import :concepts.SpecializationOf;
import :containers.forwardTuple;

export namespace xieite::containers {
	template<std::size_t start, std::size_t end = start, xieite::concepts::SpecializationOf<std::tuple> Tuple1, xieite::concepts::SpecializationOf<std::tuple> Tuple2 = std::tuple<>>
	[[nodiscard]] constexpr auto spliceTuple(Tuple1&& tuple1, Tuple2&& tuple2 = Tuple2()) noexcept {
		static constexpr std::size_t tupleSize = std::tuple_size_v<std::remove_cvref_t<Tuple1>>;
		static_assert(start <= tupleSize, "start index must be within tuple size");
		static_assert(end <= tupleSize, "end index must be within tuple size");
		return std::tuple_cat(
			([&tuple1]<std::size_t... i>(std::index_sequence<i...>) {
				return std::forward_as_tuple(std::get<i>(std::move(tuple1))...);
			})(std::make_index_sequence<start>()),
			xieite::containers::forwardTuple(XIEITE_FORWARD(tuple2)),
			([&tuple1]<std::size_t... i>(std::index_sequence<i...>) {
				return std::forward_as_tuple(std::get<end + i>(std::move(tuple1))...);
			})(std::make_index_sequence<tupleSize - end>())
		);
	}
}
