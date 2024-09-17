export module xieite:containers.MaybeCopyConstructible;

export namespace xieite::containers {
	template<bool>
	struct MaybeCopyConstructible {};

	template<>
	struct MaybeCopyConstructible<false> {
		MaybeCopyConstructible() = default;
		MaybeCopyConstructible(const xieite::containers::MaybeCopyConstructible<false>&) = delete;
		MaybeCopyConstructible(xieite::containers::MaybeCopyConstructible<false>&&) = default;
		xieite::containers::MaybeCopyConstructible<false>& operator=(const xieite::containers::MaybeCopyConstructible<false>&) = default;
		xieite::containers::MaybeCopyConstructible<false>& operator=(xieite::containers::MaybeCopyConstructible<false>&&) = default;
	};
}
