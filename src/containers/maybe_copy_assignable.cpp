export module xieite:containers.MaybeCopyAssignable;

export namespace xieite::containers {
	template<bool>
	struct MaybeCopyAssignable {};

	template<>
	struct MaybeCopyAssignable<false> {
		MaybeCopyAssignable() = default;
		MaybeCopyAssignable(const MaybeCopyAssignable&) = default;
		MaybeCopyAssignable(MaybeCopyAssignable&&) = default;
		auto operator=(const MaybeCopyAssignable&) = delete;
		MaybeCopyAssignable& operator=(MaybeCopyAssignable&&) = default;
	};
}
