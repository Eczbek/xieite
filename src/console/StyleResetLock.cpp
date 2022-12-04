#include <iostream>
#include <xieite/console/StyleResetLock.hpp>
#include <xieite/console/resetStyle.hpp>

xieite::console::StyleResetLock::~StyleResetLock() {
	xieite::console::resetStyle();
}
