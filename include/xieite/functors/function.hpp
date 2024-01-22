#ifndef XIEITE_HEADER_FUNCTORS_FUNCTION
#	define XIEITE_HEADER_FUNCTORS_FUNCTION

#	include <concepts>
#	include <functional>
#	include <memory>
#	include <type_traits>
#	include <utility>
#	include "../concepts/functable.hpp"
#	include "../exceptions/unset_functor_invoked.hpp"

namespace xieite::functors {
	template<typename>
	struct Function;

	template<typename Result, typename... Arguments>
	class Function<Result(Arguments...)> {
	public:
		constexpr Function() noexcept = default;

		template<xieite::concepts::Functable<Result(Arguments...)> Functor>
		constexpr Function(Functor&& functor) noexcept
		: pointer(std::make_unique<xieite::functors::Function<Result(Arguments...)>::Derived<Functor>>(std::forward<Functor>(functor))) {}

		[[nodiscard]] constexpr operator bool() const noexcept {
			return this->pointer;
		}

		template<typename... ArgumentReferences>
		requires((... && std::convertible_to<ArgumentReferences, Arguments>))
		constexpr Result operator()(ArgumentReferences&&... arguments) const {
			if (!*this) {
				throw xieite::exceptions::UnsetFunctorInvoked("Cannot invoke unset functor");
			}
			return (*this->pointer)(std::forward<ArgumentReferences>(arguments)...);
		}

	private:
		struct Base {
			virtual constexpr ~Base() = default;

			virtual constexpr Result operator()(Arguments...) const = 0;
		};

		template<typename Functor>
		struct Derived
		: xieite::functors::Function<Result(Arguments...)>::Base {
			mutable Functor functor;

			template<std::convertible_to<Functor> FunctorReference>
			constexpr Derived(FunctorReference&& functor) noexcept
			: functor(std::forward<FunctorReference>(functor)) {}

			template<typename... ArgumentReferences>
			requires((... && std::convertible_to<ArgumentReferences, Arguments>))
			constexpr Result operator()(ArgumentReferences&&... arguments) const {
				return std::invoke(this->functor, std::forward<ArgumentReferences>(arguments)...);
			}
		};

		std::shared_ptr<xieite::functors::Function<Result(Arguments...)>::Base> pointer;
	};
}

#endif
