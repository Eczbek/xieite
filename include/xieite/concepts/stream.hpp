#ifndef XIEITE_HEADER_CONCEPTS_STREAM
#	define XIEITE_HEADER_CONCEPTS_STREAM

#	include "../concepts/input_stream.hpp"
#	include "../concepts/output_stream.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Stream = xieite::concepts::InputStream<Type> || xieite::concepts::OutputStream<Type>;
}

#endif
