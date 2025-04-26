#ifndef DETAIL_XIEITE_HEADER_DATA_MD_CONTAINER
#	define DETAIL_XIEITE_HEADER_DATA_MD_CONTAINER
#
#	include <cstddef>
#	include <type_traits>
#	include "../fn/unroll.hpp"
#	include "../meta/fold.hpp"

namespace DETAIL_XIEITE::md_container {
	template<template<typename> typename Container, typename Value, std::size_t rank>
	struct impl : decltype(xieite::unroll<rank>([]<std::size_t... i> static {
		return xieite::fold<
			[]<typename Prev, typename> static {
				return std::type_identity<Container<typename Prev::type>>();
			},
			std::type_identity<Value>,
			decltype(i)...
		>();
	})) {};
}

namespace xieite {
	template<template<typename> typename Container, typename Value, std::size_t rank>
	using md_container = DETAIL_XIEITE::md_container::impl<Container, Value, rank>::type;
}

#endif
