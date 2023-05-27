#ifndef XIEITE_HEADER_FUNCTIONS_PREFIX
#	define XIEITE_HEADER_FUNCTIONS_PREFIX

#	include <functional>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename, auto>
	struct Prefix;

	template<typename Result, typename RightParameter, xieite::concepts::Functional<Result(RightParameter)> auto callback>
	struct Prefix<Result(RightParameter), callback> final {
		constexpr Result operator>(const RightParameter& rightArgument) const {
			return callback(rightArgument);
		}
	};
}

#endif
