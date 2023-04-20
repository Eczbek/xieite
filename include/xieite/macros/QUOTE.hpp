#pragma once

#define XIEITE_QUOTE_PRIMITIVE(expression) \
	#expression

#define XIEITE_QUOTE(expression) \
	XIEITE_QUOTE_PRIMITIVE(expression)
