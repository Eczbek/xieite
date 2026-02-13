#ifndef DETAIL_XTE_HEADER_DATA_OPT
#	define DETAIL_XTE_HEADER_DATA_OPT
#
#	include "../data/null.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_callable.hpp"
#	include "../trait/is_same_ignore_cvref.hpp"
#	include "../trait/remove_cvref.hpp"
#	include "../util/address.hpp"
#	include "../util/construct.hpp"
#	include "../util/xvalue.hpp"

namespace xte {
	template<typename T>
	struct opt {
	private:
		union {
			char _empty = {};
			T _value;
		};
		bool _has_value = false;

	public:
		[[nodiscard]] explicit(false) constexpr opt() noexcept = default;

		[[nodiscard]] explicit(false) constexpr opt(decltype(xte::null)) noexcept {}

		[[nodiscard]] explicit(false) constexpr opt(auto&&... args) XTE_ARROW_CTOR(,
			_value,((XTE_FWD(args)...)),
			_has_value,((true))
		)

		constexpr auto&& emplace(this auto&& self, auto&&... args)
		noexcept(noexcept(T(XTE_FWD(args)...)))
		requires(requires { T(XTE_FWD(args)...); }) {
			self = xte::null;
			xte::construct(self._value, XTE_FWD(args)...);
			self._has_value = true;
			return XTE_FWD(self);
		}

		[[nodiscard]] explicit(false) constexpr opt(const xte::opt<T>& other)
		noexcept(noexcept(T(other._value)))
		requires(requires { T(other._value); })
		{ other && this->emplace(other._value); }

		[[nodiscard]] explicit(false) constexpr opt(xte::opt<T>&& other)
		noexcept(noexcept(T(xte::xvalue(other._value))))
		requires(requires { T(xte::xvalue(other._value)); })
		{ other && this->emplace(xte::xvalue(other._value)); }

		constexpr ~opt() {
			if (this->_has_value) {
				this->_value.~T();
			}
		}

		constexpr auto operator=(const xte::opt<T>& other) & XTE_ARROW(
			this->_has_value ? this->_value.~T() : void(),
			(this->_has_value = other._has_value) ? void(this->_value = other._value) : void(),
			*this
		)

		constexpr auto operator=(xte::opt<T>&& other) & XTE_ARROW(
			this->_has_value ? this->_value.~T() : void(),
			(this->_has_value = other._has_value) ? void(this->_value = xte::xvalue(other)._value) : void(),
			*this
		)

		constexpr auto operator=(auto&& x) & XTE_ARROW(
			void(this->_value = XTE_FWD(x)),
			void(this->_has_value = true),
			*this
		)

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return this->_has_value;
		}

		[[nodiscard]] constexpr auto&& operator*(this auto&& self) noexcept {
			return XTE_FWD(self)._value;
		}

		[[nodiscard]] constexpr auto* operator->(this auto&& self) noexcept {
			return xte::address(self._value);
		}
		
		[[nodiscard]] static constexpr auto make(auto&&... args) XTE_ARROW(
			xte::opt<T>().emplace(XTE_FWD(args)...)
		)

		[[nodiscard]] constexpr auto and_then(this auto&& self, auto&& func) XTE_ARROW(
			self ? XTE_FWD(func)(XTE_FWD(self)._value) : decltype(XTE_FWD(func)(XTE_FWD(self)._value))()
		)

		[[nodiscard]] constexpr auto or_else(xte::is_callable<T()> auto&& func) XTE_ARROW(
			this->_has_value ? this->_value : XTE_FWD(func)()
		)
	};

	template<typename T>
	opt(T&&) -> opt<xte::remove_cvref<T>>;
}

#endif
