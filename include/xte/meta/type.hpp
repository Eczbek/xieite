#ifndef DETAIL_XTE_HEADER_META_TYPE
#	define DETAIL_XTE_HEADER_META_TYPE

namespace xte {
	template<typename T>
	using type = T;

	template<typename class_type, typename type>
	using member_type = type class_type::*;
}

#endif
