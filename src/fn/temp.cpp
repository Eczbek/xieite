export module xieite:temp;

export namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr T& temp(T&& value = {}) noexcept {
		return { value }; // :)
	}
}
