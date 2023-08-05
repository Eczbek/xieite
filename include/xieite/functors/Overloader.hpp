#ifndef XIEITE_HEADER__FUNCTORS__OVERLOADER
#	define XIEITE_HEADER__FUNCTORS__OVERLOADER

#	include "../concepts/Derivable.hpp"

namespace xieite::functors {
	template<xieite::concepts::Derivable... Derivables>
	struct Overloader
	: Derivables... {
		constexpr Overloader() noexcept = default;

		constexpr Overloader(const Derivables&... derivables) noexcept
		: Derivables(derivables)... {}

		using Derivables::operator()...;
	};
}

// Thanks to melak47 for help

#endif
