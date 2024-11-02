export module xieite:proc_result;

import std;

export namespace xieite {
	struct proc_result {
		std::string output;
		int status = 0;
	};
}
