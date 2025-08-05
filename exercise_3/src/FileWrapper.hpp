#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>

class FileWrapper
{
public:
    FileWrapper(const char *pathToOpen)
    {
        file = std::fopen(pathToOpen, "w+");
        if (!file)
        {
            std::perror("File opening failed");
        }
    }

    // FileWrapper(FILE *file) noexcept
    // {
    //     this->file = file;
    //     file = nullptr;
    // }

    FileWrapper(FileWrapper &&other) noexcept
    {
        this->file = other.file;
        other.file = nullptr;
    }

    bool isOpen() const
    {
        return (file == nullptr) ? false : true;
    }

    bool operator==(const FileWrapper &other) const
    {
        if (this->file == other.file)
        {
            return true;
        }
        return false;
    }

    void write(const std::string &text)
    {
        if (!std::feof(file))
        {
            std::cout << "File opened" << std::endl;
        }
    }

    ~FileWrapper()
    {
        std::fclose(file);
    }

private:
    FILE *file;
};