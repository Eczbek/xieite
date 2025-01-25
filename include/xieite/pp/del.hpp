#pragma once

#include "../pp/lang.hpp"

#if XIEITE_LANG_LEAST(CPP, 2026)
#	define XIEITE_DEL(s_) delete(s_)
#else
#	define XIEITE_DEL(_) delete
#endif
