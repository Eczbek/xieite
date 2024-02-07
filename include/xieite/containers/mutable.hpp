#ifndef XIEITE_HEADER_CONTAINERS_MUTABLE
#	define XIEITE_HEADER_CONTAINERS_MUTABLE

#	include <concepts>
#	include <type_traits>
#	include "../macros/forward.hpp"
#	include "../types/collapse_reference.hpp"

namespace xieite::containers {
	template<typename Type>
	class Mutable {
	public:
		template<typename... Arguments>
		constexpr Mutable(Arguments&&... arguments)
		noexcept(std::is_nothrow_constructible_v<Type, Arguments...>)
		: value(XIEITE_FORWARD(arguments)...) {}

		template<typename Self>
		[[nodiscard]] constexpr operator xieite::types::CollapseReference<Type, Self>(this Self&& self) noexcept {
			return XIEITE_FORWARD(self).value;
		}

	private:
		mutable Type value;
	};
}

#endif
