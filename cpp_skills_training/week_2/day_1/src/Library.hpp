#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>
#include <vector>

#pragma once

class Book
{
public:
    Book(std::string title, std::pair<std::string, std::string> author) : title(title), author(author) {};
    std::string info()
    {
        return title + " " + author.first + " " + author.second;
    }

    std::string getTitle() const
    {
        return title;
    }

private:
    std::string title;
    std::pair<std::string, std::string> author;
};

class Reader
{
public:
    Reader(std::pair<std::string, std::string> name) : name(name) {};

    // private:
    std::pair<std::string, std::string> name;
    std::vector<std::shared_ptr<Book>> borrowedBooks;
};

class Library
{
public:
    [[nodiscard]] std::unique_ptr<Book> addBook(std::string title, std::pair<std::string, std::string> author)
    {
        return std::make_unique<Book>(title, author);
    }

    std::shared_ptr<Book> borrowBook(std::string title, std::pair<std::string, std::string> author)
    {
        for (auto &book : books)
        {
            if (book->getTitle() == title)
            {
                return std::make_shared<Book>(title, author);
            }
        }
        throw std::invalid_argument("That book is not in the library");
    }

    std::vector<std::unique_ptr<Book>> books;
};

class Loan
{
public:
    bool isValid();

private:
    std::vector<std::unique_ptr<Book>> books;
};

class Loan
{
public:
    bool isValid();

private:
    std::weak_ptr<Reader> reader;
    std::weak_ptr<Book> book;
};