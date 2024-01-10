#ifndef XIEITE_HEADER_EXCEPTIONS_UNSET_FUNCTOR_INVOKED
#	define XIEITE_HEADER_EXCEPTIONS_UNSET_FUNCTOR_INVOKED

#	include <string_view>
#	include "../exceptions/unspecified.hpp"

namespace xieite::exceptions {
	struct UnsetFunctorInvoked
	: xieite::exceptions::Unspecified {
		constexpr UnsetFunctorInvoked(const std::string_view message = "") noexcept
		: xieite::exceptions::Unspecified(message) {}
	};
}

#endif
