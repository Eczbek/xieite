#pragma once

#define XIEITE_QUOTE(expressions...) \
	XIEITE_QUOTE_PRIMITIVE(expressions)

#define XIEITE_QUOTE_PRIMITIVE(expressions...) \
	#expressions
