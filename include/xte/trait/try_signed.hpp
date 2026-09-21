#ifndef DETAIL_XTE_HEADER_TRAIT_TRY_SIGNED
#	define DETAIL_XTE_HEADER_TRAIT_TRY_SIGNED
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/is_unsigned_int.hpp"
#	include <type_traits>

namespace xte {
	template<typename T>
	using try_signed = [:xte::is_unsigned_int<T> ? ^^std::make_signed<T> : ^^xte::wrap_type<T>:]::type;
}

#endif
