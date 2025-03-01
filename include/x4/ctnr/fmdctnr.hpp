#pragma once

#include <cstddef>
#include <type_traits>
#include "../meta/v.hpp"

namespace x4 {
	template<template<typename, std::size_t> typename Ctnr, typename V, std::size_t... sizes>
	using fmdctnr = decltype(([]<std::size_t... curr>(this auto self, x4::v<curr>...) {
		if constexpr (sizeof...(curr)) {
			return ([self]<std::size_t first, std::size_t... rest> {
				return std::type_identity<Ctnr<typename decltype(self(x4::v<rest>()...))::type, first>>();
			})(x4::v<curr>()...);
		} else {
			return std::type_identity<V>();
		}
	})(x4::v<sizes>()...))::type;
}
