#ifndef DETAIL_XTE_HEADER_DATA_OPT
#	define DETAIL_XTE_HEADER_DATA_OPT
#
#	include "../data/null.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/drop_cvref.hpp"
#	include "../trait/is_callable.hpp"
#	include "../util/address.hpp"
#	include "../util/assign.hpp"
#	include "../util/cast.hpp"
#	include "../util/construct.hpp"
#	include "../util/destroy.hpp"
#	include "../util/exchange.hpp"
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
			_value,((xte::cast<T>(XTE_FWD(args)...))),
			_has_value,((true))
		)

		[[nodiscard]] explicit(false) constexpr opt(const xte::opt<T>& other) XTE_ARROW_CTOR((
			other._has_value ? void(xte::construct(this->_value, other._value)) : void(),
			this->_has_value = other._has_value
		))

		[[nodiscard]] explicit(false) constexpr opt(xte::opt<T>&& other) XTE_ARROW_CTOR((
			other._has_value ? void(xte::construct(this->_value, xte::xvalue(other)._value)) : void(),
			this->_has_value = xte::exchange(other._has_value, false)
		))

		constexpr ~opt() {
			this->reset();
		}

		constexpr xte::opt<T>& operator=(const xte::opt<T>&) & noexcept = default;

		constexpr xte::opt<T>& operator=(xte::opt<T>&&) & noexcept = default;

		constexpr auto operator=(auto&& arg) & XTE_ARROW(
			this->_has_value ? void(xte::assign(this->_value, XTE_FWD(arg))) : void(xte::construct(this->_value, XTE_FWD(arg))),
			this->_has_value = true,
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

		constexpr void reset() & noexcept {
			if (xte::exchange(this->_has_value, false)) {
				xte::destroy(this->_value);
			}
		}

		constexpr auto reset(auto&&... args) & XTE_ARROW(
			this->reset(),
			xte::construct(this->_value, XTE_FWD(args)...),
			void(this->_has_value = true)
		)

		[[nodiscard]] constexpr auto and_then(this auto&& self, auto&& func) XTE_ARROW(
			self ? XTE_FWD(func)(XTE_FWD(self)._value) : decltype(XTE_FWD(func)(XTE_FWD(self)._value))()
		)

		[[nodiscard]] constexpr auto or_else(this auto&& self, xte::is_callable<T()> auto&& func) XTE_ARROW(
			self._has_value ? XTE_FWD(self)._value : XTE_FWD(func)()
		)
	};

	template<typename T>
	opt(T&&) -> opt<xte::drop_cvref<T>>;
}

#endif
