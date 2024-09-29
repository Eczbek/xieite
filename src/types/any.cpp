export module xieite:types.Any;

export namespace xieite::types {
	struct Any {
		template<typename Type>
		explicit(false) operator Type() const noexcept {
			static_assert(false, "must not be evaluated");
		}
	};
}
