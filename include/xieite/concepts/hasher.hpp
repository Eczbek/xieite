#ifndef XIEITE_HEADER_CONCEPTS_HASHER
#	define XIEITE_HEADER_CONCEPTS_HASHER

#	include <concepts>
#	include <cstddef>
#	include <functional>

namespace xieite::concepts {
	template<template<typename> typename Template_, typename Argument_>
	concept Hasher = requires(Template_<Argument_> hasher, Argument_ value) {
		{ std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
	};
}

#endif
