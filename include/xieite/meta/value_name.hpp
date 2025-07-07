#ifndef DETAIL_XIEITE_HEADER_META_VALUE_NAME
#	define DETAIL_XIEITE_HEADER_META_VALUE_NAME
#
#	include <string_view>
#	include "../meta/type_name.hpp"
#	include "../pp/signature.hpp"

namespace DETAIL_XIEITE::value_name {
	template<auto _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return DETAIL_XIEITE::type_name::parse(XIEITE_SIGNATURE);
	}
}

namespace xieite {
	template<auto x>
	constexpr std::string_view value_name = DETAIL_XIEITE::value_name::get<x>();
}

#endif
