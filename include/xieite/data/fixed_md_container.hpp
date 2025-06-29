#ifndef DETAIL_XIEITE_HEADER_DATA_FIXED_MD_CONTAINER
#	define DETAIL_XIEITE_HEADER_DATA_FIXED_MD_CONTAINER
#
#	include <cstddef>
#	include "../meta/fold.hpp"
#	include "../meta/type.hpp"
#	include "../meta/value.hpp"

namespace DETAIL_XIEITE::fixed_md_container {
	template<template<typename, std::size_t> typename Container>
	constexpr auto impl = []<typename Prev, typename Size> { return xieite::type<Container<typename Prev::type, Size::value>>(); };
}

namespace xieite {
	template<template<typename, std::size_t> typename Container, typename Value, std::size_t... lengths>
	using fixed_md_container = xieite::fold<DETAIL_XIEITE::fixed_md_container::impl<Container>, xieite::type<Value>, xieite::value<lengths>...>;
}

#endif
