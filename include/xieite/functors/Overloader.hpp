#ifndef XIEITE_HEADER_FUNCTORS_OVERLOADER
#	define XIEITE_HEADER_FUNCTORS_OVERLOADER

#	include <xieite/concepts/Derivable.hpp>

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
