#ifndef DETAIL_XIEITE_HEADER_FN_FN
#	define DETAIL_XIEITE_HEADER_FN_FN
#
#	include <concepts>
#	include <functional>
#	include <memory>
#	include <type_traits>
#	include "../pp/debug.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_lref_invoc.hpp"
#	include "../trait/is_ref_to.hpp"

namespace xieite {
	template<typename>
	struct fn;

	template<typename Ret, typename... Args, bool noex>
	struct fn<Ret(Args...) noexcept(noex)> {
	public:
		[[nodiscard]] fn() = default;

		[[nodiscard]] constexpr fn(const xieite::fn<Ret(Args...)>& fn) noexcept
		: ptr(fn.ptr->clone()) {}

		template<xieite::is_lref_invoc<Ret(Args...)> Fn>
		requires(!std::same_as<std::remove_cvref_t<Fn>, xieite::fn<Ret(Args...)>>)
		[[nodiscard]] constexpr fn(Fn&& fn) noexcept
		: ptr(std::make_unique<xieite::fn<Ret(Args...) noexcept(noex)>::derived<std::remove_cvref_t<Fn>>>(XIEITE_FWD(fn))) {}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return static_cast<bool>(this->ptr);
		}

		constexpr Ret operator()(Args... args) const noexcept(noex) {
			if constexpr (XIEITE_DEBUG) {
				if (!this->ptr) {
					throw std::bad_function_call();
				}
			}
			return (*this->ptr)(args...);
		}

	private:
		struct base {
			virtual constexpr ~base() = default;

			virtual constexpr Ret operator()(Args...) const noexcept(noex) = 0;

			virtual constexpr std::unique_ptr<xieite::fn<Ret(Args...) noexcept(noex)>::base> clone() const noexcept = 0;
		};

		template<typename Fn>
		struct derived : xieite::fn<Ret(Args...)>::base {
			mutable Fn fn;

			[[nodiscard]] constexpr derived(xieite::is_ref_to<Fn> auto&& fn) noexcept
			: fn(XIEITE_FWD(fn)) {}

			constexpr Ret operator()(Args... args) const noexcept(noex) override {
				return std::invoke(this->fn, XIEITE_FWD(args)...);
			}

			[[nodiscard]] constexpr std::unique_ptr<xieite::fn<Ret(Args...) noexcept(noex)>::base> clone() const noexcept override {
				return std::make_unique<derived>(this->fn);
			}
		};

		std::unique_ptr<xieite::fn<Ret(Args...) noexcept(noex)>::base> ptr;
	};
}

#endif
