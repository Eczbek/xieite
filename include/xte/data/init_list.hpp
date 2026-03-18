#ifndef DETAIL_XTE_HEADER_DATA_INIT_LIST
#	define DETAIL_XTE_HEADER_DATA_INIT_LIST
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_copy_constructible.hpp"
#	include "../trait/is_move_constructible.hpp"
#	include "../trait/is_noex_copy_constructible.hpp"
#	include "../trait/is_noex_move_constructible.hpp"
#	include "../util/address.hpp"
#	include "../util/xvalue.hpp"
#	include <initializer_list>

namespace DETAIL_XTE {
	template<typename T>
	struct init_list {
	private:
		mutable T _value;

	public:
		[[nodiscard]] explicit(false) constexpr init_list(const T& x)
		noexcept(xte::is_noex_copy_constructible<T>)
		requires(xte::is_copy_constructible<T>)
		: _value(x) {}

		[[nodiscard]] explicit(false) constexpr init_list(T&& x)
		noexcept(xte::is_noex_move_constructible<T>)
		requires(xte::is_move_constructible<T>)
		: _value(xte::xvalue(x)) {}

		XTE_ARROW_CAST([[nodiscard]] explicit(false) constexpr, auto&& self,
			XTE_FWD(self)._value
		)

		[[nodiscard]] constexpr auto* operator->(this auto&& self) noexcept {
			return xte::address(self._value);
		}
	};
}

namespace xte {
	template<typename T>
	using init_list = std::initializer_list<DETAIL_XTE::init_list<T>>;
}

#endif
