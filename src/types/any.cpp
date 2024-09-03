export module xieite:types.Any;

export namespace xieite::types {
	struct Any {
		explicit(false) Any(auto&&...) noexcept;

		template<typename Type>
		explicit(false) operator Type() const noexcept;
	};
}
