export module xieite:types.CopyConstantData;

import :concepts.Constant;
import :concepts.Pointer;
import :types.MaybeConstantData;

export namespace xieite::types {
	template<typename Source, xieite::concepts::Pointer Target>
	using CopyConstantData = xieite::types::MaybeConstantData<Target, xieite::concepts::Constant<Source>>;
}
