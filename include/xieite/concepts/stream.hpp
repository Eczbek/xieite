#ifndef XIEITE_HEADER_CONCEPTS_STREAM
#	define XIEITE_HEADER_CONCEPTS_STREAM

#	include "../concepts/input_stream.hpp"
#	include "../concepts/output_stream.hpp"

namespace xieite::concepts {
	template<typename Type_>
	concept Stream = xieite::concepts::InputStream<Type_> || xieite::concepts::OutputStream<Type_>;
}

#endif
