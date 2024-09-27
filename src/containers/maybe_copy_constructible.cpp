export module xieite:containers.MaybeCopyConstructible;

export namespace xieite::containers {
	template<bool>
	struct MaybeCopyConstructible {};

	template<>
	struct MaybeCopyConstructible<false> {
		MaybeCopyConstructible() = default;
		MaybeCopyConstructible(const MaybeCopyConstructible&) = delete;
		MaybeCopyConstructible(MaybeCopyConstructible&&) = default;
		MaybeCopyConstructible& operator=(const MaybeCopyConstructible&) = default;
		MaybeCopyConstructible& operator=(MaybeCopyConstructible&&) = default;
	};
}
