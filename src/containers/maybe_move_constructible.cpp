export module xieite:containers.MaybeMoveConstructible;

export namespace xieite::containers {
	template<bool>
	struct MaybeMoveConstructible {};

	template<>
	struct MaybeMoveConstructible<false> {
		MaybeMoveConstructible() = default;
		MaybeMoveConstructible(const MaybeMoveConstructible&) = default;
		MaybeMoveConstructible(MaybeMoveConstructible&&) = delete;
		MaybeMoveConstructible& operator=(const MaybeMoveConstructible&) = default;
		MaybeMoveConstructible& operator=(MaybeMoveConstructible&&) = default;
	};
}
