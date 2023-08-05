#ifndef XIEITE_HEADER__TYPES__PARTIAL_BACK
#	define XIEITE_HEADER__TYPES__PARTIAL_BACK

namespace xieite::types {
	template<template<typename...> typename Template, typename... BackArguments>
	struct PartialBack {
		template<typename... FrontArguments>
		using Type = Template<FrontArguments..., BackArguments...>;
	};
}

#endif
