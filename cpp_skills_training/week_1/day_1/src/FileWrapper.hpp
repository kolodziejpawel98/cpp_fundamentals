#include <iostream>
#include <fstream>
#include <string>
#include <optional>

#pragma once

class FileWrapper
{
public:
    FileWrapper(const char *fileName)
    {
        file.open(fileName, std::ios::in);
        if (!file)
        {
            throw std::runtime_error("No file found!");
        }
    }

    FileWrapper(FileWrapper &&) noexcept = default;
    FileWrapper &operator=(FileWrapper &&) noexcept = default;

    FileWrapper(const FileWrapper &ob) = delete;

    std::optional<std::string> getLine()
    {
        std::string line;
        if (std::getline(file, line))
        {
            return line;
        }
        return std::nullopt;
    }

private:
    std::ifstream file;
};
