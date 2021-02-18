#include <iostream>
#include <bitset>
static inline uint64_t DoubleShiftRight(uint64_t first,
                                        uint64_t second,
                                        uint8_t shift) {
    asm("shrdq %1, %0" : "+r"(first) : "r"(second), "c"(shift) : "cc");
    return first;
}
int main() {
//    uint64_t a = 0b11111111;
//    uint64_t b = 0b11110001;
//    uint64_t c = DoubleShiftRight(a, b, 59);

//    std::cout << std::bitset<64>(DoubleShiftRight(a, b, 64)) << std::endl;
//    std::cout << std::bitset<64>(18446744073479464082) << std::endl;
//    std::cout << std::bitset<64>(10540996613548315209) << std::endl;
//    std::cout << std::bitset<64>(2635249153387078802) << std::endl;
//    std::cout << std::bitset<64>(2635249153348730880) << std::endl;
//    std::cout << std::bitset<64>(5270498306774157604) << std::endl;
//    std::cout << std::bitset<64>(18446744073479464082) << std::endl;
    std::cout << std::bitset<64>(1229782933666004992) << std::endl;
}