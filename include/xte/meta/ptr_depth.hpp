#ifndef DETAIL_XTE_HEADER_TRAIT_PTR_DEPTH
#	define DETAIL_XTE_HEADER_TRAIT_PTR_DEPTH
#
#	include "../trait/is_ptr.hpp"
#	include "../trait/remove_ptr.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<typename T>
	constexpr xte::uz ptr_depth = ([]<typename U = T>(this auto self) -> xte::uz {
		if constexpr (xte::is_ptr<U>) {
			return 1 + self.template operator()<xte::remove_ptr<U>>();
		} else {
			return 0;
		}
	})();
}

#endif
