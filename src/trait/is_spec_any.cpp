export module xieite:is_spec_any;

import :is_spec;

export namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec_any = (... || xieite::is_spec<T, Ms>);
}
