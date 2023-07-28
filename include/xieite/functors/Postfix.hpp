#ifndef XIEITE_HEADER_FUNCTORS_POSTFIX
#	define XIEITE_HEADER_FUNCTORS_POSTFIX

#	include "../concepts/Functable.hpp"

namespace xieite::functors {
	template<typename Type, xieite::concepts::Functable<Type> auto>
	struct Postfix;

	template<typename Result, typename LeftParameter, xieite::concepts::Functable<Result(LeftParameter)> auto callback>
	struct Postfix<Result(LeftParameter), callback> {
		friend constexpr Result operator<(const LeftParameter& leftArgument, const xieite::functors::Postfix<Result(LeftParameter), callback>&) {
			return callback(leftArgument);
		}
	};
}

#endif
