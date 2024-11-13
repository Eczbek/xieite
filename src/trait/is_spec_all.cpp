export module xieite:is_spec_all;

import :is_spec;

export namespace xieite {
	template<typename T, template<typename> typename... Ms>
	concept is_spec_all = (... && xieite::is_spec<T, Ms>);
}
