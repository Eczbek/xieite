#ifndef DETAIL_XTE_HEADER_META_REQ
#	define DETAIL_XTE_HEADER_META_REQ
#
#	include <meta>

namespace xte {
	template<typename type, auto... predicates>
	concept req = (... && ([] {
		if constexpr (std::meta::is_reflection_type(^^decltype(predicates))) {
			static_assert(std::meta::is_template(predicates));
			if constexpr (!std::meta::can_substitute(predicates, { ^^type })) {
				return false;
			}
			if constexpr (requires { [:std::meta::substitute(predicates, { ^^type }):]::value; }) {
				return [:std::meta::substitute(predicates, { ^^type }):]::value;
			}
			return true;
		} else {
			// static_assert(requires { &decltype(predicates)::operator(); });
			return requires { predicates.template operator()<type>(); };
		}
	})());

	template<typename type, auto... predicates>
	concept req_any = (... || xte::req<type, predicates>);

	template<typename type, auto... predicates>
	concept req_not = !xte::req_any<type, predicates...>;

	template<typename type, auto... predicates>
	concept req_some = !xte::req<type, predicates...>;
}

#endif

// TODO: Change parameters back to `decltype(auto)`
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=124893
