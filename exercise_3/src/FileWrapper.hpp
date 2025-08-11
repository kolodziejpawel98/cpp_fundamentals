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

    FileWrapper(const FileWrapper &) = delete;
    FileWrapper &operator=(const FileWrapper &) = delete;

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

    FileWrapper &operator=(FileWrapper &&other) noexcept
    {
        if (this != &other)
        {
            this->file = other.file;
            other.file = nullptr;
        }
        return *this;
    }

    void write(const std::string &text) // IN PROGRESS
    {
        if (file != nullptr)
        {
            std::size_t written = std::fwrite(&text, 1, text.size(), file);

            if (written != text.size())
            {
                std::perror("Writing error");
            }
        }
    }

    ~FileWrapper()
    {
        if (file != nullptr)
        {
            std::fclose(file);
        }
    }

private:
    FILE *file;
};