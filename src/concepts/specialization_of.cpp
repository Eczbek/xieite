export module xieite:concepts.SpecializationOf;

import std

export namespace xieite::concepts {
	template<typename Type, template<typename...> typename Template>
	concept SpecializationOf = requires { ([]<typename... Arguments>(std::type_identity<Template<Arguments...>>) {})(std::type_identity<Type>()); };
}

// TODO: Remove after `std::specialization_of` is implemented
