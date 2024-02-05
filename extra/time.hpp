#pragma once

#include <stddef.h>
#include <type_traits>

namespace estd
{

struct microseconds
{
    long unsigned int value;
};

struct milliseconds
{
    long unsigned int value;
};

struct seconds
{
    long unsigned int value;
};

struct minutes
{
    long unsigned int value;
};

struct hours
{
    long unsigned int value;
};

template <typename To, typename From> To time_cast(From from)
{
    if constexpr (std::is_same<To, microseconds>::value)
    {
        if constexpr (std::is_same<From, microseconds>::value)
        {
            return from;
        }
        else if constexpr (std::is_same<From, milliseconds>::value)
        {
            return {from.value * 1000};
        }
        else if constexpr (std::is_same<From, seconds>::value)
        {
            return {from.value * 1000000};
        }
        else if constexpr (std::is_same<From, minutes>::value)
        {
            return {from.value * 60000000};
        }
        else if constexpr (std::is_same<From, hours>::value)
        {
            return {from.value * 3600000000};
        }
    }
    else if constexpr (std::is_same<To, milliseconds>::value)
    {
        if constexpr (std::is_same<From, microseconds>::value)
        {
            return {from.value / 1000};
        }
        else if constexpr (std::is_same<From, milliseconds>::value)
        {
            return from;
        }
        else if constexpr (std::is_same<From, seconds>::value)
        {
            return {from.value * 1000};
        }
        else if constexpr (std::is_same<From, minutes>::value)
        {
            return {from.value * 60000};
        }
        else if constexpr (std::is_same<From, hours>::value)
        {
            return {from.value * 3600000};
        }
    }
    else if constexpr (std::is_same<To, seconds>::value)
    {
        if constexpr (std::is_same<From, microseconds>::value)
        {
            return {from.value / 1000000};
        }
        else if constexpr (std::is_same<From, milliseconds>::value)
        {
            return {from.value / 1000};
        }
        else if constexpr (std::is_same<From, seconds>::value)
        {
            return from;
        }
        else if constexpr (std::is_same<From, minutes>::value)
        {
            return {from.value * 60};
        }
        else if constexpr (std::is_same<From, hours>::value)
        {
            return {from.value * 3600};
        }
    }
    else if constexpr (std::is_same<To, minutes>::value)
    {
        if constexpr (std::is_same<From, microseconds>::value)
        {
            return {from.value / 60000000};
        }
        else if constexpr (std::is_same<From, milliseconds>::value)
        {
            return {from.value / 60000};
        }
        else if constexpr (std::is_same<From, seconds>::value)
        {
            return {from.value / 60};
        }
        else if constexpr (std::is_same<From, minutes>::value)
        {
            return from;
        }
        else if constexpr (std::is_same<From, hours>::value)
        {
            return {from.value * 60};
        }
    }
    else if constexpr (std::is_same<To, hours>::value)
    {
        if constexpr (std::is_same<From, microseconds>::value)
        {
            return {from.value / 3600000000};
        }
        else if constexpr (std::is_same<From, milliseconds>::value)
        {
            return {from.value / 3600000};
        }
        else if constexpr (std::is_same<From, seconds>::value)
        {
            return {from.value / 3600};
        }
        else if constexpr (std::is_same<From, minutes>::value)
        {
            return {from.value / 60};
        }
        else if constexpr (std::is_same<From, hours>::value)
        {
            return from;
        }
    }
    return {};
}
} // namespace estd