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

	template<typename Return_, typename... Arguments_>
	struct Function<Return_(Arguments_...)> {
	public:
		constexpr Function() noexcept = default;

		constexpr Function(const xieite::functors::Function<Return_(Arguments_...)>& function) noexcept
		: pointer(function.pointer->clone()) {}

		template<xieite::concepts::Functable<Return_(Arguments_...)> Functor_>
		requires(!std::same_as<std::remove_cvref_t<Functor_>, xieite::functors::Function<Return_(Arguments_...)>>)
		constexpr Function(Functor_&& functor) noexcept
		: pointer(std::make_unique<xieite::functors::Function<Return_(Arguments_...)>::Derived<std::remove_cvref_t<Functor_>>>(XIEITE_FORWARD(functor))) {}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return static_cast<bool>(this->pointer);
		}

		template<typename... ArgumentReferences_>
		requires((... && std::convertible_to<ArgumentReferences_, Arguments_>))
		constexpr Return_ operator()(ArgumentReferences_&&... arguments) const {
			// Not handling nullptr dereference
			return (*this->pointer)(XIEITE_FORWARD(arguments)...);
		}

	private:
		struct Base {
			virtual constexpr ~Base() = default;

			virtual constexpr Return_ operator()(Arguments_...) const = 0;

			virtual constexpr std::unique_ptr<xieite::functors::Function<Return_(Arguments_...)>::Base> clone() const noexcept = 0;
		};

		template<typename Functor_>
		struct Derived
		: xieite::functors::Function<Return_(Arguments_...)>::Base {
			mutable Functor_ functor;

			template<std::convertible_to<Functor_> FunctorReference_>
			constexpr Derived(FunctorReference_&& functor) noexcept
			: functor(XIEITE_FORWARD(functor)) {}

			constexpr Return_ operator()(Arguments_... arguments) const override {
				return std::invoke(this->functor, XIEITE_FORWARD(arguments)...);
			}

			constexpr std::unique_ptr<xieite::functors::Function<Return_(Arguments_...)>::Base> clone() const noexcept override {
				return std::make_unique<xieite::functors::Function<Return_(Arguments_...)>::Derived<Functor_>>(this->functor);
			}
		};

		std::unique_ptr<xieite::functors::Function<Return_(Arguments_...)>::Base> pointer;
	};
}

#endif
