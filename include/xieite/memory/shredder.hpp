#ifndef XIEITE_HEADER_MEMORY_SHREDDER
#	define XIEITE_HEADER_MEMORY_SHREDDER

#	include <concepts>
#	include <cstddef>
#	include <utility>
#	include "../macros/forward.hpp"

namespace xieite::memory {
	template<typename Type>
	class Shredder {
	public:
		constexpr Shredder() noexcept = default;

		template<typename... Arguments>
		requires(std::constructible_from<Type, Arguments...>)
		constexpr Shredder(Arguments&&... arguments) noexcept
		: value(XIEITE_FORWARD(arguments)...) {}

		template<typename Self>
		[[nodiscard]] std::convertible_to<Type> auto&& data(this Self&& self) noexcept {
			return XIEITE_FORWARD(self).value;
		}

		constexpr ~Shredder() {
			if !consteval {
				const auto byte = reinterpret_cast<volatile std::byte*>(&this->value);
				for (std::size_t i = 0; i < sizeof(Type); ++i) {
					byte[i] = 0;
				}
			}
		}

	private:
		mutable Type value;
	};
}

#endif
