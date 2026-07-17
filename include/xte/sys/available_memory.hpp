#ifndef DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#	define DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#
#	include "../data/ptr.hpp"
#	include "../math/exp_search.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../util/number_types.hpp"

namespace xte {
	[[nodiscard]] constexpr xte::uz available_memory() noexcept {
		return xte::exp_search<xte::uz>(([](xte::uz n) {
			XTE_DIAGNOSTIC_PUSH_GCC(ON, "-Wno-larger-than")
			return xte::ptr<char[]>::make_default_noex(n + 1);
			XTE_DIAGNOSTIC_POP_GCC()
		}));
	}
}

#endif
