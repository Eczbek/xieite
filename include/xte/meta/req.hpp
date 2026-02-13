#ifndef DETAIL_XTE_HEADER_META_REQ
#	define DETAIL_XTE_HEADER_META_REQ
#
#	include "../meta/refl.hpp"

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept req = (... && requires { xte::refl::subst<predicates, ^^T>; });
}

#endif
