module;

#include <xieite/forward.hpp>

export module xieite:memory.Shredder;

import std;
import :concepts.TriviallyDestructible;

export namespace xieite::memory {
	template<xieite::concepts::TriviallyDestructible Type>
	struct Shredder {
	public:
		constexpr Shredder() noexcept {
			this->shred();
		}

		template<typename... Arguments>
		requires(std::constructible_from<Type, Arguments...>)
		constexpr Shredder(Arguments&&... arguments) noexcept
		: value(XIEITE_FORWARD(arguments)...) {}

		template<typename Self>
		[[nodiscard]] constexpr auto&& data(this Self&& self) noexcept {
			return std::forward_like<Self>(self.value);
		}

		constexpr void shred() noexcept {
			if !consteval {
				const auto byte = reinterpret_cast<volatile std::byte*>(std::addressof(this->value));
				for (std::size_t i = 0; i < sizeof(Type); ++i) {
					byte[i] = static_cast<std::byte>(0);
				}
			}
		}

		constexpr ~Shredder() {
			this->shred();
		}

	private:
		mutable Type value;
	};
}
