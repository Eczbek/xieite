#ifndef DETAIL_XTE_HEADER_FUNC_FUNC
#	define DETAIL_XTE_HEADER_FUNC_FUNC
#
#	include "../data/ptr.hpp"
#	include "../preproc/constructs.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/drop_ref.hpp"

namespace xte {
	template<typename>
	struct func;

	template<typename return_type, typename... arg_types, bool noex_spec>
	struct func<return_type(arg_types...) noexcept(noex_spec)> {
	public:
		[[nodiscard]] explicit(false) constexpr func() noexcept = default;

		[[nodiscard]] explicit(false) constexpr func(const xte::func<return_type(arg_types...) noexcept(noex_spec)>& other) noexcept(false)
		: data(other.data->clone()) {}

		[[nodiscard]] explicit(false) constexpr func(auto&& func) XTE_CONSTRUCTS(,
			data,((xte::ptr<xte::func<return_type(arg_types...) noexcept(noex_spec)>::derived<xte::drop_ref<decltype(func)>>>::make_noex(XTE_FWD(func))))
		)

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return !!this->data;
		}

		[[nodiscard]] constexpr return_type operator()(arg_types... args) const noexcept(noex_spec) {
			return (*this->data)(XTE_FWD(args)...);
		}

	private:
		struct base {
			virtual constexpr ~base() = default;

			virtual constexpr return_type operator()(arg_types...) const noexcept(noex_spec) = 0;

			virtual constexpr xte::ptr<xte::func<return_type(arg_types...) noexcept(noex_spec)>::base> clone() const noexcept(false) = 0;
		};

		template<typename func_type>
		struct derived : xte::func<return_type(arg_types...) noexcept(noex_spec)>::base {
			mutable func_type func;

			[[nodiscard]] explicit constexpr derived(auto&& func) XTE_CONSTRUCTS(,
				func,((XTE_FWD(func)))
			)

			[[nodiscard]] constexpr return_type operator()(arg_types... args) const noexcept(noex_spec) override {
				return this->func(XTE_FWD(args)...);
			}

			[[nodiscard]] constexpr auto clone() const noexcept(false) override {
				return xte::ptr<xte::func<return_type(arg_types...) noexcept(noex_spec)>::derived<func_type>>::make_noex(this->func);
			}
		};

		xte::ptr<xte::func<return_type(arg_types...) noexcept(noex_spec)>::base> data;
	};
}

#endif
