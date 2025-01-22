export module xieite:split_bool;

export namespace xieite {
	[[nodiscard]] constexpr int split_bool(bool x) noexcept {
		return x * 2 - 1;
	}
}
