#ifndef XIEITE_HEADER_EXCEPTIONS_DIVISION_BY_ZERO
#	define XIEITE_HEADER_EXCEPTIONS_DIVISION_BY_ZERO

#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct DivisionByZero
	: xieite::exceptions::Unspecified {
		DivisionByZero(const std::string_view message = "") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
