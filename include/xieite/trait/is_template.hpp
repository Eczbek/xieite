#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_TEMPLATE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_TEMPLATE
#
#	include "../trait/is_spec.hpp"

namespace xieite {
	template<template<typename...> typename M, typename... Ts>
	concept is_template = (... && xieite::is_spec<Ts, M>);
}

#endif
