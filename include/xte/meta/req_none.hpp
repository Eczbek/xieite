#ifndef DETAIL_XTE_HEADER_META_REQ_NONE
#	define DETAIL_XTE_HEADER_META_REQ_NONE
#
#	include "../meta/req_any.hpp"

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept req_none = !xte::req_any<T, predicates...>;
}

#endif
