#ifndef DETAIL_XTE_HEADER_FUNC_GEN
#	define DETAIL_XTE_HEADER_FUNC_GEN
#
#	include "../address.hpp"
#	include "../aliases.hpp"
#	include "../opt.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../qual_cast.hpp"
#	include "../trait/drop_cvref.hpp"
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_specialization_of.hpp"

namespace DETAIL_XTE::gen {
	template<typename func_type>
	requires(requires { { xte::fake<func_type&>()() } -> xte::is_specialization_of<^^xte::opt>; })
	struct impl {
		struct iter {
			using difference_type = xte::iz;
			using value_type = xte::drop_cvref<decltype(*xte::fake<func_type&>()())>;

			func_type* _func;
			decltype(xte::fake<func_type&>()()) _value;

			[[nodiscard]] explicit(false) constexpr iter() noexcept
			: _func(nullptr), _value(xte::null) {}

			[[nodiscard]] constexpr iter(func_type* func, decltype(xte::fake<func_type&>()()) value) XTE_CONSTRUCTS(
				(_func,(func))
				(_value,(xte::as_xvalue(value)))
			)

			[[nodiscard]] explicit(false) constexpr iter(const DETAIL_XTE::gen::impl<func_type>::iter& other) XTE_CONSTRUCTS(
				(_func,(other._func))
				(_value,(other._value))
			)

			[[nodiscard]] explicit(false) constexpr iter(DETAIL_XTE::gen::impl<func_type>::iter&& other) XTE_CONSTRUCTS(
				(_func,(other._func))
				(_value,(xte::as_xvalue(other)._value))
			)

			[[nodiscard]] constexpr auto operator=(const DETAIL_XTE::gen::impl<func_type>::iter& other) XTE_RETURNS(
				void(this->_func = other._func),
				void(this->_value = other._value),
				*this
			)

			[[nodiscard]] constexpr auto operator=(DETAIL_XTE::gen::impl<func_type>::iter&& other) XTE_RETURNS(
				void(this->_func = other._func),
				void(this->_value = xte::as_xvalue(other)._value),
				*this
			)

			[[nodiscard]] friend constexpr bool operator==(const DETAIL_XTE::gen::impl<func_type>::iter& lhs, const DETAIL_XTE::gen::impl<func_type>::iter& rhs) noexcept {
				return !lhs._value == !rhs._value;
			}

			[[nodiscard]] constexpr DETAIL_XTE::gen::impl<func_type>::iter::value_type operator*() const noexcept {
				return *this->_value;
			}

			constexpr auto operator++() & XTE_RETURNS(
				void(this->_value = (*this->_func)()),
				*this
			)

			constexpr void operator++(int) const& noexcept {}
		};

		func_type _func;

		[[nodiscard]] constexpr impl(auto&& func) XTE_CONSTRUCTS(
			(_func,(XTE_FWD(func)))
		)

		[[nodiscard]] constexpr auto begin() XTE_RETURNS(
			DETAIL_XTE::gen::impl<func_type>::iter(xte::address(this->_func), this->_func())
		)

		[[nodiscard]] constexpr DETAIL_XTE::gen::impl<func_type>::iter end() const noexcept {
			return {};
		}
	};
}

namespace xte {
	inline constexpr auto gen = [][[nodiscard]](auto&& func) static XTE_RETURNS(
		DETAIL_XTE::gen::impl<xte::drop_ref<decltype(func)>>(XTE_FWD(func))
	);
}

#endif
