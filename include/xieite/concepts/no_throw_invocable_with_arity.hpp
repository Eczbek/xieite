#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE_WITH_ARGUMENT_COUNT
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE_WITH_ARGUMENT_COUNT

#	include <cstddef>
#	include <type_traits>
#	include "../types/any.hpp"
#	include "../types/list.hpp"

namespace xieite::concepts {
	template<typename Functor_, std::size_t arity_>
	concept NoThrowInvocableWithArity = xieite::types::List<xieite::types::Any>::Repeat<arity_>::template Prepend<Functor_>::template Apply<std::is_nothrow_invocable>::value;
}

#endif
