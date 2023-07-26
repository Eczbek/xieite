#ifndef XIEITE_HEADER_FUNCTORS_PREFIX
#	define XIEITE_HEADER_FUNCTORS_PREFIX

#	include <xieite/concepts/Functable.hpp>

namespace xieite::functors {
	template<typename Type, xieite::concepts::Functable<Type> auto>
	struct Prefix;

	template<typename Result, typename RightParameter, auto callback>
	struct Prefix<Result(RightParameter), callback> {
		constexpr Result operator>(const RightParameter& rightArgument) const {
			return callback(rightArgument);
		}
	};
}

#endif
