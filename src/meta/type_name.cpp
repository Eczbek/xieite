module;

#include <xieite/cplr.hpp>
#include <xieite/fn_sig.hpp>

export module xieite:type_name;

import std;
import :make_array;
import :str_after;
import :str_between;

[[nodiscard]] consteval std::string_view get_type_name(std::string_view sig) noexcept {
#if XIEITE_CPLR_TYPE_GCC
	return xieite::str_between(sig, "= ", ';');
#elif XIEITE_CPLR_TYPE_CLANG
	return xieite::str_between(sig, "= ", ']');
#elif XIEITE_CPLR_TYPE_WINDOWS
	return xieite::str_between(xieite::str_after(sig, " __"), '<', ">(");
#endif
}

export namespace xieite {
	template<typename>
	[[nodiscard]] consteval std::string_view type_name() noexcept {
		static constexpr auto data = xieite::make_array<char, get_type_name(XIEITE_FN_SIG).size()>(get_type_name(XIEITE_FN_SIG));
		return std::string_view(data.begin(), data.end());
	}

	template<auto>
	[[nodiscard]] consteval std::string_view type_name() noexcept {
		static constexpr auto data = xieite::make_array<char, get_type_name(XIEITE_FN_SIG).size()>(get_type_name(XIEITE_FN_SIG));
		return std::string_view(data.begin(), data.end());
	}
}
