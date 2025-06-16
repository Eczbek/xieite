#ifndef DETAIL_XIEITE_HEADER_SYS_EXIT
#	define DETAIL_XIEITE_HEADER_SYS_EXIT

namespace xieite::exit {
	inline constexpr int ok = 0;
	
	inline constexpr int usage = 64;
	
	inline constexpr int input = 65;
	
	inline constexpr int no_input = 66;
	
	inline constexpr int no_user = 67;
	
	inline constexpr int no_host = 68;
	
	inline constexpr int unavail = 69;
	
	inline constexpr int software = 70;
	
	inline constexpr int os = 71;
	
	inline constexpr int sys_file = 72;
	
	inline constexpr int cant_create = 73;
	
	inline constexpr int io = 74;
	
	inline constexpr int tmp = 75;
	
	inline constexpr int protocol = 76;
	
	inline constexpr int no_perm = 77;
	
	inline constexpr int config = 78;
}

#endif
