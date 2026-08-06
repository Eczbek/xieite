#ifndef DETAIL_XTE_HEADER_META_MEMBER_TYPE
#	define DETAIL_XTE_HEADER_META_MEMBER_TYPE

namespace xte {
	template<typename class_type, typename type>
	using member_type = type class_type::*;
}

#endif
