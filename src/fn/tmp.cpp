export module xieite:tmp;

export namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr T& tmp(T&& value = {}) noexcept {
		return { value }; // :)
	}
}
