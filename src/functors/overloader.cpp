module;

#include <xieite/forward.hpp>

export module xieite:functors.Overloader;

import :concepts.Derivable;

export namespace xieite::functors {
	template<xieite::concepts::Derivable... Functors>
	struct Overloader
	: Functors... {
		using Functors::operator()...;
	};

	template<typename... Functors>
	Overloader(Functors...) -> xieite::functors::Overloader<Functors...>;
}
