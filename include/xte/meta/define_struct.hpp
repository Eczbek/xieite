#ifndef DETAIL_XTE_HEADER_META_DEFINE_STRUCT
#	define DETAIL_XTE_HEADER_META_DEFINE_STRUCT
#
#	include "../data/string_view.hpp"
#	include "../preproc/diagnostic.hpp"
#	include <meta>

XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Wmissing-field-initializers")

namespace DETAIL_XTE::define_struct {
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
	template<DETAIL_XTE::define_struct::member... members>
	using define_struct = DETAIL_XTE::define_struct::impl<members...>::type;
}

#endif
