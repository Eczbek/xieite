#ifndef DETAIL_XTE_HEADER_VISITOR
#	define DETAIL_XTE_HEADER_VISITOR

namespace xte {
	template<typename... Ts>
	struct visitor : Ts... {
		using Ts::operator()...;
	};

	template<typename... Ts>
	visitor(Ts&&...) -> visitor<Ts...>;
}

#endif
