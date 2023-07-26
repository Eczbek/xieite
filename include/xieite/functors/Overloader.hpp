#ifndef XIEITE_HEADER_FUNCTORS_OVERLOADER
#	define XIEITE_HEADER_FUNCTORS_OVERLOADER

#	include <xieite/concepts/Derivable.hpp>
#	include <xieite/functors/MakeFunctor.hpp>

namespace xieite::functors {
	template<xieite::concepts::Derivable... Derivables>
	struct Overloader
	: xieite::functors::MakeFunctor<Derivables>... {
		constexpr Overloader(const Derivables&... derivables) noexcept
		: xieite::functors::MakeFunctor<Derivables>(derivables)... {}

		using xieite::functors::MakeFunctor<Derivables>::operator()...;
	};
}

// Thanks to melak47 for help

#endif
