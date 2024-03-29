#ifndef XIEITE_HEADER_EXCEPTIONS_UNREPRESENTABLE_VALUE
#	define XIEITE_HEADER_EXCEPTIONS_UNREPRESENTABLE_VALUE

#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct UnrepresentableValue
	: xieite::exceptions::Unspecified {
		UnrepresentableValue(const std::string_view message = "") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
