export module xieite:traits.IsTemplateOfAny;

import std;
import :concepts.TemplateOfAny;

export namespace xieite::traits {
	template<template<typename...> typename Template, typename... Types>
	struct IsTemplateOfAny
	: std::bool_constant<xieite::concepts::TemplateOfAny<Template, Types...>> {};
}
