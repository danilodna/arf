#include "TestClearColor.hpp"

TestClearColor::TestClearColor() :
    m_clearColor { 0.2f, 0.4f, 0.6f, 1.0f }
{

}

void TestClearColor::onRender()
{
    glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

void TestClearColor::onImGuiRender()
{
    ImGui::ColorEdit4("Clear Color", m_clearColor);
}
