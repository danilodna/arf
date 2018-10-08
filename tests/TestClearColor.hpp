#ifndef TEST_CLEAR_COLOR_HPP_
#define TEST_CLEAR_COLOR_HPP_

#include "Test.hpp"

class TestClearColor : public Test
{
private:
    float m_clearColor[4];

public:
    TestClearColor();
    ~TestClearColor() = default;

    void onRender() override;
    void onImGuiRender() override;
};

#endif // TEST_CLEAR_COLOR_HPP_