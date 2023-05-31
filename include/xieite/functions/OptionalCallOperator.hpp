#ifndef XIEITE_HEADER_FUNCTIONS_OPTIONALCALLOPERATOR
#	define XIEITE_HEADER_FUNCTIONS_OPTIONALCALLOPERATOR

#	warning "'xietie::functions::OptionalCallOperator' is deprecated"

#	include <xieite/functions/MakeFunctor.hpp>

namespace xieite::functions {
	template<typename Any>
	using OptionalCallOperator = xietie::functions::MakeFunctor<Any>;
}

#endif
