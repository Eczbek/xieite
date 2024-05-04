#ifndef XIEITE_HEADER_MEMORY_SHREDDER
#	define XIEITE_HEADER_MEMORY_SHREDDER

#	include <concepts>
#	include <cstddef>
#	include <utility>
#	include "../concepts/trivially_destructible.hpp"
#	include "../macros/forward.hpp"

namespace xieite::memory {
	template<xieite::concepts::TriviallyDestructible Type_>
	struct Shredder {
	public:
		constexpr Shredder() noexcept {
			this->shred();
		}

		template<typename... Arguments_>
		requires(std::constructible_from<Type_, Arguments_...>)
		constexpr Shredder(Arguments_&&... arguments) noexcept
		: value(XIEITE_FORWARD(arguments)...) {}

		template<typename Self>
		[[nodiscard]] constexpr auto&& data(this Self&& self) noexcept {
			return XIEITE_FORWARD(self).value;
		}

		constexpr void shred() noexcept {
			if !consteval {
				const auto byte = reinterpret_cast<volatile std::byte*>(&this->value);
				for (std::size_t i = 0; i < sizeof(Type_); ++i) {
					byte[i] = 0;
				}
			}
		}

		constexpr ~Shredder() {
			this->shred();
		}

	private:
		mutable Type_ value;
	};
}

#endif
