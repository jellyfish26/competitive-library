#pragma once
#include <cstdint>
#include <map>

// Last updated 2020-05-14
class PrimeFactor {
private:
    std::map<std::uint64_t , std::uint64_t> factor_result;
    const std::uint64_t value;

public:
    PrimeFactor(std::uint64_t value);

    std::uint64_t get_value() const;
    const std::map<std::uint64_t, std::uint64_t> &query() const;
};