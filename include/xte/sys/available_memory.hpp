#ifndef DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#	define DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#
#	include "../aliases.hpp"
#	include "../diagnostic.hpp"
#	include "../math/exp_search.hpp"
#	include "../ptr.hpp"

XTE_DIAGNOSTIC_PUSH((NO_OBJECT_SIZE))

namespace xte {
	[[nodiscard]] constexpr xte::uz available_memory() noexcept {
		return xte::exp_search<xte::uz>(([](xte::uz size) {
			return !!xte::ptr<char[]>::make_default_noex(size + 1);
		}));
	}
}

XTE_DIAGNOSTIC_POP()

#endif
