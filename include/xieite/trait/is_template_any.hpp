#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_TEMPLATE_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_TEMPLATE_ANY
#
#	include "../trait/is_template.hpp"

namespace xieite {
	template<template<typename...> typename Template, typename... Ts>
	concept is_template_any = (... || xieite::is_template<Template, Ts>);
}

#endif
