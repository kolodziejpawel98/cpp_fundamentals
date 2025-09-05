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
        borrowedBooks.push_back(book);
    }

    size_t getNumberOfBorrowedBooks() const
    {
        return borrowedBooks.size();
    }

    std::shared_ptr<Book> returnBook(const std::string &title, const std::pair<std::string, std::string> &author)
    {
        if (borrowedBooks.size() == 0)
            throw std::invalid_argument("You don't have any borrowed book");

        auto it = std::find_if(borrowedBooks.begin(), borrowedBooks.end(),
                               [&title, &author](const std::shared_ptr<Book> &book)
                               {
                                   return book->getTitle() == title && book->getAuthor() == author;
                               });

        if (it == borrowedBooks.end())
        {
            throw std::invalid_argument("You haven't borrowed this book");
        }
        else
        {
            auto bookToReturn = std::move(*it);
            borrowedBooks.erase(it);
            return bookToReturn;
        }
    }

private:
    std::pair<std::string, std::string> name;
    std::vector<std::shared_ptr<Book>> borrowedBooks;
};

// class Borrowing
// {
// public:
//     Borrowing(std::weak_ptr<Reader> reader, std::weak_ptr<Book> book) : reader(reader), book(book) {}

// private:
//     std::weak_ptr<Reader> reader;
//     std::weak_ptr<Book> book;
// };

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

    std::shared_ptr<Book> borrowBook(/*Reader &reader, */ const std::string &title, const std::pair<std::string, std::string> &author)
    {
        auto it = std::find_if(books.begin(), books.end(),
                               [&title, &author](const std::shared_ptr<Book> &book)
                               {
                                   return book->getTitle() == title && book->getAuthor() == author;
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
            // std::weak_ptr<Reader> readerWeak = std::make_shared<Reader>(reader);
            // borrowings.emplace_back(readerWeak, *it);
            (*it)->setAvailability(false);
            return *it;
        }
    }

    void retrieveReturnedBook(/*Reader &reader, */ std::shared_ptr<Book> returnedBook)
    {
        auto it = std::find(books.begin(), books.end(), returnedBook);

        if (it == books.end())
        {
            throw std::invalid_argument("That book doesn't belong to that library.");
        }
        else
        {

            (*it)->setAvailability(true);
        }
    }

    bool isBorrowingPossible(const std::string &title, const std::pair<std::string, std::string> &author)
    {
        auto it = std::find_if(books.begin(), books.end(),
                               [&title, &author](const std::shared_ptr<Book> &book)
                               {
                                   return book->getTitle() == title && book->getAuthor() == author;
                               });
        if (it == books.end())
        {
            throw std::invalid_argument("That book doesn't belong to that library.");
        }
        else
        {
            return (*it)->getAvailability();
        }
    }

    size_t getNumberOfBooks() const
    {
        return books.size();
    }

private:
    std::vector<std::shared_ptr<Book>> books;
    // std::vector<Borrowing> borrowings;
};
