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
}

#endif

// TODO: Change parameter type back to `decltype(auto)`
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=124893
