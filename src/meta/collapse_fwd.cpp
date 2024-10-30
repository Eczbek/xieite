export module xieite:collapse_fwd;

import std;
import :collapse_ref;

export namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr auto&& collapse_fwd(auto&& value) noexcept {
		return std::forward_like<xieite::collapse_ref<T, decltype(value)>>(value);
	}
}
