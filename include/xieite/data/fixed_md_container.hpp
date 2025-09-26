#ifndef DETAIL_XIEITE_HEADER_DATA_FIXED_MD_CONTAINER
#	define DETAIL_XIEITE_HEADER_DATA_FIXED_MD_CONTAINER
#
#	include <cstddef>
#	include "../meta/fold.hpp"
#	include "../meta/wrap_type.hpp"
#	include "../meta/wrap_value.hpp"

namespace DETAIL_XIEITE::fixed_md_container {
	template<template<typename, std::size_t> typename Container>
	constexpr auto impl = []<typename Prev, typename Size> {
		return xieite::wrap_type<Container<typename Prev::type, Size::value>>();
	};
}

namespace xieite {
	template<
		template<typename, std::size_t> typename Container,
		typename Value,
		std::size_t... lengths
	>
	using fixed_md_container = xieite::fold<
		DETAIL_XIEITE::fixed_md_container::impl<Container>,
		xieite::wrap_type<Value>,
		xieite::wrap_value<lengths>...
	>::type;
}

#endif
