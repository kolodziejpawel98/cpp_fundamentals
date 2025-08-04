#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>

class FileWrapper
{
public:
    FileWrapper(const char *pathToOpen)
    {
        fp = std::fopen(pathToOpen, "w+");
        if (!fp)
        {
            std::perror("File opening failed");
        }
    }

    FileWrapper(FILE *fp) noexcept
    {
        this->fp = fp;
        fp = nullptr;
    }

    bool isOpen() const
    {
        return (fp == nullptr) ? false : true;
    }

    void write(const std::string &text)
    {
        if (!std::feof(fp))
        {
            std::cout << "File opened" << std::endl;
        }
    }

    ~FileWrapper()
    {
        std::fclose(fp);
    }

private:
    FILE *fp;
};