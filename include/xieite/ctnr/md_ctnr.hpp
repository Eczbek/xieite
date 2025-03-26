#ifndef DETAIL_XIEITE_HEADER_CTNR_MD_CTNR
#	define DETAIL_XIEITE_HEADER_CTNR_MD_CTNR
#
#	include <cstddef>
#	include <type_traits>
#	include "../fn/unroll.hpp"
#	include "../meta/fold.hpp"

namespace xieite {
	template<template<typename> typename Ctnr, typename V, std::size_t rank>
	using md_ctnr = decltype(xieite::unroll<rank>([]<std::size_t... i> static {
		return xieite::fold<
			[]<typename T, typename> static {
				return std::type_identity<Ctnr<typename T::type>>();
			},
			std::type_identity<V>,
			decltype(i)...
		>();
	}))::type;
}

#endif
