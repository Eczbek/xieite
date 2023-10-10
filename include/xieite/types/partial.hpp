#pragma once

#include <type_traits>

namespace xieite::types {
	template<template<typename...> typename Template, typename... FirstArguments>
	struct Partial {
		template<typename... SecondArguments>
		using Append = Template<FirstArguments..., SecondArguments...>;

		template<typename... SecondArguments>
		using Prepend = Template<SecondArguments..., FirstArguments...>;
	};
}
