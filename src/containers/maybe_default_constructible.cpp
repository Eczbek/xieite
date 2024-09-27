export module xieite:containers.MaybeDefaultConstructible;

export namespace xieite::containers {
	template<bool>
	struct MaybeDefaultConstructible {};

	template<>
	struct MaybeDefaultConstructible<false> {
		MaybeDefaultConstructible() = delete;
		MaybeDefaultConstructible(const MaybeDefaultConstructible&) = default;
		MaybeDefaultConstructible(MaybeDefaultConstructible&&) = default;
		MaybeDefaultConstructible& operator=(const MaybeDefaultConstructible&) = default;
		MaybeDefaultConstructible& operator=(MaybeDefaultConstructible&&) = default;
	};
}
