#ifndef DETAIL_XIEITE_HEADER_META_ANY
#	define DETAIL_XIEITE_HEADER_META_ANY

namespace xieite {
	struct any {
		any() = default;

		constexpr any(auto&&...) noexcept {}

		template<typename T>
		[[nodiscard]] explicit(false) operator T() const noexcept {
			static_assert(false, "must not be evaluated");
		}
	};
}

#endif
