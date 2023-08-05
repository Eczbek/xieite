#ifndef XIEITE_HEADER__TYPES__SIZEBITS
#	define XIEITE_HEADER__TYPES__SIZEBITS

#	include <cstddef>
#	include "../system/bitsPerByte.hpp"

namespace xieite::types {
	template<typename Any>
	inline constexpr std::size_t sizeBits = sizeof(Any) * xieite::system::bitsPerByte;
}

#endif
