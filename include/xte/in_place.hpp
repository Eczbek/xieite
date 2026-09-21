#ifndef DETAIL_XTE_HEADER_IN_PLACE
#	define DETAIL_XTE_HEADER_IN_PLACE
#
#	include "./address.hpp"
#	include "./make.hpp"
#	include "./preproc/fwd.hpp"
#	include "./preproc/returns.hpp"
#	include "./trait/is_constructible_noex.hpp"
#	include <new>

namespace xte {
	template<typename object_type>
	constexpr auto construct(object_type& object, auto&&... args) XTE_RETURNS(
		*::new(xte::address(object)) object_type(xte::make<object_type>(XTE_FWD(args)...))
	)

	template<typename object_type>
	constexpr auto destroy(object_type& object) XTE_RETURNS(
		object.~object_type()
	)

	template<typename object_type, typename... arg_types>
	requires(xte::is_constructible_noex<object_type, arg_types...>)
	constexpr auto reconstruct(object_type& object, arg_types&&... args) XTE_RETURNS(
		xte::destroy(object),
		xte::construct(object, XTE_FWD(args)...)
	)
}

#endif
