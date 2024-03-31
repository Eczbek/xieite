#ifndef XIEITE_HEADER_ERRORS_STRINGIFY
#	define XIEITE_HEADER_ERRORS_STRINGIFY

#	include <string_view>
#	include "../errors/type.hpp"

namespace xieite::erros {
	[[nodiscard]] constexpr std::string_view stringify(const xieite::errors::Type error) noexcept {
		switch (error) {
		case xieite::errors::Type::AllResultsExcluded:
			return "All possible results excluded";
		case xieite::errors::Type::DimensionsMismatch:
			return "Dimensions do not match";
		case xieite::errors::Type::DivisionByZero:
			return "Division by zero";
		case xieite::errors::Type::IndexOutOfRange:
			return "Range does not contain index";
		case xieite::errors::Type::InvalidNetworkAddress:
			return "Invalid network address";
		case xieite::errors::Type::KeyOutOfMap:
			return "Map does not contain key";
		case xieite::errors::Type::SkillIssue:
			return "Skill issue";
		case xieite::errors::Type::UnrepresentableValue:
			return "Unrepresentable value";
		}
	}
}

#endif
