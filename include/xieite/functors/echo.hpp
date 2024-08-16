#ifndef XIEITE_HEADER_FUNCTORS_ECHO
#	define XIEITE_HEADER_FUNCTORS_ECHO

#	include "../macros/forward.hpp"

namespace xieite::functors {
	struct Echo {
		template<typename Type>
		[[nodiscard]] constexpr decltype(auto) operator()(Type&& value) const noexcept {
			return XIEITE_FORWARD(value);
		}
	};
}

#endif
