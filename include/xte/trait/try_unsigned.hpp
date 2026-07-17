#ifndef DETAIL_XTE_HEADER_TRAIT_TRY_UNSIGNED
#	define DETAIL_XTE_HEADER_TRAIT_TRY_UNSIGNED
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/is_signed.hpp"
#	include <type_traits>

namespace xte {
	template<typename T>
	using try_unsigned = [:xte::is_signed<T> ? ^^std::make_unsigned<T> : ^^xte::wrap_type<T>:]::type;
}

#endif
