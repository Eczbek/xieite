#ifndef DETAIL_XIEITE_HEADER_IO_DUMP
#	define DETAIL_XIEITE_HEADER_IO_DUMP
#
#	include <cstdio>
#	include <print>
#	include "../data/fixed_str.hpp"
#	include "../data/fmt_join.hpp"
#	include "../pp/fwd.hpp"

using namespace std::literals;

namespace xieite {
	template<xieite::fixed_str delim = " ", bool newline = true, typename... Args>
	void dump(std::FILE* file, Args&&... args) noexcept {
		if constexpr (newline) {
			std::println(file, xieite::fmt_join<delim, Args...>, XIEITE_FWD(args)...);
		} else {
			std::print(file, xieite::fmt_join<delim, Args...>, XIEITE_FWD(args)...);
		}
	}

	template<xieite::fixed_str delim = " ", bool newline = true>
	void dump(auto&&... args) noexcept {
		return xieite::dump<delim, newline>(stdout, XIEITE_FWD(args)...);
	}
}

#endif
