#ifndef XIEITE_HEADER_FUNCTIONS_OVERLOADER
#	define XIEITE_HEADER_FUNCTIONS_OVERLOADER

#	include <xieite/concepts/Derivable.hpp>
#	include <xieite/functions/DefaultCallOperator.hpp>

namespace xieite::functions {
	template<xieite::concepts::Derivable... Functions>
	struct Overloader final
	: xieite::functions::DefaultCallOperator<Functions>... {
		constexpr Overloader(const Functions&... functions) noexcept
		: xieite::functions::DefaultCallOperator<Functions>(functions)... {}

		using xieite::functions::DefaultCallOperator<Functions>::operator()...;
	};
}

// Thanks to melak47 for help

#endif
