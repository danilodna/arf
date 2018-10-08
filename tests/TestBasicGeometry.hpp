#ifndef TEST_BASIC_GEOMETRY
#define TEST_BASIC_GEOMETRY

#include "Test.hpp"
#include <memory>

class TestBasicGeometry : public Test
{
private:
    std::unique_ptr<GLuint> m_VAO;
    std::unique_ptr<GLuint> m_VBO;

public:
    TestBasicGeometry() = default;
    ~TestBasicGeometry() = default;

    void onUpdate(float deltaTime) override;
    void onRender() override;
    void onImGuiRender() override;

    void someFunc();
};


#endif // TEST_BASIC_GEOMETRY
