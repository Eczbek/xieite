#ifndef XIEITE_HEADER_FUNCTIONS_SUFFIX
#	define XIEITE_HEADER_FUNCTIONS_SUFFIX

#	include <functional>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename, auto>
	struct Suffix;

	template<typename Result, typename LeftParameter, xieite::concepts::Functional<Result(LeftParameter)> auto callback>
	struct Suffix<Result(LeftParameter), callback> final {
		friend constexpr Result operator<(const LeftParameter& leftArgument, const xieite::functions::Suffix<Result(LeftParameter), callback>&) {
			return callback(leftArgument);
		}
	};
}

#endif
