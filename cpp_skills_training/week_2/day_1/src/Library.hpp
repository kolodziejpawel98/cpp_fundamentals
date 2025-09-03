#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>
#include <vector>

#pragma once

class Book
{
    friend class Library;

public:
    std::string info()
    {
        return title + " " + author.first + " " + author.second;
    }

    std::string getTitle() const
    {
        return title;
    }

private:
    Book(std::string title, std::pair<std::string, std::string> author) : title(title), author(author) {};

    std::string title;
    std::pair<std::string, std::string> author;
};

class Reader
{
public:
    Reader(std::pair<std::string, std::string> name) : name(name) {};

    void setName(std::pair<std::string, std::string> name)
    {
        this->name = name;
    }

    void addBorrowedBook(std::shared_ptr<Book> book)
    {
        borrowedBooks.push_back(book);
    }

    size_t getNumberOfBorrowedBooks() const
    {
        return borrowedBooks.size();
    }

private:
    std::pair<std::string, std::string> name;
    std::vector<std::shared_ptr<Book>> borrowedBooks;
};

class Library
{
public:
    void addBook(std::string title, std::pair<std::string, std::string> author)
    {
        books.push_back(std::make_unique<Book>(title, author));
    }

    void borrowBook(Reader &reader, std::string title, std::pair<std::string, std::string> author)
    {
        for (auto &book : books)
        {
            if (book->getTitle() == title)
            {
                reader.addBorrowedBook(std::make_shared<Book>(title, author));
                return;
            }
        }
        throw std::invalid_argument("That book is not in the library");
    }

    // std::unique_ptr<Book> getBook(std::string title) const
    // {
    //     for (auto &book : books)
    //     {
    //         if (book->getTitle() == title)
    //         {
    //             return ? ? ? ;
    //         }
    //     }
    //     throw std::invalid_argument("That book is not in the library");
    // }

private:
    std::vector<std::unique_ptr<Book>> books;
};

// class Loan
// {
// public:
//     bool isValid();

// private:
//     std::vector<std::unique_ptr<Book>> books;
// };

class Loan
{
public:
    bool isValid();

private:
    std::weak_ptr<Reader> reader;
    std::weak_ptr<Book> book;
};