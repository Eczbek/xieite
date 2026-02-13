#ifndef DETAIL_XTE_HEADER_FUNC_GEN
#	define DETAIL_XTE_HEADER_FUNC_GEN
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_instance_of.hpp"
#	include "../trait/remove_cvref.hpp"
#	include "../trait/remove_ref.hpp"
#	include "../util/address.hpp"
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<typename Func>
	requires(requires { { xte::fake<Func&>()() } -> xte::is_instance_of<^^xte::opt>; })
	struct gen {
		struct iter {
			using difference_type = xte::iz;
			using value_type = xte::remove_cvref<decltype(*xte::fake<Func&>()())>;

			Func* _func;
			decltype(xte::fake<Func&>()()) _value;

			[[nodiscard]] explicit(false) constexpr iter() noexcept
			: _func(nullptr), _value(xte::null) {}

			[[nodiscard]] constexpr iter(Func* func, decltype(xte::fake<Func&>()()) value) XTE_ARROW_CTOR(,
				_func,((func)),
				_value,((xte::xvalue(value)))
			)

			[[nodiscard]] explicit(false) constexpr iter(const DETAIL_XTE::gen<Func>::iter& other) XTE_ARROW_CTOR(,
				_func,((other._func)),
				_value,((other._value))
			)

			[[nodiscard]] explicit(false) constexpr iter(DETAIL_XTE::gen<Func>::iter&& other) XTE_ARROW_CTOR(,
				_func,((other._func)),
				_value,((xte::xvalue(other)._value))
			)

			[[nodiscard]] constexpr auto operator=(const DETAIL_XTE::gen<Func>::iter& other) XTE_ARROW(
				void(this->_func = other._func),
				void(this->_value = other._value),
				*this
			)

			[[nodiscard]] constexpr auto operator=(DETAIL_XTE::gen<Func>::iter&& other) XTE_ARROW(
				void(this->_func = other._func),
				void(this->_value = xte::xvalue(other)._value),
				*this
			)

			[[nodiscard]] friend constexpr bool operator==(const DETAIL_XTE::gen<Func>::iter& lhs, const DETAIL_XTE::gen<Func>::iter& rhs) noexcept {
				return !lhs._value == !rhs._value;
			}

			[[nodiscard]] constexpr DETAIL_XTE::gen<Func>::iter::value_type operator*() const noexcept {
				return *this->_value;
			}

			constexpr auto operator++() & XTE_ARROW(
				void(this->_value = (*this->_func)()),
				*this
			)

			constexpr void operator++(int) const & noexcept {}
		};

		Func _func;

		[[nodiscard]] constexpr gen(auto&& func) XTE_ARROW_CTOR(,
			_func,((XTE_FWD(func)))
		)

		[[nodiscard]] constexpr auto begin() XTE_ARROW(
			DETAIL_XTE::gen<Func>::iter(xte::address(this->_func), this->_func())
		)

		[[nodiscard]] constexpr DETAIL_XTE::gen<Func>::iter end() const noexcept {
			return {};
		}
	};
}

namespace xte {
	inline constexpr auto gen = [][[nodiscard]](auto&& func) static XTE_ARROW(
		DETAIL_XTE::gen<xte::remove_ref<decltype(func)>>(XTE_FWD(func))
	);
}

#endif
