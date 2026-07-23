#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_RVALUE_REF
#
#	include "../trait/copy_rvalue_ref.hpp"
#	include "../trait/copy_volatile.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_volatile_rvalue_ref = xte::copy_rvalue_ref<T, xte::copy_volatile<T, U>>;
}

#endif
