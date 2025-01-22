module;

#include <xieite/fwd.hpp>

export module xieite:collapse_fwd_as_tuple;

import std;
import :collapse_fwd;

export namespace xieite {
	template<typename T, typename... Args>
	[[nodiscard]] constexpr auto collapse_fwd_as_tuple(Args&&... args) noexcept {
		return std::forward_as_tuple(xieite::collapse_fwd<T>(XIEITE_FWD(args))...);
	}
}
