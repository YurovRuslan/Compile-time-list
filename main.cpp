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

template<class LIST>
struct Length {
    typedef class LIST::Tail Tail;
    static constexpr uint32_t length = 1 + Length<Tail>::length;
};

template<>
struct Length<NIL> {
    static constexpr uint32_t length = 0;
};

int main() {
    typedef List<Int<1>, List<Int<2>>> list;
    typedef Length<list> list_length;
    std::cout << list_length::length;
    return 0;
}