#ifndef XIEITE_HEADER_FUNCTORS_OVERLOADER
#	define XIEITE_HEADER_FUNCTORS_OVERLOADER

#	include <concepts>
#	include <utility>
#	include "../concepts/derivable.hpp"

namespace xieite::functors {
	template<xieite::concepts::Derivable... Derivables>
	struct Overloader
	: Derivables... {
		constexpr Overloader() noexcept = default;

		template<typename... DerivableReferences>
		requires((... && std::convertible_to<DerivableReferences, Derivables>))
		constexpr Overloader(DerivableReferences&&... callbacks) noexcept
		: Derivables(std::forward<DerivableReferences>(callbacks))... {}

		using Derivables::operator()...;
	};
}

#endif
