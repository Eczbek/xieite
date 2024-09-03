export module xieite:types.MaybeConstantData;

import :concepts.Pointer;
import :types.MaybeConstant;
import :types.MaybePointer;

export namespace xieite::types {
	template<xieite::concepts::Pointer Type, bool qualified>
	using MaybeConstantData = xieite::types::MaybePointer<xieite::types::MaybeConstant<xieite::types::MaybePointer<Type, false>, qualified>, true>;
}
