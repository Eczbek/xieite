module;

#include <xieite/cplr.hpp>
#include <xieite/fn_sig.hpp>

export module xieite:name;

import std;
import :make_array;
import :str_after;
import :str_between;

[[nodiscard]] consteval std::string_view get_name(std::string_view strv) noexcept {
#if XIEITE_CPLR_TYPE_CLANG || XIEITE_CPLR_TYPE_ICC
	return xieite::str_betw(strv, "= ", ']');
#elif XIEITE_CPLR_TYPE_GCC
	return xieite::str_betw(strv, "= ", ';');
#elif XIEITE_CPLR_TYPE_WINDOWS
	return xieite::str_betw(xieite::str_after(strv, " __"), '<', ">(");
#endif
}

namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		static constexpr auto data = xieite::make_array<char, get_name(XIEITE_FN_SIG).size()>(get_name(XIEITE_FN_SIG));
		return std::string_view(data.begin(), data.end());
	}

	template<auto v>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		static constexpr auto data = xieite::make_array<char, get_name(XIEITE_FN_SIG).size()>(get_name(XIEITE_FN_SIG));
		return std::string_view(data.begin(), data.end());
	}
}

// TODO: Mark functions `consteval`
