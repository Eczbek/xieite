#ifndef XIEITE_HEADER_FUNCTIONS_OVERLOADER
#	define XIEITE_HEADER_FUNCTIONS_OVERLOADER

#	include <xieite/concepts/Derivable.hpp>
#	include <xieite/functions/MakeFunctor.hpp>

namespace xieite::functions {
	template<xieite::concepts::Derivable... Functions>
	struct Overloader
	: xieite::functions::MakeFunctor<Functions>... {
		constexpr Overloader(const Functions&... functions) noexcept
		: xieite::functions::MakeFunctor<Functions>(functions)... {}

		using xieite::functions::MakeFunctor<Functions>::operator()...;
	};
}

// Thanks to melak47 for help

#endif
