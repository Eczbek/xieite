#ifndef DETAIL_XTE_HEADER_META_REQ_NOT
#	define DETAIL_XTE_HEADER_META_REQ_NOT
#
#	include "../meta/req_any.hpp"

namespace xte {
	template<typename T, auto... predicates>
	concept req_not = !xte::req_any<T, predicates...>;
}

#endif

// TODO: Change parameter type back to `decltype(auto)`
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=124893
