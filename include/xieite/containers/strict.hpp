#ifndef XIEITE_HEADER_CONTAINERS_STRICT
#	define XIEITE_HEADER_CONTAINERS_STRICT

#	include <concepts>
#	include <type_traits>
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<typename Type>
	class Strict {
	public:
		template<typename TypeReference>
		requires(std::same_as<std::remove_cvref_t<TypeReference>, Type>)
		constexpr Strict(TypeReference&& value) noexcept
		: value(XIEITE_FORWARD(value)) {}

		[[nodiscard]] constexpr operator Type&() const& noexcept {
			return this->value;
		}

		[[nodiscard]] cosntexpr operator Type&&() const&& noexcept {
			return std::move(this->value);
		}

	private:
		Type value;
	};
}

#endif
