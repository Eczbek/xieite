#pragma once

#include "../pp/lang.hpp"

#if X4LANGLEAST(CPP, 2026)
#	define X4DEL(s_) delete(s_)
#else
#	define X4DEL(_) delete
#endif
