#ifndef XIEITE_HEADER_TYPES_SIZEBITS
#	define XIEITE_HEADER_TYPES_SIZEBITS

#	include <cstddef>
#	include "../system/bitsPerByte.hpp"

namespace xieite::types {
	template<typename Any>
	inline constexpr std::size_t sizeBits = sizeof(Any) * xieite::system::bitsPerByte;
}

#endif
