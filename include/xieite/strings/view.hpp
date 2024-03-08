#ifndef XIEITE_HEADER_STRINGS_VIEW
#	define XIEITE_HEADER_STRINGS_VIEW

#	include <string_view>
#	include "../concepts/string.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String>
	using View = std::basic_string_view<String::value_type, String::traits_type>;
}

#endif
