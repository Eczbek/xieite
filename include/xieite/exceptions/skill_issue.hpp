#ifndef XIEITE_HEADER_EXCEPTIONS_SKILL_ISSUE
#	define XIEITE_HEADER_EXCEPTIONS_SKILL_ISSUE

#	include <string>
#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct SkillIssue
	: xieite::exceptions::Unspecified {
		SkillIssue(const std::string_view message = "cope") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
