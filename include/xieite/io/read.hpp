#ifndef DETAIL_XIEITE_HEADER_IO_READ
#	define DETAIL_XIEITE_HEADER_IO_READ
#
#	include <cstddef>
#	include <cstdio>
#	include <istream>
#	include <iterator>
#	include <string>

namespace xieite {
	[[nodiscard]] inline std::string read(std::istream& stream, int delim = EOF) noexcept {
		if (delim == EOF) {
			return std::string(std::istreambuf_iterator<char>(stream), {});
		}
		std::string input;
		std::getline(stream, input, static_cast<char>(delim));
		return input;
	}

	[[nodiscard]] inline std::string read(std::FILE* stream, int delim = EOF) noexcept {
		std::string input;
		while (stream) {
			const std::size_t prev_size = input.size();
			const std::size_t next_size = prev_size + 32768;
			input.resize_and_overwrite(
				next_size,
				[stream, delim, prev_size](char* buf, std::size_t buf_size) -> std::size_t {
					if (delim == EOF) {
						return prev_size + std::fread(buf + prev_size, 1, buf_size - prev_size, stream);
					}
					int input;
					std::size_t count = prev_size;
					while ((input = std::fgetc(stream)) != delim) {
						buf[count++] = static_cast<char>(input);
					}
					return count;
				}
			);
			if (input.size() != next_size) {
				break;
			}
		}
		return input;
	}
}

#endif

// https://vitaut.net/posts/2020/optimal-file-buffer-size/
