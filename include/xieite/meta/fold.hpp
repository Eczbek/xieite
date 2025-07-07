#ifndef DETAIL_XIEITE_HEADER_META_FOLD
#	define DETAIL_XIEITE_HEADER_META_FOLD
#
#	include "../meta/type.hpp"

namespace DETAIL_XIEITE::fold {
	template<auto fn, typename T>
	struct impl {
		using type = T;

		template<typename U>
		DETAIL_XIEITE::fold::impl<fn, decltype(fn.template operator()<T, U>())> operator->*(xieite::type_id<U>) const;
	};
}

namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((DETAIL_XIEITE::fold::impl<fn, T>()->*...->*xieite::type_id<Ts>()))::type;
}

#endif
