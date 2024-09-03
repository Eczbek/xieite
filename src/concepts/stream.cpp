export module xieite:concepts.Stream;

import :concepts.InputStream;
import :concepts.OutputStream;

export namespace xieite::concepts {
	template<typename Type>
	concept Stream = xieite::concepts::InputStream<Type> || xieite::concepts::OutputStream<Type>;
}
