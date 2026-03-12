#ifndef DETAIL_XTE_HEADER_DATA_INIT_LIST
#	define DETAIL_XTE_HEADER_DATA_INIT_LIST
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/address.hpp"
#	include <initializer_list>

namespace DETAIL_XTE {
	template<typename T>
	struct init_list {
	private:
		mutable T _value;

	public:
		[[nodiscard]] explicit(false) constexpr init_list(auto&& arg) XTE_ARROW_CTOR(,
			_value,((XTE_FWD(arg)))
		)

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
