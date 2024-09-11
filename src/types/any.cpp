export module xieite:types.Any;

export namespace xieite::types {
	struct Any {
		explicit(false) Any(auto&&...) noexcept {
			static_assert(false, "must not be evaluated");
		}

		template<typename Type>
		explicit(false) operator Type() const noexcept {
			static_assert(false, "must not be evaluated");
		}
	};
}
