#ifndef XIEITE_HEADER_FUNCTIONS_SUFFIX
#	define XIEITE_HEADER_FUNCTIONS_SUFFIX

#	include <xieite/concepts/Functable.hpp>

namespace xieite::functions {
	template<typename Type, xieite::concepts::Functable<Type> auto>
	struct Suffix;

	template<typename Result, typename LeftParameter, auto callback>
	struct Suffix<Result(LeftParameter), callback> {
		friend constexpr Result operator<(const LeftParameter& leftArgument, const xieite::functions::Suffix<Result(LeftParameter), callback>&) {
			return callback(leftArgument);
		}
	};
}

#endif
