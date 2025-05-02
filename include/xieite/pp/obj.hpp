#ifndef DETAIL_XIEITE_HEADER_PP_OBJ
#	define DETAIL_XIEITE_HEADER_PP_OBJ
#
#	ifdef __cplusplus
#		define XIEITE_OBJ(...) DETAIL_XIEITE::OBJ::paren<__VA_ARGS__>

namespace DETAIL_XIEITE::OBJ {
	template<typename T>
	using paren = T;
}

#	else
#		define XIEITE_OBJ(...) (__VA_ARGS__)
#	endif
#endif
