#ifndef DETAIL_XTE_HEADER_UTIL_INIT_LIST
#	define DETAIL_XTE_HEADER_UTIL_INIT_LIST
#
#	include "../preproc/constructs.hpp"
#	include "../preproc/define_cast.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/drop_const.hpp"
#	include "../util/address.hpp"
#	include "../util/as_xvalue.hpp"
#	include <initializer_list>

namespace DETAIL_XTE::init_list {
	template<typename T>
	struct impl {
	private:
		mutable T _value;

	public:
		[[nodiscard]] explicit(false) constexpr impl(const T& x) XTE_CONSTRUCTS(,
			_value,((x))
		)

		[[nodiscard]] explicit(false) constexpr impl(T&& x) XTE_CONSTRUCTS(,
			_value,((xte::as_xvalue(x)))
		)

		[[nodiscard]] explicit(false) constexpr impl(auto&&... args) XTE_CONSTRUCTS(,
			_value,({ XTE_FWD(args)... })
		)

		XTE_DEFINE_CAST([[nodiscard]] explicit(false) constexpr, auto&& self,
			XTE_FWD(self)._value
		)

		[[nodiscard]] constexpr auto* operator->(this auto&& self) noexcept {
			return xte::address(self._value);
		}
	};
}

namespace xte {
	template<typename T>
	using init_list = std::initializer_list<DETAIL_XTE::init_list::impl<xte::drop_const<T>>>;
}

#endif
