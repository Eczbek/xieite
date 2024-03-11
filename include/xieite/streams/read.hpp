#ifndef XIEITE_HEADER_STREAMS_READ
#	define XIEITE_HEADER_STREAMS_READ

#	include <istream>
#	include <iterator>
#	include <string>
#	include "../concepts/string.hpp"

namespace xieite::streams {
	template<xieite::concepts::String String = std::string>
	String read(std::istream& inputStream) noexcept {
		using Iterator = std::istreambuf_iterator<typename String::value_type>;
		return String(Iterator(inputStream), Iterator());
	}
}

#endif
