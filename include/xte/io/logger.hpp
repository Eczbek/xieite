#ifndef DETAIL_XTE_HEADER_IO_LOGGER
#	define DETAIL_XTE_HEADER_IO_LOGGER
#
#	include "../data/fixed_string.hpp"
#	include "../meta/sloc.hpp"
#	include "../preproc/fwd.hpp"
#	include "../sys/isatty.hpp"
#	include "../util/types.hpp"
#	include <chrono>
#	include <cstdio>
#	include <format>
#	include <meta>
#	include <print>

namespace DETAIL_XTE {
	template<xte::uz color, xte::fixed_string tag, typename... Args>
	struct logger {
	public:
		explicit logger(std::format_string<Args...> fmt, Args&&... args, xte::sloc sloc = {}) noexcept
		: logger(sloc, stdout, fmt, XTE_FWD(args)...) {}

		explicit logger(std::FILE* file, std::format_string<Args...> fmt, Args&&... args, xte::sloc sloc = {}) noexcept
		: logger(sloc, file, fmt, XTE_FWD(args)...) {}

	private:
		explicit logger(const xte::sloc& sloc, std::FILE* file, std::format_string<Args...> fmt, Args&&... args) noexcept {
			bool tty = xte::isatty(file);
			std::println(file, "{}{:<5} [{:%F %T}] {}:{}:{}: {}{}", (tty ? std::format("\x1B[{}m", color).c_str() : ""), std::define_static_string(tag), std::chrono::floor<std::chrono::seconds>(std::chrono::system_clock::now()), sloc.file, sloc.func, sloc.line, std::format(fmt, XTE_FWD(args)...), (tty ? "\x1B[0m" : ""));
		}
	};
}

#	define DETAIL_XTE_LOGGER(_name, _color, _tag) \
		template<typename... DETAIL_XTE_Args> \
		struct _name : DETAIL_XTE::logger<(_color), (_tag), DETAIL_XTE_Args...> { \
			using DETAIL_XTE::logger<(_color), (_tag), DETAIL_XTE_Args...>::logger; \
		}; \
		\
		template<typename... DETAIL_XTE_Args> \
		_name(std::format_string<DETAIL_XTE_Args...>, DETAIL_XTE_Args&&...) -> _name<DETAIL_XTE_Args...>; \
		\
		template<typename... DETAIL_XTE_Args> \
		_name(std::FILE*, std::format_string<DETAIL_XTE_Args...>, DETAIL_XTE_Args&&...) -> _name<DETAIL_XTE_Args...>

namespace xte::logger {
	DETAIL_XTE_LOGGER(info, 0, "INFO");
	DETAIL_XTE_LOGGER(debug, 35, "DEBUG");
	DETAIL_XTE_LOGGER(warn, 33, "WARN");
	DETAIL_XTE_LOGGER(error, 31, "ERROR");
}

#endif
