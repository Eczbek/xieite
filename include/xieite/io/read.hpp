#ifndef DETAIL_XIEITE_HEADER_IO_READ
#	define DETAIL_XIEITE_HEADER_IO_READ
#
#	include <cstddef>
#	include <cstdio>
#	include <istream>
#	include <iterator>
#	include <string>

namespace xieite {
	[[nodiscard]] inline std::string read(std::istream& stream) noexcept {
		return std::string(std::istreambuf_iterator<char>(stream), {});
	}

	[[nodiscard]] inline std::string read(std::FILE* stream) noexcept {
		std::string result;
		while (stream) {
			const std::size_t orig_size = result.size();
			const std::size_t next_size = orig_size ? (orig_size * 2) : 8192;
			result.resize_and_overwrite(
				next_size,
				[stream, orig_size](char* buf, std::size_t buf_size) -> std::size_t {
					return orig_size + std::fread(buf + orig_size, 1, buf_size - orig_size, stream);
				}
			);
			if (result.size() != next_size) {
				break;
			}
		}
		return result;
	}
}

#endif

// https://vitaut.net/posts/2020/optimal-file-buffer-size/
