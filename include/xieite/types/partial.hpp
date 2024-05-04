#ifndef XIEITE_HEADER_TYPES_PARTIAL
#	define XIEITE_HEADER_TYPES_PARTIAL

namespace xieite::types {
	template<template<typename...> typename Template_, typename... FirstArguments_>
	struct Partial {
		template<typename... RestArguments_>
		using Append = Template_<FirstArguments_..., RestArguments_...>;

		template<typename... RestArguments_>
		using Prepend = Template_<RestArguments_..., FirstArguments_...>;
	};
}

#endif
