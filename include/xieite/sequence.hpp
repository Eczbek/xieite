#pragma once

#include <xieite/unwrap.hpp>

#define XIEITE_SEQUENCE(index_, size_, ...) XIEITE_DETAIL_SEQUENCE(&, index_, size_, __VA_ARGS__)
#define XIEITE_SEQUENCE_CAPTURE(captures_, index_, size_, ...) XIEITE_DETAIL_SEQUENCE(captures_, index_, size_, __VA_ARGS__)
#define XIEITE_SEQUENCE_TYPE(index_, size_, ...) decltype(XIEITE_DETAIL_SEQUENCE(, index_, size_, __VA_ARGS__))

#define XIEITE_DETAIL_SEQUENCE(captures_, index_, size_, ...) \
	([XIEITE_UNWRAP(captures_)]<decltype(size_)... index_>(std::integer_sequence<decltype(size_), index_...>) -> decltype(auto) { \
		return __VA_ARGS__; \
	})(std::make_integer_sequence<decltype(size_), size_>())
