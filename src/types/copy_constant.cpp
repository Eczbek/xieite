export module xieite:types.CopyConstant;

import :concepts.Constant;
import :types.MaybeConstant;

export namespace xieite::types {
	template<typename Source, typename Target>
	using CopyConstant = xieite::types::MaybeConstant<Target, xieite::concepts::Constant<Source>>;
}
