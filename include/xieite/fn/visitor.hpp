#ifndef DETAIL_XIEITE_HEADER_FN_VISITOR
#	define DETAIL_XIEITE_HEADER_FN_VISITOR

namespace xieite {
	template<typename... Fns>
	struct visitor : Fns... {
		using Fns::operator()...;
	};

	template<typename... Fns>
	visitor(Fns...) -> visitor<Fns...>;
}

#endif
