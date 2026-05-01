#ifndef DETAIL_XTE_HEADER_SYS_DETECT_COSMIC_RAY
#	define DETAIL_XTE_HEADER_SYS_DETECT_COSMIC_RAY
#
#	include "../data/ptr.hpp"
#	include "../sys/available_memory.hpp"
#	include "../util/numbers.hpp"

namespace xte {
	inline void detect_cosmic_ray() noexcept(false) {
		xte::uz size = xte::available_memory() / sizeof(xte::umax);
		auto detector = xte::ptr<volatile xte::umax[]>::make_default(size);
		for (xte::uz i = 0; !detector[++i %= size];);
	}
}

#endif
