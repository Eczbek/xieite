export module xieite:is_vref;

import :is_vlref;
import :is_vrref;

export namespace xieite {
	template<typename T>
	concept is_vref = xieite::is_vlref<T> || xieite::is_vrref<T>;
}
