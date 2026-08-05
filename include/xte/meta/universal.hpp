#ifndef DETAIL_XTE_HEADER_META_UNIVERSAL
#	define DETAIL_XTE_HEADER_META_UNIVERSAL

namespace xte {
	struct universal {
		explicit(false) universal(auto&&...) noexcept {
			static_assert(false, "must not be evaluated");
		}

		template<typename T>
		explicit(false) operator T() const&& noexcept {
			static_assert(false, "must not be evaluated");
		}

		template<typename T>
		explicit(false) operator T&() const& noexcept {
			static_assert(false, "must not be evaluated");
		}
	};
}
