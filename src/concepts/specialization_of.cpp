export module xieite:concepts.SpecializationOf;

import :traits.IsSpecializationOf;

export namespace xieite::concepts {
	template<typename Type, template<typename...> typename Template>
	concept SpecializationOf = xieite::traits::IsSpecializationOf<std::remove_cvref_t<Type>, Template>::value;
}
