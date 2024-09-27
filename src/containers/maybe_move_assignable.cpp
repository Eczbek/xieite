export module xieite:containers.MaybeMoveAssignable;

export namespace xieite::containers {
	template<bool>
	struct MaybeMoveAssignable {};

	template<>
	struct MaybeMoveAssignable<false> {
		MaybeMoveAssignable() = default;
		MaybeMoveAssignable(const MaybeMoveAssignable&) = default;
		MaybeMoveAssignable(MaybeMoveAssignable&&) = default;
		MaybeMoveAssignable& operator=(const MaybeMoveAssignable&) = default;
		auto operator=(MaybeMoveAssignable&&) = delete;
	};
}
