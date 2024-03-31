#ifndef XIEITE_HEADER_FUNCTORS_FUNCTION
#	define XIEITE_HEADER_FUNCTORS_FUNCTION

#	include <concepts>
#	include <functional>
#	include <memory>
#	include <type_traits>
#	include "../concepts/functable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename>
	struct Function;

	template<typename Result, typename... Arguments>
	struct Function<Result(Arguments...)> {
	public:
		constexpr Function() noexcept = default;

		template<typename Functor>
		constexpr Function(const xieite::functors::Function<Result(Arguments...)>& function) noexcept
		: pointer(function.pointer->clone()) {}

		template<xieite::concepts::Functable<Result(Arguments...)> Functor>
		requires(!std::same_as<std::remove_cvref_t<Functor>, xieite::functors::Function<Result(Arguments...)>>)
		constexpr Function(Functor&& functor) noexcept
		: pointer(std::make_unique<xieite::functors::Function<Result(Arguments...)>::Derived<std::remove_cvref_t<Functor>>>(XIEITE_FORWARD(functor))) {}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return static_cast<bool>(this->pointer);
		}

		template<typename... ArgumentReferences>
		requires((... && std::convertible_to<ArgumentReferences, Arguments>))
		constexpr Result operator()(ArgumentReferences&&... arguments) const {
			// Not handling nullptr dereference
			return (*this->pointer)(XIEITE_FORWARD(arguments)...);
		}

	private:
		struct Base {
			virtual constexpr ~Base() = default;

			virtual constexpr Result operator()(Arguments...) const = 0;

			virtual constexpr std::unique_ptr<Base> clone() const noexcept = 0;
		};

		template<typename Functor>
		struct Derived
		: xieite::functors::Function<Result(Arguments...)>::Base {
			mutable Functor functor;

			template<std::convertible_to<Functor> FunctorReference>
			constexpr Derived(FunctorReference&& functor) noexcept
			: functor(XIEITE_FORWARD(functor)) {}

			constexpr Result operator()(Arguments... arguments) const override {
				return std::invoke(this->functor, XIEITE_FORWARD(arguments)...);
			}

			constexpr std::unique_ptr<Base> clone() const noexcept override {
				return std::make_unique<Derived<Functor>>(this->functor);
			}
		};

		std::unique_ptr<xieite::functors::Function<Result(Arguments...)>::Base> pointer;
	};
}

#endif
