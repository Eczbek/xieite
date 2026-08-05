#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MAKEABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_MAKEABLE
#
#	include "../meta/fake.hpp"
#	include "../util/make.hpp"

namespace xte {
	template<typename to_type, typename... arg_types>
	concept is_makeable = requires { xte::make<to_type>(xte::fake<arg_types>()...); };
}

#endif
