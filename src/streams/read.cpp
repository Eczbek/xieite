export module xieite:streams.read;

import std;

export namespace xieite::streams {
	std::string read(std::istream& inputStream) noexcept {
		using Iterator = std::istreambuf_iterator<char>;
		return std::string(Iterator(inputStream), Iterator());
	}

	std::string read(std::FILE* const inputFile) noexcept {
		std::string result;
		std::size_t chunkSize = 1024;
		while (true) {
			std::string buffer = std::string(chunkSize, '\0');
			const std::size_t bytesRead = std::fread(buffer.data(), 1, chunkSize, inputFile);
			result += buffer.substr(0, bytesRead);
			if (bytesRead != chunkSize) {
				break;
			}
			chunkSize *= 2;
		}
		return result;
	}
}

// TODO: Research best initial chunk size
