export module xieite:types.Partial;

export namespace xieite::types {
	template<template<typename...> typename Template, typename... FirstArguments>
	struct Partial {
		template<typename... RestArguments>
		using Append = Template<FirstArguments..., RestArguments...>;

		template<typename... RestArguments>
		using Prepend = Template<RestArguments..., FirstArguments...>;
	};
}
