export module xieite:concepts.StreamableIn;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept StreamableIn = requires(Type value, std::istream inputStream) {
		{ inputStream >> value } -> std::convertible_to<std::istream&>;
	};
}
