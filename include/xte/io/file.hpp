#ifndef DETAIL_XTE_HEADER_IO_FILE
#	define DETAIL_XTE_HEADER_IO_FILE
#
#	include "../data/ptr.hpp"
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../io/eof.hpp"
#	include "../preproc/platform.hpp"
#	include "../sys/isatty.hpp"
#	include "../util/exchange.hpp"
#	include "../util/types.hpp"
#	include <cstdio>
#	include <stdio.h>
#	include <utility>

namespace xte {
	struct file {
	public:
		enum struct mode : xte::uz {
			none = 0b0000,
			read = 0b0001,
			write = 0b0010,
			overwrite = 0b1010,
			append = 0b0100,
			read_write = 0b0011,
			read_overwrite = 0b1011,
			read_append = 0b0101
		};

		[[nodiscard]] explicit(false) file() noexcept = default;

		[[nodiscard]] file(std::FILE* stream, xte::file::mode mode) noexcept
		: _stream(stream), _mode(mode) {}

		[[nodiscard]] file(xte::string_view path, xte::file::mode mode) noexcept(false) {
			this->open(path, mode);
		}

		~file() {
			this->close();
		}

		[[nodiscard]] explicit(false) operator std::FILE*() const noexcept {
			return this->data();
		}

		[[nodiscard]] std::FILE* data() const noexcept {
			return this->_stream.data();
		}

		[[nodiscard]] std::FILE* release() noexcept {
			return xte::exchange(this->_stream, nullptr).release();
		}

		bool open(xte::string_view path, xte::file::mode mode) noexcept(false) {
			this->_mode = mode;
			return !!(this->_stream = std::fopen(xte::string(path).data(), ([mode] {
				switch (mode) {
					case xte::file::mode::read:
						return "r";
					case xte::file::mode::write:
						return "wx";
					case xte::file::mode::overwrite:
						return "w";
					case xte::file::mode::append:
						return "a";
					case xte::file::mode::read_write:
						return "r+";
					case xte::file::mode::read_overwrite:
						return "wx+";
					case xte::file::mode::read_append:
						return "a+";
					default:
						std::unreachable();
				}
			})()));
		}

		bool close() noexcept {
			return (this->_stream && !xte::isatty(*this)) && !std::fclose(this->release());
		}

		bool reopen(xte::string_view path, xte::file::mode mode) noexcept(false) {
			return this->close() && this->open(path, mode);
		}

		[[nodiscard]] bool is_readable() const noexcept {
			return *this && (std::to_underlying(this->_mode) & 0b0001);
		}

		[[nodiscard]] bool is_writable() const noexcept {
			return *this && (std::to_underlying(this->_mode) & 0b0010);
		}

		[[nodiscard]] bool is_overwritable() const noexcept {
			return *this && (std::to_underlying(this->_mode) & 0b1010);
		}

		[[nodiscard]] bool is_appendable() const noexcept {
			return *this && (std::to_underlying(this->_mode) & 0b0100);
		}

		bool write(xte::string_view content) noexcept {
			return std::fwrite(content.data(), 1, content.size(), *this) == content.size();
		}

		bool flush() noexcept {
			return !std::fflush(*this);
		}

		[[nodiscard]] xte::string read() noexcept(false) {
			static constexpr xte::uz chunk_size = 32768;
			xte::string content;
			while (true) {
				xte::uz prev_size = content.size();
				content.insert_uninit(-1uz, chunk_size);
				content.resize(prev_size + std::fread(content.data() + prev_size, 1, chunk_size, *this));
				if (content.size() != (prev_size + chunk_size)) {
					break;
				}
			}
			return content;
		}

		[[nodiscard]] xte::string read(char delim) noexcept(false) {
			xte::string content;
			while (true) {
				int input = std::fgetc(*this);
				if ((input == xte::eof) || (input == delim)) {
					break;
				}
				content.push(static_cast<char>(input));
			}
			return content;
		}

		[[nodiscard]] int descriptor() const noexcept {
#	if XTE_PLATFORM_WINDOWS
			return ::_fileno(this->_stream.data());
#	else
			return ::fileno(this->_stream.data());
#	endif
		}

	private:
		xte::ptr<std::FILE> _stream;
		xte::file::mode _mode = xte::file::mode::none;
	};
}

#endif

// https://vitaut.net/posts/2020/optimal-file-buffer-size/
