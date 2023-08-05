#ifndef XIEITE_HEADER__TYPES__PARTIAL_FRONT
#	define XIEITE_HEADER__TYPES__PARTIAL_FRONT

namespace xieite::types {
	template<template<typename...> typename Template, typename... FrontArguments>
	struct PartialFront {
		template<typename... BackArguments>
		using Type = Template<FrontArguments..., BackArguments...>;
	};
}

#endif
