#ifndef XIEITE_HEADER_STREAMS_READ
#	define XIEITE_HEADER_STREAMS_READ

#	include <istream>
#	include <iterator>
#	include <string>

namespace xieite::streams {
	inline std::string read(std::istream& inputStream) noexcept {
		return std::string(std::istreambuf_iterator<char>(inputStream), std::istreambuf_iterator<char>());
	}
}

#endif
