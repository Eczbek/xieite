#ifndef XIEITE_HEADER_FUNCTORS_TEMPLATIFY
#	define XIEITE_HEADER_FUNCTORS_TEMPLATIFY

#	include <cstdint>
#	include <cstddef>
#	include <functional>
#	include <limits>
#	include <utility>

namespace xieite::functors {
	template<template<std::uint8_t> typename Functor>
	constexpr void templatify(const std::uint8_t value) noexcept {
		([value]<std::size_t... indices>(std::index_sequence<indices...>) {
			(..., ([value] {
				static constexpr std::uint8_t index = static_cast<std::uint8_t>(indices);
				if (value == index) {
					std::invoke(Functor<index>());
				}
			})());
		})(std::make_index_sequence<static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max()) + 1>());
	}
}

#endif
