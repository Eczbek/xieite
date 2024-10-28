export module xieite:is_stream;

import :is_istream;
import :is_ostream;

export namespace xieite {
	template<typename T>
	concept is_stream = xieite::is_istream<T> || xieite::is_ostream<T>;
}
