module;

#include <xieite/forward.hpp>

export module xieite:functors.Function;

import std;
import :concepts.Invocable;

export namespace xieite::functors {
	template<typename>
	struct Function;

	template<typename Return, typename... Arguments>
	struct Function<Return(Arguments...)> {
	public:
		Function() = default;

		explicit(false) constexpr Function(const Function& function) noexcept
		: pointer(function.pointer->clone()) {}

		template<xieite::concepts::Invocable<Return(Arguments...)> Functor>
		requires(!std::same_as<std::remove_cvref_t<Functor>, Function>)
		explicit(false) constexpr Function(Functor&& functor) noexcept
		: pointer(std::make_unique<Function::Derived<std::remove_cvref_t<Functor>>>(XIEITE_FORWARD(functor))) {}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return static_cast<bool>(this->pointer);
		}

		template<typename... ArgumentReferences>
		requires((... && std::convertible_to<ArgumentReferences, Arguments>))
		/* discardable */ constexpr Return operator()(ArgumentReferences&&... arguments) const noexcept(false) {
			// Explicitly not handling possible nullptr dereference
			return (*this->pointer)(XIEITE_FORWARD(arguments)...);
		}

	private:
		struct Base {
			virtual constexpr ~Base() = default;

			virtual constexpr Return operator()(Arguments...) const noexcept(false) = 0;

			virtual constexpr std::unique_ptr<Function::Base> clone() const noexcept = 0;
		};

		template<typename Functor>
		struct Derived
		: Function::Base {
			mutable Functor functor;

			template<std::convertible_to<Functor> FunctorReference>
			explicit(false) constexpr Derived(FunctorReference&& functor) noexcept
			: functor(XIEITE_FORWARD(functor)) {}

			/* discardable */ constexpr Return operator()(Arguments... arguments) const noexcept(false) override {
				return std::invoke(this->functor, XIEITE_FORWARD(arguments)...);
			}

			[[nodiscard]] constexpr std::unique_ptr<Function::Base> clone() const noexcept override {
				return std::make_unique<Derived>(this->functor);
			}
		};

		std::unique_ptr<Function::Base> pointer;
	};
}
