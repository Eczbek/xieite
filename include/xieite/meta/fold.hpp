#ifndef DETAIL_XIEITE_HEADER_META_FOLD
#	define DETAIL_XIEITE_HEADER_META_FOLD
#
#	include <type_traits>

namespace DETAIL_XIEITE::fold {
	template<auto fn, typename T>
	struct impl {
		using type = T;

		template<typename U>
		DETAIL_XIEITE::fold::impl<fn, decltype(fn.template operator()<T, U>())> operator->*(std::type_identity<U>) const;
	};
}

namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((DETAIL_XIEITE::fold::impl<fn, T>()->*...->*std::type_identity<Ts>()))::type;
}

#endif
