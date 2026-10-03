#ifndef DETAIL_XTE_HEADER_META_TYPE
#	define DETAIL_XTE_HEADER_META_TYPE

namespace xte {
	template<typename arg_type>
	using type = arg_type;

	template<typename class_type, typename type>
	using member_type = type class_type::*;
}

#endif
