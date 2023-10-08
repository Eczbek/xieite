#ifndef XIEITE_HEADER__FUNCTORS__OVERLOADER
#	define XIEITE_HEADER__FUNCTORS__OVERLOADER

#	include <utility>
#	include "../concepts/Derivable.hpp"

namespace xieite::functors {
	template<xieite::concepts::Derivable... Derivables>
	struct Overloader
	: Derivables... {
		constexpr Overloader() noexcept = default;

		constexpr Overloader(Derivables&&... callbacks) noexcept
		: Derivables(std::forward<Derivables>(callbacks))... {}

		using Derivables::operator()...;
	};
}

// Thanks to melak47 for help

#endif
