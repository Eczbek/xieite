#ifndef DETAIL_XIEITE_HEADER_IO_LOG
#	define DETAIL_XIEITE_HEADER_IO_LOG
#
#	include <chrono>
#	include <cstdio>
#	include <format>
#	include <print>
#	include <string>
#	include <source_location>
#	include "../data/fixed_str.hpp"
#	include "../pp/fwd.hpp"
#	include "../sys/isatty.hpp"

namespace DETAIL_XIEITE::log {
	template<int color, xieite::fixed_str tag, typename... Args>
	struct impl {
	public:
		explicit impl(std::format_string<Args...> fmt, Args&&... args, std::source_location src = std::source_location::current()) noexcept
		: impl(src, stdout, fmt, XIEITE_FWD(args)...) {}

		explicit impl(std::FILE* file, std::format_string<Args...> fmt, Args&&... args, std::source_location src = std::source_location::current()) noexcept
		: impl(src, file, fmt, XIEITE_FWD(args)...) {}

	private:
		explicit impl(std::source_location src, std::FILE* file, std::format_string<Args...> fmt, Args&&... args) noexcept {
			const std::string msg = std::format("{} [{:%F %T}] {}:{}:{}: {}", tag.view(), std::chrono::floor<std::chrono::seconds>(std::chrono::system_clock::now()), src.file_name(), src.function_name(), src.line(), std::format(fmt, XIEITE_FWD(args)...));
			if (xieite::isatty(file)) {
				std::println(file, "\x1B[{}m{}\x1B[0m", color, msg);
			} else {
				std::println(file, "{}", msg);
			}
		}
	};
}

#define DETAIL_XIEITE_LOGGER(_name, _color, _tag) \
	template<typename... DETAIL_XIEITE_Args> \
	struct _name : DETAIL_XIEITE::log::impl<_color, _tag, DETAIL_XIEITE_Args...> { \
		using DETAIL_XIEITE::log::impl<_color, _tag, DETAIL_XIEITE_Args...>::impl; \
	}; \
	\
	template<typename... DETAIL_XIEITE_Args> \
	_name(std::format_string<DETAIL_XIEITE_Args...>, DETAIL_XIEITE_Args&&...) -> _name<DETAIL_XIEITE_Args...>; \
	\
	template<typename... DETAIL_XIEITE_Args> \
	_name(std::FILE*, std::format_string<DETAIL_XIEITE_Args...>, DETAIL_XIEITE_Args&&...) -> _name<DETAIL_XIEITE_Args...>;

namespace xieite::log {
	DETAIL_XIEITE_LOGGER(info, 0, "INFO ")
	DETAIL_XIEITE_LOGGER(warn, 33, "WARN ")
	DETAIL_XIEITE_LOGGER(error, 31, "ERROR")
}

#endif
