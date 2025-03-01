#pragma once

#include <concepts>
#include <functional>
#include <memory>
#include <type_traits>
#include "../pp/fwd.hpp"
#include "../trait/isinvoc.hpp"

namespace x4 {
	template<typename>
	struct fn;

	template<typename Ret, typename... Args>
	struct fn<Ret(Args...)> {
	public:
		[[nodiscard]] fn() = default;

		[[nodiscard]] constexpr fn(const x4::fn<Ret(Args...)>& fn) noexcept
		: ptr(fn.ptr->clone()) {}

		template<x4::isinvoc<Ret(Args...)> F>
		requires(!std::same_as<std::remove_cvref_t<F>, x4::fn<Ret(Args...)>>)
		[[nodiscard]] constexpr fn(F&& fn) noexcept
		: ptr(std::make_unique<x4::fn<Ret(Args...)>::derived<std::remove_cvref_t<F>>>(X4FWD(fn))) {}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return static_cast<bool>(this->ptr);
		}

		constexpr Ret operator()(Args... args) const noexcept(false) {
			return (*this->ptr)(args...);
		}

	private:
		struct base {
			virtual constexpr ~base() = default;

			virtual constexpr Ret operator()(Args...) const noexcept(false) = 0;

			virtual constexpr std::unique_ptr<x4::fn<Ret(Args...)>::base> clone() const noexcept = 0;
		};

		template<typename F>
		struct derived : x4::fn<Ret(Args...)>::base {
			mutable F fn;

			template<std::convertible_to<F> FRef>
			[[nodiscard]] constexpr derived(FRef&& fn) noexcept
			: fn(X4FWD(fn)) {}

			constexpr Ret operator()(Args... args) const noexcept(false) override {
				return std::invoke(this->fn, X4FWD(args)...);
			}

			[[nodiscard]] constexpr std::unique_ptr<x4::fn<Ret(Args...)>::base> clone() const noexcept override {
				return std::make_unique<derived>(this->fn);
			}
		};

		std::unique_ptr<x4::fn<Ret(Args...)>::base> ptr;
	};
}
