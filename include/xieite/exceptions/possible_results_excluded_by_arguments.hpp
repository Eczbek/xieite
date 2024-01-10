#ifndef XIEITE_HEADER_EXCEPTIONS_POSSIBLE_RESULTS_EXCLUDED_BY_ARGUMENTS
#	define XIEITE_HEADER_EXCEPTIONS_POSSIBLE_RESULTS_EXCLUDED_BY_ARGUMENTS

#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct PossibleResultsExcludedByArguments
	: xieite::exceptions::Unspecified {
		constexpr PossibleResultsExcludedByArguments(const std::string_view message = "") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
