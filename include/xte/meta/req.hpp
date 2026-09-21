#ifndef DETAIL_XTE_HEADER_META_REQ
#	define DETAIL_XTE_HEADER_META_REQ
#
#	include <algorithm>
#	include <meta>

namespace xte {
	template<typename T, auto... predicates>
	concept req = (... && ([] {
		if constexpr (std::meta::is_reflection_type(^^decltype(predicates))) {
			return (std::meta::is_template(predicates) && std::meta::can_substitute(predicates, { ^^T }));
		} else {
			return requires { predicates.template operator()<T>(); };
		}
	})());

	template<typename T, auto... predicates>
	concept req_any = (... || xte::req<T, predicates>);

	template<typename T, auto... predicates>
	concept req_not = !xte::req_any<T, predicates...>;

	template<typename T, auto... predicates>
	concept req_some = !xte::req<T, predicates...>;
}

#endif

// TODO: Change parameters back to `decltype(auto)`
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=124893
