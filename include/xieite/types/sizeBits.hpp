#ifndef XIEITE_HEADER__TYPES__SIZEBITS
#	define XIEITE_HEADER__TYPES__SIZEBITS

#	include <cstddef>
#	include "../system/bitsPerByte.hpp"

namespace xieite::types {
	template<typename Type>
	inline constexpr std::size_t sizeBits = sizeof(Type) * xieite::system::bitsPerByte;
}

#endif
