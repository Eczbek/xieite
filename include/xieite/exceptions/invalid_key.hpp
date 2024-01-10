#ifndef XIEITE_HEADER_EXCEPTIONS_INVALID_KEY
#	define XIEITE_HEADER_EXCEPTIONS_INVALID_KEY

#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct InvalidKey
	: xieite::exceptions::Unspecified {
		constexpr InvalidKey(const std::string_view message = "") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
