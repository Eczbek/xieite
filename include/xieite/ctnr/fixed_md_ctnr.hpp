#ifndef DETAIL_XIEITE_HEADER_CTNR_FIXED_MD_CTNR
#	define DETAIL_XIEITE_HEADER_CTNR_FIXED_MD_CTNR
#
#	include <cstddef>
#	include <type_traits>
#	include "../meta/fold.hpp"
#	include "../meta/value.hpp"

namespace xieite {
	template<template<typename, std::size_t> typename Ctnr, typename V, std::size_t... sizes>
	using fixed_md_ctnr = xieite::fold<
		[]<typename T, typename Size> static {
			return std::type_identity<Ctnr<typename T::type, Size::value>>();
		},
		std::type_identity<V>,
		xieite::value<sizes>...
	>;
}

#endif
