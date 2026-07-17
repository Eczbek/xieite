#ifndef DETAIL_XTE_HEADER_TRAIT_TRY_SIGNED
#	define DETAIL_XTE_HEADER_TRAIT_TRY_SIGNED
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/is_unsigned.hpp"
#	include <type_traits>

namespace xte {
	template<typename T>
	using try_signed = [:xte::is_unsigned<T> ? ^^std::make_signed<T> : ^^xte::wrap_type<T>:]::type;
}

#endif
