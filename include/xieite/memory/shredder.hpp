#ifndef XIEITE_HEADER_MEMORY_SHREDDER
#	define XIEITE_HEADER_MEMORY_SHREDDER

#	include <concepts>
#	include <cstddef>
#	include <utility>

namespace xieite::memory {
	template<typename Type>
	class Shredder {
	public:
		constexpr Shredder() noexcept = default;

		template<typename... Arguments>
		requires(std::constructible_from<Type, Arguments...>)
		constexpr Shredder(Arguments&&... arguments) noexcept
		: value(std::forward<Arguments>(arguments)...) {}

		[[nodiscard]] constexpr const Type& get() const noexcept {
			return this->value;
		}

		[[nodiscard]] constexpr Type& get() noexcept {
			return this->value;
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
