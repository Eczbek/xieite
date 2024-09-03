export module xieite:traits.IsSpecializationOf;

import std;

export namespace xieite::traits {
	template<typename, template<typename...> typename>
	struct IsSpecializationOf
	: std::false_type {};

	template<template<typename...> typename Template, typename... Arguments>
	struct IsSpecializationOf<Template<Arguments...>, Template>
	: std::true_type {};
}
