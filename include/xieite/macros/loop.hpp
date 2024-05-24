#ifndef XIEITE_HEADER_MACROS_LOOP
#   define XIEITE_HEADER_MACROS_LOOP

#   define XIEITE_LOOP_FOR(...) \
        for (int XIEITE_DETAIL_LOOP_FLAG = 2, XIEITE_DETAIL_LOOP_BREAK = false; XIEITE_DETAIL_LOOP_FLAG && !XIEITE_DETAIL_LOOP_BREAK; --XIEITE_DETAIL_LOOP_FLAG) \
            if ((XIEITE_DETAIL_LOOP_FLAG == 2) && !XIEITE_DETAIL_LOOP_BREAK) \
                for (__VA_ARGS__, (XIEITE_DETAIL_LOOP_BREAK = true)) \
                    if ((XIEITE_DETAIL_LOOP_BREAK = false)); \
                    else

#   define XIEITE_LOOP_WHILE(...) XIEITE_LOOP_FOR(; __VA_ARGS__; 0)

#endif

// Blatantly stolen from m1lkweed (https://gist.github.com/m1lkweed/3be672402c43ac5697f1e29bcb79e004)
// TODO: Somehow prevent an overloaded `operator,` from doing anything in the second nested for-loop
