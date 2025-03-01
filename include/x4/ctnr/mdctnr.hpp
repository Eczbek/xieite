#pragma once

#include <cstddef>
#include <type_traits>
#include "../meta/v.hpp"

namespace x4 {
	template<template<typename> typename Ctnr, typename V, std::size_t rank>
	using mdctnr = decltype(([]<std::size_t rest>(this auto self, x4::v<rest>) {
		if constexpr (rest) {
			return std::type_identity<Ctnr<typename decltype(self(x4::v<(rest - 1)>()))::type>>();
		} else {
			return std::type_identity<V>();
		}
	})(x4::v<rank>()))::type;
}
