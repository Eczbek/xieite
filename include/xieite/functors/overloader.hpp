#ifndef XIEITE_HEADER_FUNCTORS_OVERLOADER
#	define XIEITE_HEADER_FUNCTORS_OVERLOADER

#	include <concepts>
#	include "../concepts/derivable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<xieite::concepts::Derivable... Derivables>
	struct Overloader
	: Derivables... {
		constexpr Overloader() noexcept = default;

		template<typename... DerivableReferences>
		requires((... && std::convertible_to<DerivableReferences, Derivables>))
		constexpr Overloader(DerivableReferences&&... callbacks) noexcept
		: Derivables(XIEITE_FORWARD(callbacks))... {}

		using Derivables::operator()...;
	};
}

#endif
