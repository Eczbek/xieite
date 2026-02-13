#ifndef DETAIL_XTE_HEADER_TRAIT_NON_MOVABLE
#	define DETAIL_XTE_HEADER_TRAIT_NON_MOVABLE

namespace xte {
	struct non_movable {
		non_movable() = default;

		non_movable(xte::non_movable&) = default;

		non_movable(xte::non_movable&&) = delete;

		xte::non_movable& operator=(const xte::non_movable&) = default;

		xte::non_movable& operator=(xte::non_movable&&) = delete;
	};
}

#endif
