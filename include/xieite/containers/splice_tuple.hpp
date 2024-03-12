#ifndef XIEITE_HEADER_CONTAINERS_SPLICE_TUPLE
#	define XIEITE_HEADER_CONTAINERS_SPLICE_TUPLE

#	include <concepts>
#	include <cstddef>
#	include <tuple>
#	include <utility>

namespace xieite::containers {
	template<std::size_t start, std::size_t count = 0, typename... Types1, typename... Types2>
	requires((start <= sizeof...(Types1)) && (count <= (sizeof...(Types1) - start)))
	[[nodiscard]] constexpr auto spliceTuple(const std::tuple<Types1...>& tuple1, const std::tuple<Types2...>& tuple2 = std::tuple<>()) noexcept {
		return std::tuple_cat(([&tuple1]<std::size_t... i>(std::index_sequence<i...>) -> auto {
			return std::forward_as_tuple(std::get<i>(std::move(tuple1))...);
		})(std::make_index_sequence<start>()), ([&tuple2]<std::size_t... i>(std::index_sequence<i...>) -> auto {
			return std::forward_as_tuple(std::get<i>(std::move(tuple2))...);
		})(std::make_index_sequence<sizeof...(Types2)>()), ([&tuple1]<std::size_t... i>(std::index_sequence<i...>) -> auto {
			return std::forward_as_tuple(std::get<i + start + count>(std::move(tuple1))...);
		})(std::make_index_sequence<sizeof...(Types1) - start - count>()));
	}
}

#endif
