module;

#include <xieite/fwd.hpp>

export module xieite:shredder;

import std;
import :has_trivial_dtor;

export namespace xieite {
	template<xieite::has_trivial_dtor T>
	struct shredder {
	public:
		[[nodiscard]] constexpr shredder() noexcept {
			this->shred();
		}

		template<typename... Args>
		requires(std::constructible_from<T, Args...>)
		[[nodiscard]] constexpr shredder(Args&&... args) noexcept
		: value(XIEITE_FWD(args)...) {}

		template<typename Self>
		[[nodiscard]] constexpr auto&& data(this Self&& self) noexcept {
			return std::forward_like<Self>(self.value);
		}

		constexpr void shred() noexcept {
			if !consteval {
				const auto byte = reinterpret_cast<volatile char*>(std::addressof(this->value));
				for (std::size_t i = 0; i < sizeof(T); ++i) {
					byte[i] = '\0';
				}
			}
		}

		constexpr ~shredder() {
			this->shred();
		}

	private:
		mutable T value;
	};
}
