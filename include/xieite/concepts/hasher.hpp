#ifndef XIEITE_HEADER_CONCEPTS_HASHER
#	define XIEITE_HEADER_CONCEPTS_HASHER

#	include <concepts>
#	include <cstddef>
#	include <functional>

namespace xieite::concepts {
	template<template<typename> typename Template, typename Argument>
	concept Hasher = requires(Template<Argument> hasher, Argument value) {
		{ std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
	};
}

#endif
