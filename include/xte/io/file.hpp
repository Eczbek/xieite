#ifndef DETAIL_XTE_HEADER_IO_FILE
#	define DETAIL_XTE_HEADER_IO_FILE
#
#	include "../data/ptr.hpp"
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../io/eof.hpp"
#	include "../io/file_mode.hpp"
#	include "../preproc/platform.hpp"
#	include "../sys/is_tty.hpp"
#	include "../util/number_types.hpp"
#	include <cstdio>
#	include <stdio.h>
#	include <utility>

namespace xte {
	struct file {
	public:
		[[nodiscard]] explicit(false) file() noexcept = default;

		[[nodiscard]] file(std::FILE* stream, xte::file_mode mode) noexcept
		: _stream(stream), _mode(mode) {}

		[[nodiscard]] file(xte::string_view path, xte::file_mode mode) noexcept(false) {
			this->open(path, mode);
		}

		~file() {
			this->close();
		}

		xte::file& operator=(xte::file&& other) noexcept {
			this->_stream = other._stream.release();
			this->_mode = other._mode;
			return *this;
		}

		[[nodiscard]] explicit(false) operator std::FILE*() const noexcept {
			return this->data();
		}

		[[nodiscard]] std::FILE* data() const noexcept {
			return this->_stream.data();
		}

		[[nodiscard]] std::FILE* release() noexcept {
			return this->_stream.release();
		}

		bool open(xte::string_view path, xte::file_mode mode) noexcept(false) {
			if (*this) {
				return false;
			}
			this->_mode = mode;
			return !!(this->_stream = std::fopen(xte::string(path).data(), mode));
		}

		bool close() noexcept {
			return (this->_stream && !xte::is_tty(*this))
				? !std::fclose(this->release())
				: !!this->release();
		}

		bool reopen(xte::string_view path, xte::file_mode mode) noexcept(false) {
			return this->close() && this->open(path, mode);
		}

		[[nodiscard]] bool is_readable() const noexcept {
			return *this && (this->_mode & xte::file_mode::read);
		}

		[[nodiscard]] bool is_writable() const noexcept {
			return *this && (this->_mode & xte::file_mode::write);
		}

		[[nodiscard]] bool is_overwritable() const noexcept {
			return *this && (this->_mode & xte::file_mode::overwrite);
		}

		[[nodiscard]] bool is_appendable() const noexcept {
			return *this && (this->_mode & xte::file_mode::append);
		}

		bool write(xte::string_view content) const noexcept {
			return std::fwrite(content.data(), 1, content.size(), *this) == content.size();
		}

		bool flush() noexcept {
			return !std::fflush(*this);
		}

		[[nodiscard]] xte::string read() const noexcept(false) {
			static constexpr xte::uz chunk_size = 32768;
			xte::string content;
			while (true) {
				xte::uz prev_size = content.size();
				content.resize(prev_size + chunk_size);
				if (xte::uz bytes_read = std::fread(content.data() + prev_size, 1, chunk_size, *this); bytes_read != chunk_size) {
					content.resize(prev_size + bytes_read);
					break;
				}
			}
			return content;
		}

		[[nodiscard]] xte::string read(char delim) const noexcept(false) {
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
#	elif XTE_PLATFORM_UNIX
			return ::fileno(this->_stream.data());
#	else
			return -1;
#	endif
		}

	private:
		xte::ptr<std::FILE> _stream;
		xte::file_mode _mode = xte::file_mode::none;
	};
}

#endif

// https://vitaut.net/posts/2020/optimal-file-buffer-size/
