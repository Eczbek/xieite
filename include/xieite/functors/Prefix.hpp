#ifndef XIEITE_HEADER__FUNCTORS__PREFIX
#	define XIEITE_HEADER__FUNCTORS__PREFIX

#	include "../concepts/Functable.hpp"

namespace xieite::functors {
	template<typename Type, xieite::concepts::Functable<Type> auto>
	struct Prefix;

	template<typename Result, typename RightParameter, xieite::concepts::Functable<Result(RightParameter)> auto callback>
	struct Prefix<Result(RightParameter), callback> {
		constexpr Result operator>(const RightParameter& rightArgument) const {
			return callback(rightArgument);
		}
	};
}

#endif
