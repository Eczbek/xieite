#pragma once

#include <cstddef>
#include <type_traits>
#include "../meta/value.hpp"

namespace xieite {
	template<template<typename, std::size_t> typename Ctnr, typename V, std::size_t... sizes>
	using fixed_md_ctnr = decltype(([]<std::size_t... curr>(this auto self, xieite::value<curr>...) {
		if constexpr (sizeof...(curr)) {
			return ([self]<std::size_t first, std::size_t... rest> {
				return std::type_identity<Ctnr<typename decltype(self(xieite::value<rest>()...))::type, first>>();
			})(xieite::value<curr>()...);
		} else {
			return std::type_identity<V>();
		}
	})(xieite::value<sizes>()...))::type;
}
