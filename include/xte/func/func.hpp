#ifndef DETAIL_XTE_HEADER_FUNC_FUNC
#	define DETAIL_XTE_HEADER_FUNC_FUNC
#
#	include "../data/ptr.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename>
	struct func;

	template<typename Return, typename... Args, bool noex>
	struct func<Return(Args...) noexcept(noex)> {
	public:
		[[nodiscard]] explicit(false) constexpr func() noexcept = default;

		[[nodiscard]] explicit(false) constexpr func(const xte::func<Return(Args...) noexcept(noex)>& other) noexcept(false)
		: data(other.data->clone()) {}

		[[nodiscard]] explicit(false) constexpr func(auto&& func) XTE_ARROW_CTOR(,
			data,((xte::ptr<xte::func<Return(Args...) noexcept(noex)>::derived<xte::remove_ref<decltype(func)>>>::make_noex(XTE_FWD(func))))
		)

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return !!this->data;
		}

		[[nodiscard]] constexpr Return operator()(Args... args) const noexcept(noex) {
			return (*this->data)(XTE_FWD(args)...);
		}

	private:
		struct base {
			virtual constexpr ~base() = default;

			virtual constexpr Return operator()(Args...) const noexcept(noex) = 0;

			virtual constexpr xte::ptr<xte::func<Return(Args...) noexcept(noex)>::base> clone() const noexcept(false) = 0;
		};

		template<typename Func>
		struct derived : xte::func<Return(Args...) noexcept(noex)>::base {
			mutable Func func;

			[[nodiscard]] explicit constexpr derived(auto&& func) XTE_ARROW_CTOR(,
				func,((XTE_FWD(func)))
			)

			[[nodiscard]] constexpr Return operator()(Args... args) const noexcept(noex) override {
				return this->func(XTE_FWD(args)...);
			}

			[[nodiscard]] constexpr auto clone() const noexcept(false) override {
				return xte::ptr<xte::func<Return(Args...) noexcept(noex)>::derived<Func>>::make_noex(this->func);
			}
		};

		xte::ptr<xte::func<Return(Args...) noexcept(noex)>::base> data;
	};
}

#endif
