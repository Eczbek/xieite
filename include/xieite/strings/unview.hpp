#ifndef XIEITE_HEADER_STRINGS_UNVIEW
#	define XIEITE_HEADER_STRINGS_UNVIEW

#	include <string>
#	include "../concepts/string_view.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView>
	using Unview = std::basic_string<typename StringView::value_type, typename StringView::traits_type>;
}

#endif
