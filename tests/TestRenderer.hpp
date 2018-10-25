#ifndef TEST_RENDERER_GEOMETRY
#define TEST_RENDERER_GEOMETRY

#include "Test.hpp"
#include <memory>

class TestRenderer : public Test
{
private:


public:
    TestRenderer() = default;
    ~TestRenderer() = default;

    void onUpdate(float deltaTime) override;
    void onRender() override;
    void onImGuiRender() override;

    void someFunc();
};


#endif // TEST_RENDERER_GEOMETRY
