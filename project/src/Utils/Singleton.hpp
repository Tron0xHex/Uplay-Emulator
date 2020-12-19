#pragma once

#include "src/pch.h"

namespace UplayR1Loader
{
    using namespace std;

    template <class T>
    class SingletonBase
    {
    public:
        static T& Instance()
        {
            static const shared_ptr<T> INSTANCE{ new T{} };
            return *INSTANCE;
        }
    };

    template <class T>
    class Singleton : public SingletonBase<Singleton<T>>
    {
        T Value;

    public:
        void Set(T value)
        {
            Value = value;
        }
        T& Get()
        {
            return Value;
        }
    };
} // namespace UbiorbitapiR2Loader
