export module xieite:split_bool;

export namespace xieite {
	[[nodiscard]] constexpr int split_bool(bool value) noexcept {
		return value * 2 - 1;
	}
}
