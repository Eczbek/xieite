#ifndef XIEITE_HEADER_FUNCTORS_RECURSIVELY_DISTRIBUTE_ARGUMENTS
#	define XIEITE_HEADER_FUNCTORS_RECURSIVELY_DISTRIBUTE_ARGUMENTS

#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include <utility>
#	include "../concepts/invocable_with_argument_count.hpp"
#	include "../concepts/no_throw_invocable_with_argument_count.hpp"
#	include "../containers/splice_tuple.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<std::size_t argumentCount_, std::size_t previousResultIndex_ = 0, xieite::concepts::InvocableWithArgumentCount<argumentCount_> Functor_, typename... Arguments_>
	requires((argumentCount_ > previousResultIndex_) && (argumentCount_ <= sizeof...(Arguments_)) && ((argumentCount_ == 1) || (argumentCount_ > 1) && !((sizeof...(Arguments_) - 1) % (argumentCount_ - 1))))
	constexpr decltype(auto) recursivelyDistributeArguments(Functor_&& functor, Arguments_&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocableWithArgumentCount<Functor_, argumentCount_>) {
		if constexpr (sizeof...(Arguments_) == argumentCount_) {
			return std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...);
		} else {
			const std::tuple<Arguments_&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			return ([&functor, resultsTuple = xieite::containers::spliceTuple<previousResultIndex_ + argumentCount_>(argumentsTuple, std::forward_as_tuple(std::apply(functor, xieite::containers::spliceTuple<argumentCount_, sizeof...(Arguments_) - argumentCount_>(argumentsTuple))))]<std::size_t... i_>(std::index_sequence<i_...>) -> decltype(auto) {
				return xieite::functors::recursivelyDistributeArguments<argumentCount_, previousResultIndex_>(XIEITE_FORWARD(functor), std::get<i_ + argumentCount_>(std::move(resultsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments_) - argumentCount_ + 1>());
		}
	}
}

#endif
