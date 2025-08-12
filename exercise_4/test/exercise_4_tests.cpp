#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include <typeinfo>
#include "Task.hpp"

TEST(fileTodoManagerTest, basicFunctionality)
{
    Task(123, "description", std::chrono::system_clock::from_time_t(123), Priority::Low, false);
}