#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE_WITH_ARGUMENT_COUNT
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE_WITH_ARGUMENT_COUNT

#	include <cstddef>
#	include <type_traits>
#	include "../types/list.hpp"
#	include "../types/placeholder.hpp"

namespace xieite::concepts {
	template<typename Functor, std::size_t argumentCount>
	concept NoThrowInvocableWithArgumentCount = xieite::types::List<xieite::types::Placeholder>::Repeat<argumentCount>::template Prepend<Functor>::template Apply<std::is_nothrow_invocable>::value;
}

#endif
