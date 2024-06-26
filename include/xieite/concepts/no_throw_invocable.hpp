#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Functor_, typename... Arguments_>
	concept NoThrowInvocable = std::is_nothrow_invocable_v<Functor_, Arguments_...>;
}

#endif
