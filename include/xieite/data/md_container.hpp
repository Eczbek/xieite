#ifndef DETAIL_XIEITE_HEADER_DATA_MD_CONTAINER
#	define DETAIL_XIEITE_HEADER_DATA_MD_CONTAINER
#
#	include <cstddef>
#	include "../meta/type.hpp"
#	include "../meta/fold_for.hpp"

namespace DETAIL_XIEITE::md_container {
	template<template<typename> typename Container>
	constexpr auto impl = []<typename Prev, auto> static {
		return xieite::type<Container<typename Prev::type>>();
	};
}

namespace xieite {
	template<template<typename> typename Container, typename Value, std::size_t rank>
	using md_container = xieite::fold_for<DETAIL_XIEITE::md_container::impl<Container>, xieite::type<Value>, rank>;
}

#endif
