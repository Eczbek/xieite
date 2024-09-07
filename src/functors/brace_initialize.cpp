module;

#include <xieite/forward.hpp>

export module xieite:functors.BraceInitialize;

import :concepts.BraceInitializable;
import :concepts.NoThrowBraceInitializable;

export namespace xieite::functors {
	template<typename Type>
	struct BraceInitialize {
		template<typename... Arguments>
		requires(xieite::concepts::BraceInitializable<Type, Arguments...>)
		[[nodiscard]] constexpr Type operator()(Arguments&&... arguments) const
		noexcept(xieite::concepts::NoThrowBraceInitializable<Type, Arguments...>) {
			return Type { XIEITE_FORWARD(arguments)... };
		}
	};
}
