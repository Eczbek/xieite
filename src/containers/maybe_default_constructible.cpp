export module xieite:containers.MaybeDefaultConstructible;

export namespace xieite::containers {
	template<bool>
	struct MaybeDefaultConstructible {};

	template<>
	struct MaybeDefaultConstructible<false> {
		MaybeDefaultConstructible() = delete;
		MaybeDefaultConstructible(const xieite::containers::MaybeDefaultConstructible<false>&) = default;
		MaybeDefaultConstructible(xieite::containers::MaybeDefaultConstructible<false>&&) = default;
		xieite::containers::MaybeDefaultConstructible<false>& operator=(const xieite::containers::MaybeDefaultConstructible<false>&) = default;
		xieite::containers::MaybeDefaultConstructible<false>& operator=(xieite::containers::MaybeDefaultConstructible<false>&&) = default;
	};
}
