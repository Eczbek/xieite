#ifndef DETAIL_XTE_HEADER_SYS_EXIT
#	define DETAIL_XTE_HEADER_SYS_EXIT

namespace xte::exit {
	inline constexpr int ok = 0;

	inline constexpr int fail = 1;

	inline constexpr int help = 2; // returned by `kill --help`

	inline constexpr int bad_args = 64;

	inline constexpr int bad_input = 65;

	inline constexpr int no_input = 66;

	inline constexpr int no_user = 67;

	inline constexpr int no_host = 68;

	inline constexpr int unavailable = 69;

	inline constexpr int internal_error = 70;

	inline constexpr int system_error = 71;

	inline constexpr int system_file_error = 72;

	inline constexpr int cannot_create_file = 73;

	inline constexpr int io_error = 74;

	inline constexpr int try_again = 75;

	inline constexpr int protocol = 76;

	inline constexpr int permission = 77;

	inline constexpr int misconfig = 78;
}

#endif

// https://man.freebsd.org/cgi/man.cgi?query=sysexits
