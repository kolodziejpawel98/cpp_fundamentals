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

private:
    std::string title;
    std::pair<std::string, std::string> author;
};

class Reader
{
private:
    std::pair<std::string, std::string> name;
    std::vector<std::shared_ptr<Book>> borrowedBooks;
};

class Library
{
public:
    std::unique_ptr<Book> addBook(std::string title, std::pair<std::string, std::string> author);
    std::shared_ptr<Book> borrowBook(std::string title, std::pair<std::string, std::string> author);

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