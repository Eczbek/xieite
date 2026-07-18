#ifndef DETAIL_XTE_HEADER_TRAIT_IS_BRACE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_BRACE_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_brace_constructible = requires { T { xte::fake<arg_types>()... }; };
}

#endif
