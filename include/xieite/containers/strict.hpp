#ifndef XIEITE_HEADER_CONTAINERS_STRICT
#	define XIEITE_HEADER_CONTAINERS_STRICT

#	include <concepts>
#	include <type_traits>
#	include "../macros/forward.hpp"
#	include "../types/collapse_reference.hpp"

namespace xieite::containers {
	template<typename Type>
	class Strict {
	public:
		template<typename TypeReference>
		requires(std::same_as<std::remove_cvref_t<TypeReference>, Type>)
		constexpr Strict(TypeReference&& value) noexcept
		: value(XIEITE_FORWARD(value)) {}

		template<typename Self>
		[[nodiscard]] constexpr operator xieite::types::CollapseReference<Type, Self>(this Self&& self) noexcept {
			return XIEITE_FORWARD(self).value;
		}

	private:
		Type value;
	};
}

#endif
