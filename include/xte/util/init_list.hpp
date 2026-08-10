#ifndef DETAIL_XTE_HEADER_UTIL_INIT_LIST
#	define DETAIL_XTE_HEADER_UTIL_INIT_LIST
#
#	include "../preproc/constructs.hpp"
#	include "../preproc/define_cast.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/drop_const.hpp"
#	include "../trait/is_constructible_implicit.hpp"
#	include "../util/address.hpp"
#	include "../util/as_xvalue.hpp"
#	include "../util/make.hpp"
#	include <initializer_list>

namespace DETAIL_XTE::init_list {
	template<typename arg_type>
	struct explicit_cast {
		arg_type&& arg;

		template<xte::is_constructible_implicit<arg_type> item_type>
		[[nodiscard]] explicit(false) constexpr operator item_type() const XTE_RETURNS_FIXED(
			xte::make<item_type>(XTE_FWD(this->arg))
		)
	};

	template<typename item_type>
	struct impl {
	private:
		mutable item_type _value;

	public:
		[[nodiscard]] explicit(false) constexpr impl(const item_type& arg) XTE_CONSTRUCTS(,
			_value,((arg))
		)

		[[nodiscard]] explicit(false) constexpr impl(item_type&& arg) XTE_CONSTRUCTS(,
			_value,((xte::as_xvalue(arg)))
		)

		[[nodiscard]] explicit(false) constexpr impl(auto&&... args) XTE_CONSTRUCTS(,
			_value,((explicit_cast<decltype(args)>(XTE_FWD(args))...))
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
	template<typename item_type>
	using init_list = std::initializer_list<DETAIL_XTE::init_list::impl<xte::drop_const<item_type>>>;
}

#endif
