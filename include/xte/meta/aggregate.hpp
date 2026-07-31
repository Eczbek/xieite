#ifndef DETAIL_XTE_HEADER_META_AGGREGATE
#	define DETAIL_XTE_HEADER_META_AGGREGATE
#
#	include "../data/string_view.hpp"
#	include "../preproc/diagnostic.hpp"
#	include <meta>

XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Wmissing-field-initializers")

namespace DETAIL_XTE::aggregate {
	struct member {
		std::meta::info type;
		xte::string_view name;
	};

	template<member... members>
	struct impl {
		struct type;

		consteval {
			std::meta::define_aggregate(^^impl::type, {
				std::meta::data_member_spec(members.type, { .name = members.name })...
			});
		}
	};
}

XTE_DIAGNOSTIC_POP_GCC()

namespace xte {
	template<DETAIL_XTE::aggregate::member... members>
	using aggregate = DETAIL_XTE::aggregate::impl<members...>::type;
}

#endif
