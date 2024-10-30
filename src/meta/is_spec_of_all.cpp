export module xieite:is_spec_of_all;

import :is_spec_of;

export namespace xieite {
	template<typename T, template<typename> typename... Ms>
	concept is_spec_of_all = (... && xieite::is_spec_of<T, Ms>);
}
