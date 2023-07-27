#ifndef XIEITE_HEADER_FUNCTORS_SUFFIX
#	define XIEITE_HEADER_FUNCTORS_SUFFIX

#	include "../concepts/Functable.hpp"

namespace xieite::functors {
	template<typename Type, xieite::concepts::Functable<Type> auto>
	struct Suffix;

	template<typename Result, typename LeftParameter, xieite::concepts::Functable<Result(LeftParameter)> auto callback>
	struct Suffix<Result(LeftParameter), callback> {
		friend constexpr Result operator<(const LeftParameter& leftArgument, const xieite::functors::Suffix<Result(LeftParameter), callback>&) {
			return callback(leftArgument);
		}
	};
}

#endif
