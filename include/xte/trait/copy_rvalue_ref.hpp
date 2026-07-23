#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_RVALUE_REF
#
#	include "../trait/add_rvalue_ref.hpp"
#	include "../trait/drop_ref.hpp"
#	include "../trait/drop_rvalue_ref.hpp"
#	include "../trait/is_rvalue_ref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_rvalue_ref = [:xte::is_rvalue_ref<T> ? ^^xte::add_rvalue_ref<xte::drop_ref<U>> : ^^xte::drop_rvalue_ref<U>:];
}

#endif
