#ifndef DETAIL_XIEITE_HEADER_DATA_FIXED_MD_CONTAINER
#	define DETAIL_XIEITE_HEADER_DATA_FIXED_MD_CONTAINER
#
#	include <cstddef>
#	include <type_traits>
#	include "../meta/fold.hpp"
#	include "../meta/value.hpp"

namespace DETAIL_XIEITE::fixed_md_container {
	template<template<typename, std::size_t> typename Container, typename Value, std::size_t... lengths>
	struct impl : std::type_identity<xieite::fold<
		[]<typename Prev, typename Size> static {
			return std::type_identity<Container<typename Prev::type, Size::value>>();
		},
		std::type_identity<Value>,
		xieite::value<lengths>...
	>> {};
}

namespace xieite {
	template<template<typename, std::size_t> typename Container, typename Value, std::size_t... lengths>
	using fixed_md_container = DETAIL_XIEITE::fixed_md_container::impl<Container, Value, lengths...>::type;
}

#endif
