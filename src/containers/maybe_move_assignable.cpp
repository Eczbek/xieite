export module xieite:containers.MaybeMoveAssignable;

export namespace xieite::containers {
	template<bool>
	struct MaybeMoveAssignable {};

	template<>
	struct MaybeMoveAssignable<false> {
		MaybeMoveAssignable() = default;
		MaybeMoveAssignable(const xieite::containers::MaybeMoveAssignable<false>&) = default;
		MaybeMoveAssignable(xieite::containers::MaybeMoveAssignable<false>&&) = default;
		xieite::containers::MaybeMoveAssignable<false>& operator=(const xieite::containers::MaybeMoveAssignable<false>&) = default;
		auto operator=(xieite::containers::MaybeMoveAssignable<false>&&) = delete;
	};
}
