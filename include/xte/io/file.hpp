#ifndef DETAIL_XTE_HEADER_IO_FILE
#	define DETAIL_XTE_HEADER_IO_FILE
#
#	include "../aliases.hpp"
#	include "../detect/platform.hpp"
#	include "../exchange.hpp"
#	include "../io/eof.hpp"
#	include "../preproc/lift.hpp"
#	include "../qual_cast.hpp"
#	include "../string.hpp"
#	include "../string_view.hpp"
#	include "../sys/is_tty.hpp"
#	include <cstdio>
#	include <stdio.h>
#	include <utility>
#	if XTE_PLATFORM_UNIX
#		include <sys/wait.h>
#	endif

namespace xte {
	struct file_mode {
	private:
		xte::uz _mask;
	
		[[nodiscard]] constexpr file_mode(xte::uz mask) noexcept
		: _mask(mask) {}

	public:
		[[nodiscard]] constexpr file_mode() noexcept
		: _mask(xte::file_mode::none) {}

		static const xte::file_mode none;
		static const xte::file_mode read;
		static const xte::file_mode write;
		static const xte::file_mode overwrite;
		static const xte::file_mode append;
		static const xte::file_mode read_write;
		static const xte::file_mode read_overwrite;
		static const xte::file_mode read_append;
		
		[[nodiscard]] explicit(false) constexpr operator xte::uz() const noexcept {
			return this->_mask;
		}

		[[nodiscard]] explicit(false) constexpr operator const char*() const noexcept;
	};

	constexpr xte::file_mode xte::file_mode::none = xte::file_mode(0b0000);
	constexpr xte::file_mode xte::file_mode::read = xte::file_mode(0b0001);
	constexpr xte::file_mode xte::file_mode::write = xte::file_mode(0b0010);
	constexpr xte::file_mode xte::file_mode::overwrite = xte::file_mode(0b0110);
	constexpr xte::file_mode xte::file_mode::append = xte::file_mode(0b1000);
	constexpr xte::file_mode xte::file_mode::read_write = xte::file_mode(0b0011);
	constexpr xte::file_mode xte::file_mode::read_overwrite = xte::file_mode(0b0111);
	constexpr xte::file_mode xte::file_mode::read_append = xte::file_mode(0b1001);

	constexpr xte::file_mode::operator const char*() const noexcept {
		switch (this->_mask) {
			case xte::file_mode::read:
				return "r";
			case xte::file_mode::write:
				return "wx";
			case xte::file_mode::overwrite:
				return "w";
			case xte::file_mode::append:
				return "a";
			case xte::file_mode::read_write:
				return "r+";
			case xte::file_mode::read_overwrite:
				return "wx+";
			case xte::file_mode::read_append:
				return "a+";
			default:
				return nullptr;
		}
	}

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

		xte::file& operator=(xte::file&& other) & noexcept {
			this->close();
			this->_stream = other.release();
			this->_mode = other._mode;
			return *this;
		}

		[[nodiscard]] explicit(false) operator std::FILE*() const noexcept {
			return this->_stream;
		}

		[[nodiscard]] xte::file_mode mode() const noexcept {
			return this->_mode;
		}

		[[nodiscard]] std::FILE* release() noexcept {
			this->_mode = xte::file_mode::none;
			return xte::exchange(this->_stream, nullptr);
		}

		bool open(xte::string_view path, xte::file_mode mode) & noexcept(false) {
			if (*this) {
				return false;
			}
			this->_mode = mode;
			return !!(this->_stream = path.make_c_str_for(XTE_LIFT(std::fopen), mode));
		}

		bool close() & noexcept {
			return (this->_stream && !xte::is_tty(*this))
				? !std::fclose(this->release())
				: !!this->release();
		}

		bool write(xte::string_view content) const noexcept {
			return std::fwrite(content.data(), 1, content.size(), this->_stream) == content.size();
		}

		bool flush() noexcept {
			return !std::fflush(this->_stream);
		}

		[[nodiscard]] xte::string read() const noexcept(false) {
			static constexpr xte::uz chunk_size = 32768;
			xte::string content;
			while (true) {
				xte::uz prev_size = content.size();
				content.resize(prev_size + chunk_size);
				if (xte::uz bytes_read = std::fread(content.data() + prev_size, 1, chunk_size, this->_stream); bytes_read != chunk_size) {
					content.resize(prev_size + bytes_read);
					break;
				}
			}
			return content;
		}

		[[nodiscard]] xte::string read(char delim) const noexcept(false) {
			xte::string content;
			while (true) {
				int input = std::fgetc(this->_stream);
				if ((input == xte::eof) || (input == delim)) {
					break;
				}
				content.append(static_cast<char>(input));
			}
			return content;
		}

		[[nodiscard]] int descriptor() const noexcept {
#	if XTE_PLATFORM_WINDOWS
			return ::_fileno(this->_stream);
#	elif XTE_PLATFORM_UNIX
			return ::fileno(this->_stream);
#	else
			return -1;
#	endif
		}

	private:
		std::FILE* _stream = nullptr;
		xte::file_mode _mode = xte::file_mode::none;
	};

	struct file_pipe {
	public:
		[[nodiscard]] explicit(false) file_pipe() noexcept = default;

		[[nodiscard]] explicit file_pipe(std::FILE* stream) noexcept
		: _file(stream, xte::file_mode::read) {}

		[[nodiscard]] explicit file_pipe(xte::string_view path) noexcept(false) {
			this->open(path);
		}

		~file_pipe() {
			this->close();
		}

		xte::file_pipe& operator=(xte::file_pipe&& other) & noexcept {
			this->_file = xte::as_xvalue(other)._file;
			return *this;
		}

		[[nodiscard]] explicit(false) operator std::FILE*() const noexcept {
			return this->_file;
		}

		[[nodiscard]] std::FILE* release() noexcept {
			return this->_file.release();
		}

		bool open(xte::string_view command) & noexcept(false) {
#	if XTE_PLATFORM_WINDOWS
			std::FILE* pipe = command.make_c_str_for(XTE_LIFT(::_popen), xte::file_mode::read);
#	else
			std::FILE* pipe = command.make_c_str_for(XTE_LIFT(::popen), xte::file_mode::read);
#	endif
			return (*this = xte::file_pipe(pipe));
		}

		bool close() & noexcept {
			if (!*this) {
				return xte::eof;
			}
#	if XTE_PLATFORM_WINDOWS
			int status = ::_pclose(this->release());
#	else
			int status = ::pclose(this->release());
			if (WIFEXITED(status)) {
				return WEXITSTATUS(status);
			}
			if (WIFSIGNALED(status)) {
				return WTERMSIG(status);
			}
			if (WIFSTOPPED(status)) {
				return WSTOPSIG(status);
			}
#	endif
			return status;
		}

		[[nodiscard]] xte::string read() const noexcept(false) {
			return this->_file.read();
		}

		[[nodiscard]] xte::string read(char delim) const noexcept(false) {
			return this->_file.read(delim);
		}

		[[nodiscard]] int descriptor() const noexcept {
			return this->_file.descriptor();
		}

	private:
		xte::file _file;
	};
}

#endif

// https://vitaut.net/posts/2020/optimal-file-buffer-size/
