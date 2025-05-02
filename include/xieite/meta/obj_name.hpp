#ifndef DETAIL_XIEITE_HEADER_META_OBJ_NAME
#	define DETAIL_XIEITE_HEADER_META_OBJ_NAME
#
#	include <string_view>
#	include "../meta/type_name.hpp"
#	include "../pp/signature.hpp"

namespace DETAIL_XIEITE::obj_name {
	template<auto _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return DETAIL_XIEITE::type_name::parse(XIEITE_SIGNATURE);
	}
}

namespace xieite {
	template<auto x>
	constexpr std::string_view obj_name = DETAIL_XIEITE::obj_name::get<x>();
}

#endif
