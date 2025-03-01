#pragma once

#include "../pp/cplr.hpp"
#include "../pp/pragma.hpp"

#define X4DIAGMSG(_)
#define X4DIAGMSG_GCC(_)
#define X4DIAGMSG_CLANG(_)
#define X4DIAGMSG_MSVC(_)
#define X4DIAGWARN(_)
#define X4DIAGWARN_GCC(_)
#define X4DIAGWARN_CLANG(_)
#define X4DIAGWARN_MSVC(_)
#define X4DIAGERR(_)
#define X4DIAGERR_GCC(_)
#define X4DIAGERR_CLANG(_)
#define X4DIAGERR_MSVC(_)
#define X4DIAGPUSH()
#define X4DIAGPUSH_GCC()
#define X4DIAGPUSH_CLANG()
#define X4DIAGPUSH_MSVC()
#define X4DIAGPOP()
#define X4DIAGPOP_GCC()
#define X4DIAGPOP_CLANG()
#define X4DIAGPOP_MSVC()
#define X4DIAGON_GCC(_)
#define X4DIAGON_CLANG(_)
#define X4DIAGON_MSVC(_)
#define X4DIAGSTRICT_GCC(_)
#define X4DIAGSTRICT_CLANG(_)
#define X4DIAGSTRICT_MSVC(_)
#define X4DIAGOFF_GCC(_)
#define X4DIAGOFF_CLANG(_)
#define X4DIAGOFF_MSVC(_)

#if X4CPLR_GCC && !X4CPLR_CLANG
#	undef X4DIAGMSG
#	define X4DIAGMSG(s_) X4PRAGMA(message s_)

#	undef X4DIAGMSG_GCC
#	define X4DIAGMSG_GCC(s_) X4DIAGMSG(s_)

#	undef X4DIAGWARN
#	define X4DIAGWARN(s_) X4PRAGMA(GCC warning s_)

#	undef X4DIAGWARN_GCC
#	define X4DIAGWARN_GCC(s_) X4DIAGWARN(s_)

#	undef X4DIAGERR
#	define X4DIAGERR(s_) X4PRAGMA(GCC error s_)

#	undef X4DIAGERR_GCC
#	define X4DIAGERR_GCC(s_) X4DIAGERR(s_)

#	undef X4DIAGPUSH
#	define X4DIAGPUSH() X4PRAGMA(GCC diagnostic push)

#	undef X4DIAGPUSH_GCC
#	define X4DIAGPUSH_GCC() X4DIAGPUSH()

#	undef X4DIAGPOP
#	define X4DIAGPOP() X4PRAGMA(GCC diagnostic pop)

#	undef X4DIAGPOP_GCC
#	define X4DIAGPOP_GCC() X4DIAGPOP()

#	undef X4DIAGON_GCC
#	define X4DIAGON_GCC(s_) X4PRAGMA(GCC diagnostic warning s_)

#	undef X4DIAGSTRICT_GCC
#	define X4DIAGSTRICT_GCC(s_) X4PRAGMA(GCC diagnostic error s_)

#	undef X4DIAGOFF_GCC
#	define X4DIAGOFF_GCC(s_) X4PRAGMA(GCC diagnostic ignored s_)
#elif X4CPLR_CLANG
#	undef X4DIAGMSG
#	define X4DIAGMSG(s_) X4PRAGMA(message s_)

#	undef X4DIAGMSG_CLANG
#	define X4DIAGMSG_CLANG(s_) X4DIAGMSG(s_)

#	undef X4DIAGWARN
#	define X4DIAGWARN(s_) X4PRAGMA(GCC warning s_)

#	undef X4DIAGWARN_CLANG
#	define X4DIAGWARN_CLANG(s_) X4DIAGWARN(s_)

#	undef X4DIAGERR
#	define X4DIAGERR(s_) X4PRAGMA(GCC error s_)

#	undef X4DIAGERR_CLANG
#	define X4DIAGERR_CLANG(s_) X4DIAGERR(s_)

#	undef X4DIAGPUSH
#	define X4DIAGPUSH() X4PRAGMA(clang diagnostic push)

#	undef X4DIAGPUSH_CLANG
#	define X4DIAGPUSH_CLANG() X4DIAGPUSH()

#	undef X4DIAGPOP
#	define X4DIAGPOP() X4PRAGMA(clang diagnostic pop)

#	undef X4DIAGPOP_CLANG
#	define X4DIAGPOP_CLANG() X4DIAGPOP()

#	undef X4DIAGON_CLANG
#	define X4DIAGON_CLANG(s_) X4PRAGMA(clang diagnostic warning s_)

#	undef X4DIAGSTRICT_CLANG
#	define X4DIAGSTRICT_CLANG(s_) X4PRAGMA(clang diagnostic error s_)

#	undef X4DIAGOFF_CLANG
#	define X4DIAGOFF_CLANG(s_) X4PRAGMA(clang diagnostic ignored s_)
#elif X4CPLR_MSVC
#	undef X4DIAGMSG
#	define X4DIAGMSG(s_) X4PRAGMA(message(s_))

#	undef X4DIAGMSG_MSVC
#	define X4DIAGMSG_MSVC(s_) X4DIAGMSG(s_)

#	undef X4DIAGWARN
#	define X4DIAGWARN(s_) X4PRAGMA(message("\x1B[31m" s_ "\x1B[0m"))

#	undef X4DIAGWARN_MSVC
#	define X4DIAGWARN_MSVC(s_) X4DIAGWARN(s_)

#	undef X4DIAGERR
#	define X4DIAGERR(s_) X4PRAGMA(message("\x1B[35m" s_ "\x1B[0m"))

#	undef X4DIAGERR_MSVC
#	define X4DIAGERR_MSVC(s_) X4DIAGERR(s_)

#	undef X4DIAGPUSH
#	define X4DIAGPUSH() X4PRAGMA(warning(push))

#	undef X4DIAGPUSH_MSVC
#	define X4DIAGPUSH_MSVC() X4DIAGPUSH()

#	undef X4DIAGPOP
#	define X4DIAGPOP() X4PRAGMA(warning(pop))

#	undef X4DIAGPOP_MSVC
#	define X4DIAGPOP_MSVC() X4DIAGPOP()

#	undef X4DIAGON_MSVC
#	define X4DIAGON_MSVC(n_) X4PRAGMA(warning(default: n_))

#	undef X4DIAGSTRICT_MSVC
#	define X4DIAGSTRICT_MSVC(n_) X4PRAGMA(warning(error: n_))

#	undef X4DIAGOFF_MSVC
#	define X4DIAGOFF_MSVC(n_) X4PRAGMA(warning(disable: n_))
#endif
