#ifndef XIEITE_HEADER_CONCEPTS_INVOCABLE_WITH_ARITY
#	define XIEITE_HEADER_CONCEPTS_INVOCABLE_WITH_ARITY

#	include <cstddef>
#	include <type_traits>
#	include "../types/any.hpp"
#	include "../types/list.hpp"

namespace xieite::concepts {
	template<typename Functor_, std::size_t arity_>
	concept InvocableWithArity = xieite::types::List<xieite::types::Any>::Repeat<arity_>::template Prepend<Functor_>::template Apply<std::is_invocable>::value;
}

#endif
