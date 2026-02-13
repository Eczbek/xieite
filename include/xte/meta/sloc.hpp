#ifndef DETAIL_XTE_HEADER_META_SLOC
#	define DETAIL_XTE_HEADER_META_SLOC
#
#	include "../data/string_view.hpp"
#	include "../util/types.hpp"
#	include <meta>
#	include <source_location>

namespace xte {
	struct sloc {
		xte::string_view file;
		xte::string_view func;
		xte::uz row;
		xte::uz col;

		[[nodiscard]] explicit(false) consteval sloc(std::source_location sloc = std::source_location::current()) noexcept
		: file(std::define_static_string(sloc.file_name()))
		, func(std::define_static_string(sloc.function_name()))
		, row(sloc.line())
		, col(sloc.column()) {}

		[[nodiscard]] explicit constexpr sloc(xte::string_view file, xte::string_view func, xte::uz row, xte::uz col = 0) noexcept
		: file(file), func(func), row(row), col(col) {}
	};
}

#endif
