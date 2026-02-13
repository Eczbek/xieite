#ifndef DETAIL_XTE_HEADER_META_REQ_ANY
#	define DETAIL_XTE_HEADER_META_REQ_ANY
#
#	include "../meta/req.hpp"

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept req_any = (... || xte::req<T, predicates>);
}

#endif
