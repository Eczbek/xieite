#ifndef DETAIL_XTE_HEADER_TRAIT_NON_COPYABLE
#	define DETAIL_XTE_HEADER_TRAIT_NON_COPYABLE

namespace xte {
	struct non_copyable {
		non_copyable() = default;

		non_copyable(const xte::non_copyable&) = delete;

		non_copyable(xte::non_copyable&&) = default;

		xte::non_copyable& operator=(const xte::non_copyable&) = delete;

		xte::non_copyable& operator=(xte::non_copyable&&) = default;
	};
}

#endif
