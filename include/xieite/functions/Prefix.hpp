#ifndef XIEITE_HEADER_FUNCTIONS_PREFIX
#	define XIEITE_HEADER_FUNCTIONS_PREFIX

#	include <xieite/concepts/Functable.hpp>

namespace xieite::functions {
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
