#ifndef XIEITE_HEADER_CONTAINERS_SPLICE_TUPLE
#	define XIEITE_HEADER_CONTAINERS_SPLICE_TUPLE

#	include <cstddef>
#	include <tuple>
#	include <type_traits>
#	include <utility>
#	include "../concepts/specialization_of.hpp"
#	include "../containers/forward_tuple.hpp"
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<std::size_t start, std::size_t count = 0, xieite::concepts::SpecializationOf<std::tuple> Tuple1_, xieite::concepts::SpecializationOf<std::tuple> Tuple2_ = std::tuple<>>
	requires((start <= std::tuple_size_v<std::remove_cvref_t<Tuple1_>>) && (count <= (std::tuple_size_v<std::remove_cvref_t<Tuple1_>> - start)))
	[[nodiscard]] constexpr auto spliceTuple(Tuple1_&& tuple1, Tuple2_&& tuple2 = Tuple2_()) noexcept {
		return std::tuple_cat(([&tuple1]<std::size_t... i>(std::index_sequence<i...>) -> auto {
			return std::forward_as_tuple(std::get<i>(std::move(tuple1))...);
		})(std::make_index_sequence<start>()), xieite::containers::forwardTuple(XIEITE_FORWARD(tuple2)), ([&tuple1]<std::size_t... i>(std::index_sequence<i...>) -> auto {
			return std::forward_as_tuple(std::get<i + start + count>(std::move(tuple1))...);
		})(std::make_index_sequence<std::tuple_size_v<std::remove_cvref_t<Tuple1_>> - start - count>()));
	}
}

#endif
