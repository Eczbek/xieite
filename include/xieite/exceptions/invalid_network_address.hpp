#ifndef XIEITE_HEADER_EXCEPTIONS_INVALID_NETWORK_ADDRESS
#	define XIEITE_HEADER_EXCEPTIONS_INVALID_NETWORK_ADDRESS

#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct InvalidNetworkAddress
	: xieite::exceptions::Unspecified {
		constexpr InvalidNetworkAddress(const std::string_view message = "") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
