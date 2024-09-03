export module xieite:types.CopyQualifiers;

import :types.CopyConstant;
import :types.CopyReference;
import :types.CopyVolatile;

export namespace xieite::types {
	template<typename Source, typename Target>
	using CopyQualifiers = xieite::types::CopyReference<Source, xieite::types::CopyVolatile<Source, xieite::types::CopyConstant<Source, Target>>>;
}
