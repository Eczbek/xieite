#include <xte/preproc/while.hpp>

static_assert(([] {
	int i = 0;
	bool done = false;
	XTE_WHILE (i < 3) {
		++i;
	} else {
		done = true;
	}
	return (i == 3) && done;
})());

static_assert(([] {
	int i = 0;
	bool done = false;
	XTE_WHILE (i < 3) {
		++i;
		if (i == 1) {
			break;
		}
	} else {
		done = true;
	}
	return (i == 1) && !done;
})());
