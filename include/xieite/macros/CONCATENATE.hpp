#pragma once

#define XIEITE_CONCATENATE(expression1, expression2) \
	XIEITE_CONCATENATE_PRIMITIVE(expression1, expression2)

#define XIEITE_CONCATENATE_PRIMITIVE(expression1, expression2) \
	expression1 ## expression2

