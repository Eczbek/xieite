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

		constexpr operator const Type&() const& noexcept {
			return this->value;
		}

		constexpr operator Type&()& noexcept {
			return this->value;
		}

		constexpr operator const Type&&() const&& noexcept {
			return std::move(this->value);
		}

		constexpr operator Type&&()&& noexcept {
			return std::move(this->value);
		}

		constexpr ~Shredder() {
			volatile std::byte* const byte = static_cast<std::byte*>(static_cast<void*>(&this->value));
			for (std::size_t i = 0; i < sizeof(Type); ++i) {
				byte[i] = 0;
			}
		}

	private:
		mutable Type value;
	};
}

#endif
