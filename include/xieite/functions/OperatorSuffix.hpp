#ifndef XIEITE_HEADER_FUNCTIONS_SUFFIX
#	define XIEITE_HEADER_FUNCTIONS_SUFFIX

#	include <functional>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename, auto>
	struct OperatorSuffix;

	template<typename Result, typename LeftParameter, xieite::concepts::Functional<Result(LeftParameter)> auto callback>
	struct OperatorSuffix<Result(LeftParameter), callback> {
		friend constexpr Result operator<(const LeftParameter& leftArgument, const xieite::functions::OperatorSuffix<Result(LeftParameter), callback>&) {
			return callback(leftArgument);
		}
	};
}

#endif
