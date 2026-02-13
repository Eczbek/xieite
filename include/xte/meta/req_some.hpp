#ifndef DETAIL_XTE_HEADER_META_REQ_SOME
#	define DETAIL_XTE_HEADER_META_REQ_SOME
#
#	include "../meta/req.hpp"

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept req_some = !xte::req<T, predicates...>;
}

#endif
