#ifndef DETAIL_XTE_HEADER_OPT
#	define DETAIL_XTE_HEADER_OPT
#
#	include "./address.hpp"
#	include "./assign.hpp"
#	include "./class_traits.hpp"
#	include "./exchange.hpp"
#	include "./in_place.hpp"
#	include "./macros.hpp"
#	include "./make.hpp"
#	include "./qual_traits.hpp"
#	include <type_traits>

namespace xte {
	inline constexpr struct {} null;

	template<typename item_type>
	struct opt {
	private:
		union {
			item_type _value;
		};
		bool _has_value = false;

	public:
		using value_type = item_type;

		[[nodiscard]] constexpr explicit(false) opt() noexcept = default;

		[[nodiscard]] constexpr explicit(false) opt(decltype(xte::null)) noexcept {}

		[[nodiscard]] constexpr explicit(false) opt(auto&&... args) XTE_CONSTRUCTS(
			(_value,(xte::make<item_type>(XTE_FWD(args)...)))
			(_has_value,(true))
		)

		[[nodiscard]] constexpr explicit(false) opt(xte::opt<item_type> const& other) XTE_CONSTRUCTS(,
			other._has_value ? void(xte::construct(this->_value, other._value)) : void(),
			this->_has_value = other._has_value
		)

		[[nodiscard]] constexpr explicit(false) opt(xte::opt<item_type>&& other) XTE_CONSTRUCTS(,
			other._has_value ? (
				xte::construct(this->_value, xte::as_xvalue(other)._value),
				xte::destroy(other._value)
			) : void(),
			this->_has_value = xte::exchange(other._has_value, false)
		)

		constexpr ~opt() {
			this->reset();
		}

		constexpr xte::opt<item_type>& operator=(xte::opt<item_type> const&) & noexcept = default;

		constexpr xte::opt<item_type>& operator=(xte::opt<item_type>&&) & noexcept = default;

		constexpr auto operator=(auto&& arg) & XTE_RETURNS(
			this->_has_value ? void(xte::assign(this->_value, XTE_FWD(arg))) : void(xte::construct(this->_value, XTE_FWD(arg))),
			this->_has_value = true,
			*this
		)

		[[nodiscard]] constexpr explicit operator bool() const noexcept {
			return this->_has_value;
		}

		[[nodiscard]] constexpr auto&& operator*(this auto&& self) noexcept {
			return XTE_FWD(self)._value;
		}

		[[nodiscard]] constexpr auto* operator->(this auto&& self) noexcept {
			return xte::address(self._value);
		}

		[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, xte::is_member_ptr_of<item_type> auto&& member) noexcept {
			if constexpr (std::is_member_function_pointer_v<xte::drop_ref<decltype(member)>>) {
				return XTE_LIFT_LOCAL((XTE_FWD(self)._value.*member));
			} else {
				return xte::like<decltype(self)>(self._value.*member);
			}
		}

		constexpr void reset() & noexcept {
			if (xte::exchange(this->_has_value, false)) {
				xte::destroy(this->_value);
			}
		}

		constexpr auto replace(auto&&... args) & XTE_RETURNS(
			this->reset(),
			xte::construct(this->_value, XTE_FWD(args)...),
			void(this->_has_value = true)
		)

		[[nodiscard]] constexpr auto and_then(this auto&& self, auto&& func) XTE_RETURNS(
			self ? XTE_FWD(func)(XTE_FWD(self)._value) : decltype(XTE_FWD(func)(XTE_FWD(self)._value))()
		)

		[[nodiscard]] constexpr auto or_else(this auto&& self, xte::is_callable<item_type()> auto&& func) XTE_RETURNS(
			self._has_value ? XTE_FWD(self)._value : XTE_FWD(func)()
		)
	};

	template<typename item_type>
	opt(item_type&&) -> opt<xte::drop_cvref<item_type>>;
}

#endif
