#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <algorithm>

#pragma once

class Book
{
public:
    Book(std::string title, std::pair<std::string, std::string> author) : title(title), author(author), isAvailable(true) {};

    std::string info() const
    {
        return title + " " + author.first + " " + author.second;
    }

    std::string getTitle() const
    {
        return title;
    }

    std::pair<std::string, std::string> getAuthor() const
    {
        return author;
    }

    bool getAvailability() const
    {
        return isAvailable;
    }

    void setAvailability(bool isAvailable)
    {
        this->isAvailable = isAvailable;
    }

private:
    std::string title;
    std::pair<std::string, std::string> author;
    bool isAvailable;
};

class Reader
{
public:
    explicit Reader(std::pair<std::string, std::string> name) : name(name) {};

    void borrowBook(std::shared_ptr<Book> book)
    {
        // check nullpt?
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
    void addBook(const std::string &title, const std::pair<std::string, std::string> &author)
    {
        auto it = std::find_if(books.begin(), books.end(),
                               [&title, &author](const std::shared_ptr<Book> &book)
                               {
                                   return book->getTitle() == title && book->getAuthor() == author;
                               });
        if (it == books.end())
        {
            books.push_back(std::make_shared<Book>(title, author));
        }
        else
        {
            throw std::invalid_argument("That book already stored in library.");
        }
    }

    std::shared_ptr<Book> borrowBook(const std::string &title)
    {
        auto it = std::find_if(books.begin(), books.end(),
                               [&title](const std::shared_ptr<Book> &book)
                               {
                                   return book->getTitle() == title;
                               });
        if (it == books.end())
        {
            throw std::invalid_argument("That book is not in the library.");
        }
        else if (!(*it)->getAvailability())
        {
            throw std::invalid_argument("Book already borrowed.");
        }
        else
        {
            (*it)->setAvailability(false);
            return *it;
        }
    }

    size_t getNumberOfBooks() const
    {
        return books.size();
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

// class Loan
// {
// public:
//     bool isValid();

// private:
//     std::weak_ptr<Reader> reader;
//     std::weak_ptr<Book> book;
// };