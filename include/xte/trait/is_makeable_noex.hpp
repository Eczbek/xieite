#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MAKEABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_MAKEABLE_NOEX
#
#	include "../meta/fake.hpp"
#	include "../util/make.hpp"

namespace xte {
	template<typename to_type, typename... arg_types>
	concept is_makeable_noex = requires { { xte::make<to_type>(xte::fake<arg_types>()...) } noexcept; };
}

#endif
