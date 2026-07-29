#ifndef DETAIL_XTE_HEADER_TRAIT_PTR_DEPTH
#	define DETAIL_XTE_HEADER_TRAIT_PTR_DEPTH
#
#	include "../util/number_types.hpp"
#	include <meta>

namespace xte {
	template<typename T>
	constexpr xte::uz ptr_depth = ([] {
		auto type = std::meta::remove_reference(^^T);
		xte::uz depth = 0;
		while (std::meta::is_pointer_type(type)) {
			type = std::meta::remove_pointer(type);
			++depth;
		}
		return depth;
	})();
}

#endif
