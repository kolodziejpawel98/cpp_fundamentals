#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>

enum class Priority
{
    Low,
    Medium,
    High
};

class Task
{
public:
    Task(int id, std::string desc, std::chrono::system_clock::time_point due, Priority prio, bool isDone)
        : id(id), description(std::move(desc)), dueDate(due), priority(prio), isDone(isDone) {}

private:
    int id;
    std::string description;
    std::chrono::system_clock::time_point dueDate;
    Priority priority;
    bool isDone;
};