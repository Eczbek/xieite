#pragma once

#define MAKE_SINGLETON(Singleton)                  \
    private:                                       \
        Singleton() {}                             \
    public:                                        \
        static Singleton& getInstance() noexcept { \
            static Singleton instance;             \
            return instance;                       \
        }                                          \
        Singleton(const Singleton&) = delete;      \
        Singleton& operator=(const Singleton&) = delete

#define QUOTE(expression) #expression
