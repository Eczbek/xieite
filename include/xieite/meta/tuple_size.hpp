#ifndef DETAIL_XIEITE_HEADER_META_TUPLE_SIZE
#	define DETAIL_XIEITE_HEADER_META_TUPLE_SIZE
#
#	include <cstddef>
#	include <tuple>
#	include <type_traits>

namespace xieite {
	template<typename T>
	constexpr std::size_t tuple_size = std::tuple_size_v<std::remove_cvref_t<T>>;
}

#endif
