#ifndef DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#	define DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#
#	include "../aliases.hpp"
#	include "../math/exp_search.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../ptr.hpp"

namespace xte {
	[[nodiscard]] constexpr xte::uz available_memory() noexcept {
		return xte::exp_search<xte::uz>(([](xte::uz size) {
			XTE_DIAGNOSTIC_PUSH_GCC(ON, "-Wno-larger-than")
			return xte::ptr<char[]>::make_default_noex(size + 1);
			XTE_DIAGNOSTIC_POP_GCC()
		}));
	}
}

#endif
