#ifndef DETAIL_XTE_HEADER_IO_LOGGER
#	define DETAIL_XTE_HEADER_IO_LOGGER
#
#	include "../data/string_view.hpp"
#	include "../meta/sloc.hpp"
#	include "../preproc/fwd.hpp"
#	include "../sys/is_tty.hpp"
#	include "../util/number_types.hpp"
#	include <chrono>
#	include <cstdio>
#	include <format>
#	include <meta>
#	include <print>

namespace DETAIL_XTE::logger {
	template<xte::uz color, xte::string_view tag, typename... arg_types>
	struct impl {
	public:
		explicit impl(std::format_string<arg_types...> fmt, arg_types&&... args, xte::sloc sloc = {}) noexcept(false)
		: impl(sloc, stdout, fmt, XTE_FWD(args)...) {}

		explicit impl(std::FILE* stream, std::format_string<arg_types...> fmt, arg_types&&... args, xte::sloc sloc = {}) noexcept(false)
		: impl(sloc, stream, fmt, XTE_FWD(args)...) {}

	private:
		explicit impl(const xte::sloc& sloc, std::FILE* stream, std::format_string<arg_types...> fmt, arg_types&&... args) noexcept(false) {
			bool tty = xte::is_tty(stream);
			std::println(stream, "{}{:<5} [{:%F %T}] {}:{}:{}: {}{}", (tty ? std::format("\x1B[{}m", color).c_str() : ""), std::define_static_string(tag), std::chrono::floor<std::chrono::seconds>(std::chrono::system_clock::now()), sloc.file, sloc.func, sloc.line, std::format(fmt, XTE_FWD(args)...), (tty ? "\x1B[0m" : ""));
		}
	};
}

#	define DETAIL_XTE_LOGGER(NAME, COLOR, TAG) \
		template<typename... DETAIL_XTE_arg_types> \
		struct NAME : DETAIL_XTE::logger::impl<(COLOR), (TAG), DETAIL_XTE_arg_types...> { \
			using DETAIL_XTE::logger::impl<(COLOR), (TAG), DETAIL_XTE_arg_types...>::logger::impl; \
		}; \
		\
		template<typename... DETAIL_XTE_arg_types> \
		NAME(std::format_string<DETAIL_XTE_arg_types...>, DETAIL_XTE_arg_types&&...) -> NAME<DETAIL_XTE_arg_types...>; \
		\
		template<typename... DETAIL_XTE_arg_types> \
		NAME(std::FILE*, std::format_string<DETAIL_XTE_arg_types...>, DETAIL_XTE_arg_types&&...) -> NAME<DETAIL_XTE_arg_types...>

namespace xte::logger {
	DETAIL_XTE_LOGGER(info, 0, "INFO");
	DETAIL_XTE_LOGGER(debug, 35, "DEBUG");
	DETAIL_XTE_LOGGER(warn, 33, "WARN");
	DETAIL_XTE_LOGGER(error, 31, "ERROR");
}

#endif
