#ifndef XIEITE_HEADER_CONTAINERS_MUTABLE
#	define XIEITE_HEADER_CONTAINERS_MUTABLE

#	include <concepts>
#	include <type_traits>
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<typename Type>
	class Mutable {
	public:
		template<typename... Arguments>
		constexpr Mutable(Arguments&&... arguments)
		noexcept(std::is_nothrow_constructible_v<Type, Arguments...>)
		: value(XIEITE_FORWARD(arguments)...) {}

		[[nodiscard]] constexpr operator Type&() const& noexcept {
			return this->value;
		}

		[[nodiscard]] constexpr operator Type&&() const&& noexcept {
			return this->value;
		}

	private:
		mutable Type value;
	};
}

#endif
