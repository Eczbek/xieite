export module xieite:math.splitBoolean;

export namespace xieite::math {
	[[nodiscard]] constexpr int splitBoolean(const bool value) noexcept {
		return value * 2 - 1;
	}
}
