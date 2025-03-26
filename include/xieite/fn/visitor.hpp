#ifndef DETAIL_XIEITE_HEADER_FN_VISITOR
#	define DETAIL_XIEITE_HEADER_FN_VISITOR

namespace xieite {
	template<typename... Fs>
	struct visitor : Fs... {
		using Fs::operator()...;
	};

	template<typename... Fs>
	visitor(Fs...) -> visitor<Fs...>;
}

#endif
