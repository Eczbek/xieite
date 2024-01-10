#ifndef XIEITE_HEADER_EXCEPTIONS_INVALID_INDEX
#	define XIEITE_HEADER_EXCEPTIONS_INVALID_INDEX

#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct InvalidIndex
	: xieite::exceptions::Unspecified {
		constexpr InvalidIndex(const std::string_view message = "") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
