#ifndef XIEITE_HEADER_STREAMS_READ
#	define XIEITE_HEADER_STREAMS_READ

#	include <cstddef>
#	include <cstdio>
#	include <istream>
#	include <iterator>
#	include <string>

namespace xieite::streams {
	inline std::string read(std::istream& inputStream) noexcept {
		using Iterator = std::istreambuf_iterator<char>;
		return std::string(Iterator(inputStream), Iterator());
	}

	inline std::string read(std::FILE* const inputFile) noexcept {
		std::string result;
		std::size_t chunkSize = 1024;
		while (true) {
			std::string buffer = std::string(chunkSize, '\0');
			const std::size_t bytesRead = std::fread(buffer.data(), 1, chunkSize, inputFile);
			result += buffer;
			if (bytesRead != chunkSize) {
				break;
			}
			chunkSize *= 2;
		}
		return result;
	}
}

#endif

// TODO: Research best initial chunk size
