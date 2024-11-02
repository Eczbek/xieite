export module xieite:collapse_fwd;

import :collapse_ref;

export namespace xieite {
	template<typename T, typename U>
	[[nodiscard]] constexpr auto&& collapse_fwd(U&& value) noexcept {
		return static_cast<xieite::collapse_ref<T, U>>(value);
	}
}
