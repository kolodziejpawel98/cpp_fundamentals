#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <algorithm>

#pragma once

class Document
{
public:
    Document() = default;
    Document(std::string title, std::vector<char> content) : title(title), content(content) {}
    static int numberOfExistingDocuemnts;

private:
    std::string title;
    std::vector<char> content;
};

