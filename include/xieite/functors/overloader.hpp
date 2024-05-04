#ifndef XIEITE_HEADER_FUNCTORS_OVERLOADER
#	define XIEITE_HEADER_FUNCTORS_OVERLOADER

#	include <concepts>
#	include "../concepts/derivable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<xieite::concepts::Derivable... Derivables_>
	struct Overloader
	: Derivables_... {
		constexpr Overloader() noexcept = default;

		template<typename... DerivableReferences_>
		requires((... && std::convertible_to<DerivableReferences_, Derivables_>))
		constexpr Overloader(DerivableReferences_&&... callbacks) noexcept
		: Derivables_(XIEITE_FORWARD(callbacks))... {}

		using Derivables::operator()...;
	};
}

#endif
