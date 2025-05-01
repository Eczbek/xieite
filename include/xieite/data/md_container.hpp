#ifndef DETAIL_XIEITE_HEADER_DATA_MD_CONTAINER
#	define DETAIL_XIEITE_HEADER_DATA_MD_CONTAINER
#
#	include <cstddef>
#	include <type_traits>
#	include "../meta/fold_for.hpp"

namespace DETAIL_XIEITE::md_container {
	template<template<typename> typename Container>
	constexpr auto impl = []<typename Prev, auto> static {
		return std::type_identity<Container<typename Prev::type>>();
	};
}

namespace xieite {
	template<template<typename> typename Container, typename Value, std::size_t rank>
	using md_container = xieite::fold_for<DETAIL_XIEITE::md_container::impl<Container>, std::type_identity<Value>, rank>;
}

#endif
