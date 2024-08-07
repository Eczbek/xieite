#ifndef XIEITE_HEADER_FUNCTORS_ECHO
#	define XIEITE_HEADER_FUNCTORS_ECHO

#	include "../macros/forward.hpp"

namespace xieite::functors {
	struct Echo {
		template<typename Type_>
		[[nodiscard]] constexpr decltype(auto) operator()(Type_&& value) const noexcept {
			return XIEITE_FORWARD(value);
		}
	};
}

#endif
