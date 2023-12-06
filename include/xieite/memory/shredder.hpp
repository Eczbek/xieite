#ifndef XIEITE_HEADER_MEMORY_SHREDDER
#	define XIEITE_HEADER_MEMORY_SHREDDER

#	include <concepts>
#	include <cstring>
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
			if !consteval {
				std::memset(&this->value, 0, sizeof(this->value));
			}
		}

	private:
		mutable Type value;
	};
}

#endif
