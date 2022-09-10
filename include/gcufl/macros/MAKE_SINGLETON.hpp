#pragma once

#define MAKE_SINGLETON(Class)                  \
    private:                                   \
        Class() {}                             \
    public:                                    \
        static Class& getInstance() noexcept { \
            static Class instance;             \
            return instance;                   \
        }                                      \
        Class(const Class&) = delete;          \
        Class& operator=(const Class&) = delete;
