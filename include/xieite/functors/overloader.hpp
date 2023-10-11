#ifndef XIEITE_HEADER_FUNCTORS_OVERLOADER
#	define XIEITE_HEADER_FUNCTORS_OVERLOADER

#	include <utility>
#	include "../concepts/derivable.hpp"

namespace xieite::functors {
	template<xieite::concepts::Derivable... Derivables>
	struct Overloader
	: Derivables... {
		constexpr Overloader() noexcept = default;

		constexpr Overloader(const Derivables&... callbacks) noexcept
		: Derivables(callbacks)... {}

		constexpr Overloader(Derivables&&... callbacks) noexcept
		: Derivables(std::move(callbacks))... {}

		using Derivables::operator()...;
	};
}

#endif
