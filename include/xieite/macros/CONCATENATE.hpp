#pragma once

#define XIEITE_CONCATENATE(first, second) \
	XIEITE_INTERNAL_CONCATENATE(first, second)

#define XIEITE_INTERNAL_CONCATENATE(first, second) \
	first ## second
