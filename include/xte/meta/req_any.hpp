#ifndef DETAIL_XTE_HEADER_META_REQ_ANY
#	define DETAIL_XTE_HEADER_META_REQ_ANY
#
#	include "../meta/req.hpp"

namespace xte {
	template<typename T, auto... predicates>
	concept req_any = (... || xte::req<T, predicates>);
}

#endif

// TODO: Change parameter type back to `decltype(auto)`
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=124893
