#ifndef DETAIL_XTE_HEADER_UTIL_RECONSTRUCT
#	define DETAIL_XTE_HEADER_UTIL_RECONSTRUCT
#
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_noex_constructible.hpp"
#	include "../util/construct.hpp"
#	include "../util/destroy.hpp"

namespace xte {
	template<typename object_type, typename... arg_types>
	requires(xte::is_noex_constructible<object_type, arg_types...>)
	constexpr auto reconstruct(object_type& object, arg_types&&... args) XTE_RETURNS(
		xte::destroy(object),
		xte::construct(object, XTE_FWD(args)...)
	)
}

#endif
