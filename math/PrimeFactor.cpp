#include "PrimeFactor.hpp"

PrimeFactor::PrimeFactor(uint64_t value) : value(value) {
    uint64_t calc_base = value;
    for (uint64_t index = 2; index * index <= calc_base; index++) {
        while (calc_base % index == 0) {
            factor_result[index]++;
            calc_base /= index;
        }
    }
    if (calc_base != 1) factor_result[calc_base]++;
}

std::uint64_t PrimeFactor::get_value() const {
    return value;
}

const std::map<std::uint64_t, std::uint64_t> &PrimeFactor::query() const { 
    return factor_result;
}