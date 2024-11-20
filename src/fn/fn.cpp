module;

#include <xieite/fwd.hpp>

export module xieite:fn;

import std;
import :is_invoc;

export namespace xieite {
	template<typename>
	struct fn;

	template<typename Ret, typename... Args>
	struct fn<Ret(Args...)> {
	public:
		[[nodiscard]] fn() = default;

		[[nodiscard]] constexpr fn(const xieite::fn<Ret(Args...)>& fn) noexcept
		: ptr(fn.ptr->clone()) {}

		template<xieite::is_invoc<Ret(Args...)> F>
		requires(!std::same_as<std::remove_cvref_t<F>, xieite::fn<Ret(Args...)>>)
		[[nodiscard]] constexpr fn(F&& fn) noexcept
		: ptr(std::make_unique<xieite::fn<Ret(Args...)>::derived<std::remove_cvref_t<F>>>(XIEITE_FWD(fn))) {}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return static_cast<bool>(this->ptr);
		}

		constexpr Ret operator()(Args... args) const noexcept(false) {
			// Explicitly not handling possible nullptr dereference
			return (*this->ptr)(args...);
		}

	private:
		struct base {
			virtual constexpr ~base() = default;

			virtual constexpr Ret operator()(Args...) const noexcept(false) = 0;

			virtual constexpr std::unique_ptr<xieite::fn<Ret(Args...)>::base> clone() const noexcept = 0;
		};

		template<typename F>
		struct derived : xieite::fn<Ret(Args...)>::base {
			mutable F fn;

			template<std::convertible_to<F> FRef>
			[[nodiscard]] constexpr derived(FRef&& fn) noexcept
			: fn(XIEITE_FWD(fn)) {}

			constexpr Ret operator()(Args... args) const noexcept(false) override {
				return std::invoke(this->fn, XIEITE_FWD(args)...);
			}

			[[nodiscard]] constexpr std::unique_ptr<xieite::fn<Ret(Args...)>::base> clone() const noexcept override {
				return std::make_unique<derived>(this->fn);
			}
		};

		std::unique_ptr<xieite::fn<Ret(Args...)>::base> ptr;
	};
}
