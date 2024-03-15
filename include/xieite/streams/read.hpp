#ifndef XIEITE_HEADER_STREAMS_READ
#	define XIEITE_HEADER_STREAMS_READ

#	include <istream>
#	include <iterator>
#	include <string>

namespace xieite::streams {
	inline std::string read(std::istream& inputStream) noexcept {
		using Iterator = std::istreambuf_iterator<char>;
		return std::string(Iterator(inputStream), Iterator());
	}
}

#endif
