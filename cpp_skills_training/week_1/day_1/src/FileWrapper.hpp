#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>

#pragma once

// version #1
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

struct FileCloser //?????????????????
{
    void operator()(FILE *f) const noexcept
    {
        if (f)
            std::fclose(f);
    }
};

// version #2
class FileWrapperV2
{
public:
    FileWrapperV2(const char *pathToOpen) : file_(std::fopen(pathToOpen, "r"))
    {
        if (!file_)
            throw std::runtime_error("open failed");
    }

    FileWrapperV2(FileWrapperV2 &&) noexcept = default;
    FileWrapperV2 &operator=(FileWrapperV2 &&) noexcept = default;
    FileWrapperV2(FileWrapperV2 &) = delete;
    // FileWrapperV2 &operator=(FileWrapperV2 &&) = delete;

    bool getLine()
    {
        int c;
        while ((c = fgetc(file_.get())) != EOF)
        {
            return true;
        }
        return false;
    }

private:
    std::unique_ptr<FILE, FileCloser> file_;
};
