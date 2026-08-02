#ifndef DETAIL_XTE_HEADER_META_AGGREGATE
#	define DETAIL_XTE_HEADER_META_AGGREGATE
#
#	include "../data/string_view.hpp"
#	include "../func/unfold.hpp"
#	include "../meta/type.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../util/number_types.hpp"
#	include <meta>

XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Wmissing-field-initializers")

namespace DETAIL_XTE::aggregate {
	struct arg_type {
		std::meta::info type = ^^::;
		xte::string_view name = "";

		explicit(false) consteval arg_type(std::meta::info type) noexcept
		: type(type) {}

		template<xte::uz size>
		explicit(false) consteval arg_type(xte::type<const char[size]>& name) noexcept
		: name(name) {}
	};

	template<arg_type... args>
	struct impl {
		struct type;

		consteval {
			xte::unfold<(sizeof...(args) / 2)>([]<xte::uz... i> {
				std::meta::define_aggregate(^^impl::type, {
					std::meta::data_member_spec(args...[i * 2].type, { .name = args...[i * 2 + 1].name })...
				});
			});
		}
	};
}

XTE_DIAGNOSTIC_POP_GCC()

namespace xte {
	template<DETAIL_XTE::aggregate::arg_type... args>
	using aggregate = DETAIL_XTE::aggregate::impl<args...>::type;
}

#endif
