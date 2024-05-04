#ifndef XIEITE_HEADER_FUNCTORS_TEMPLATIFY
#	define XIEITE_HEADER_FUNCTORS_TEMPLATIFY

#	include <cstddef>
#	include <cstdint>
#	include <functional>
#	include <limits>
#	include <utility>

namespace xieite::functors {
	template<template<std::uint8_t> typename Functor_>
	requires(([]<std::size_t... i_>(std::index_sequence<i_...>) {
		return (... && std::invocable<Functor_<static_cast<std::uint8_t>(i_)>>);
	})(std::make_index_sequence<static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max()) + 1>()))
	constexpr void templatify(const std::uint8_t value) noexcept {
		([value]<std::size_t... i_>(std::index_sequence<i_...>) {
			(..., ([value] {
				static constexpr std::uint8_t index = static_cast<std::uint8_t>(i_);
				if (value == index) {
					static_cast<void>(std::invoke(Functor_<index>()));
				}
			})());
		})(std::make_index_sequence<static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max()) + 1>());
	}
}

#endif
