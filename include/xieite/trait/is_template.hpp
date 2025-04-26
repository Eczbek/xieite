#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_TEMPLATE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_TEMPLATE
#
#	include "../trait/is_special.hpp"

namespace xieite {
	template<template<typename...> typename Template, typename... Ts>
	concept is_template = (... && xieite::is_special<Ts, Template>);
}

#endif
