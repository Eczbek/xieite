#ifndef XIEITE_HEADER_CONCEPTS_SAMEASORDERIVEDFROM
#	define XIEITE_HEADER_CONCEPTS_SAMEASORDERIVEDFROM

#	include "../concepts/DerivedFrom.hpp"
#	include "../concepts/SameAs.hpp"

namespace xieite::concepts {
	template<typename Any, typename... Others>
	concept SameAsOrDerivedFrom = xieite::concepts::SameAs<Any, Others...> || xieite::concepts::DerivedFrom<Any, Others...>;
}

#endif
