export module xieite:is_spec_of_any;

import :is_spec_of;

export namespace xieite {
	template<typename T, template<typename> typename... Ms>
	concept is_spec_of_any = (... || xieite::is_spec_of<T, Ms>);
}
