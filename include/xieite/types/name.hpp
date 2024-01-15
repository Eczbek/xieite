#ifndef XIEITE_HEADER_TYPES_NAME
#	define XIEITE_HEADER_TYPES_NAME

#	include <source_location>
#	include <string_view>
#	include "../strings/between.hpp"

namespace XIEITE_INTERNAL_TYPES_NAME {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(std::source_location::current().function_name(), "= ", ";");
	}
}

namespace xieite::types {
	template<typename Type>
	inline constexpr std::string_view name = XIEITE_INTERNAL_TYPES_NAME::name<Type>();
}

#endif
