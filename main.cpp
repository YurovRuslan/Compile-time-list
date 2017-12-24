#include <iostream>

template<int32_t v>
struct Int {
    static constexpr int32_t value = v;
};

struct NIL {
    typedef NIL Head;
    typedef NIL Tail;
};

template<class H, class T = NIL>
struct List {
    typedef H Head;
    typedef T Tail;
};

int main() {
    typedef List<Int<1>, List<Int<2>>> lst;
    return 0;
}