export module xieite:containers.MaybeMoveConstructible;

export namespace xieite::containers {
	template<bool>
	struct MaybeMoveConstructible {};

	template<>
	struct MaybeMoveConstructible<false> {
		MaybeMoveConstructible() = default;
		MaybeMoveConstructible(const xieite::containers::MaybeMoveConstructible<false>&) = default;
		MaybeMoveConstructible(xieite::containers::MaybeMoveConstructible<false>&&) = delete;
		xieite::containers::MaybeMoveConstructible<false>& operator=(const xieite::containers::MaybeMoveConstructible<false>&) = default;
		xieite::containers::MaybeMoveConstructible<false>& operator=(xieite::containers::MaybeMoveConstructible<false>&&) = default;
	};
}
