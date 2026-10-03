#ifndef DETAIL_XTE_HEADER_INIT_LIST
#	define DETAIL_XTE_HEADER_INIT_LIST
#
#	include "./address.hpp"
#	include "./class_traits.hpp"
#	include "./macros.hpp"
#	include "./make.hpp"
#	include "./qual_traits.hpp"
#	include <initializer_list>

namespace DETAIL_XTE::init_list {
	template<typename arg_type>
	struct explicit_cast {
		arg_type&& arg;

		template<xte::is_implicitly_constructible<arg_type> item_type>
		[[nodiscard]] constexpr explicit(false) operator item_type() const XTE_RETURNS_FIXED(
			xte::make<item_type>(XTE_FWD(this->arg))
		)
	};

	template<typename item_type>
	struct impl {
	private:
		mutable item_type _value;

	public:
		[[nodiscard]] constexpr explicit(false) impl(item_type const& arg) XTE_CONSTRUCTS(
			(_value,(arg))
		)

		[[nodiscard]] constexpr explicit(false) impl(item_type&& arg) XTE_CONSTRUCTS(
			(_value,(xte::as_xvalue(arg)))
		)

		[[nodiscard]] constexpr explicit(false) impl(auto&&... args) XTE_CONSTRUCTS(
			(_value,(DETAIL_XTE::init_list::explicit_cast<decltype(args)>(XTE_FWD(args))...))
		)

		XTE_DEFINE_CAST([[nodiscard]] constexpr explicit(false), auto&& self,
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
