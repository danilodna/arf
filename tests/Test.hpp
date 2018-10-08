#ifndef TEST_H_
#define TEST_H_

#include "../include/Common.hpp"
#include <iostream>
#include <string>
#include <map>
#include <functional>

class Test
{
protected:
    Test() = default;

public:
    virtual ~Test() = default;

    virtual void onUpdate(float deltaTime) { }
    virtual void onRender() { }
    virtual void onImGuiRender() = 0;
};

#endif // TEST_H_