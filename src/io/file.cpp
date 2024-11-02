module;

#include <xieite/cplr.hpp>
#include <xieite/pltf.hpp>

#if XIEITE_PLTF_TYPE_UNIX
#	include <fcntl.h>
#	include <unistd.h>
#elif !XIEITE_PLTF_TYPE_WINDOWS
#	warning "unsupported platform"
#endif

#if XIEITE_CPLR_TYPE_GCC
#	include <ext/stdio_filebuf.h>
#endif

export module xieite:file;

import std.compat;
import :is_istream;
import :is_ostream;
import :is_stream;

export namespace xieite {
	struct file {
	public:
		file(std::FILE* const stream = nullptr) noexcept :
			stream(stream)
		{}

		file(std::string_view path, std::string_view mode) noexcept {
			this->open(path, mode);
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		file(std::wstring_view path, std::wstring_view mode) noexcept {
			this->open(path, mode);
		}
#endif

		file(int desc, std::string_view mode) noexcept {
			this->open(desc, mode);
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		file(int desc, std::wstring_view mode) noexcept {
			this->open(desc, mode);
		}
#endif

		template<xieite::is_stream Stream>
		file(Stream& stream) noexcept {
			this->open(stream);
		}

		file(std::string_view path, std::string_view mode, xieite::file other) noexcept {
			this->reopen(path, mode, other);
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		file(std::wstring_view path, std::wstring_view mode, xieite::file other) noexcept {
			this->reopen(path, mode, other);
		}
#endif

		~file() {
			this->close();
		}

		void open(std::string_view path, std::string_view mode) noexcept {
			this->stream = std::fopen(std::string(path).c_str(), std::string(mode).c_str());
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		void open(std::wstring_view path, std::wstring_view mode) noexcept {
			this->stream = ::_wfopen(std::wstring(path).c_str(), std::wstring(mode).c_str());
		}
#endif

		void open(int desc, std::string_view mode) noexcept {
#if XIEITE_PLTF_TYPE_WINDOWS
			this->stream = ::_fdopen(desc, std::string(mode).c_str());
#else
			this->stream = ::fdopen(desc, std::string(mode).c_str());
#endif
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		void open(int desc, std::wstring_view mode) noexcept {
			this->stream = ::_wfdopen(desc, std::wstring(mode).c_str());
		}
#endif

		template<xieite::is_stream Stream>
		void open(Stream& stream) noexcept {
			this->stream = ([&stream] {
				const Stream* ptr = std::addressof(stream);
				if constexpr (xieite::is_istream<Stream>) {
					if (ptr == std::addressof(std::cin)) {
						return stdin;
					}
				} else if constexpr (xieite::is_ostream<Stream>) {
					if (ptr == std::addressof(std::cout)) {
						return stdout;
					}
					if ((ptr == std::addressof(std::cerr)) || (ptr == std::addressof(std::clog))) {
						return stderr;
					}
				}
				if constexpr (requires { stream.native_handle(); }) {
					const typename Stream::native_handle_type desc = stream.native_handle();
					std::string mode;
					mode.reserve(3);
					if constexpr (xieite::is_istream<Stream>) {
						mode += "r";
					}
					if constexpr (xieite::is_ostream<Stream>) {
						mode += "w";
					}
#if XIEITE_PLTF_TYPE_UNIX
					if (::fcntl(desc, F_GETFL) & O_APPEND) {
						mode += "a";
					}
#endif
					return file(desc, mode).release();
				} else {
#if XIEITE_CPLR_TYPE_GCC
					return static_cast<__gnu_cxx::stdio_filebuf<typename Stream::char_type, typename Stream::traits_type>*>(stream.rdbuf())->file();
#else
					return nullptr;
#endif
				}
			})();
		}

		void reopen(std::string_view path, std::string_view mode, xieite::file other) noexcept {
			this->stream = std::freopen(std::string(path).c_str(), std::string(mode).c_str(), other.get());
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		void reopen(std::wstring_view path, std::wstring_view mode, xieite::file other) noexcept {
			this->stream = ::_wfreopen(std::wstring(path).c_str(), std::wstring(mode).c_str(), other.get());
		}
#endif

		int close() noexcept {
			if (this->stream && (this->stream != stdin) && (this->stream != stdout) && (this->stream != stderr)) {
				return std::fclose(this->release());
			}
			return EOF; // Erroneous value
		}

		[[nodiscard]] std::FILE* get() const noexcept {
			return this->stream;
		}

		[[nodiscard]] int desc() const noexcept {
#if XIEITE_PLTF_TYPE_WINDOWS
			return ::_fileno(this->stream);
#else
			return ::fileno(this->stream);
#endif
		}

		[[nodiscard]] std::FILE* release() noexcept {
			std::FILE* const copy = this->stream;
			this->stream = nullptr;
			return copy;
		}

	private:
		std::FILE* stream;
	};
}
