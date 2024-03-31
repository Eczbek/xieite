#ifndef XIEITE_HEADER_ERRORS_TYPE
#	define XIEITE_HEADER_ERRORS_TYPE

namespace xieite::errors {
	enum struct Type {
		AllResultsExcluded,
		DimensionsMismatch,
		DivisionByZero,
		IndexOutOfRange,
		InvalidNetworkAddress,
		KeyOutOfMap,
		SkillIssue,
		UnrepresentableValue
	};
}

#endif
