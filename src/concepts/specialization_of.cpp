export module xieite:concepts.SpecializationOf;

import std;

template<typename, template<typename...> typename>
struct IsSpecializationOf
: std::false_type {};

template<template<typename...> typename Template, typename... Arguments>
struct IsSpecializationOf<Template<Arguments...>, Template>
: std::true_type {};

export namespace xieite::concepts {
	template<typename Type, template<typename...> typename Template>
	concept SpecializationOf = IsSpecializationOf<std::remove_cvref_t<Type>, Template>::value;
}
