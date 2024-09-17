export module xieite:containers.MaybeCopyAssignable;

export namespace xieite::containers {
	template<bool>
	struct MaybeCopyAssignable {};

	template<>
	struct MaybeCopyAssignable<false> {
		MaybeCopyAssignable() = default;
		MaybeCopyAssignable(const xieite::containers::MaybeCopyAssignable<false>&) = default;
		MaybeCopyAssignable(xieite::containers::MaybeCopyAssignable<false>&&) = default;
		auto operator=(const xieite::containers::MaybeCopyAssignable<false>&) = delete;
		xieite::containers::MaybeCopyAssignable<false>& operator=(xieite::containers::MaybeCopyAssignable<false>&&) = default;
	};
}
