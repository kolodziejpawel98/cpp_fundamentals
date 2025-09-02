#include <gtest/gtest.h>
#include "Library.hpp"

TEST(week_2_day_1, getLIne)
{
    Library library{};
    library.books.push_back(library.addBook("Blackout", std::make_pair("John", "Pork")));
    library.borrowBook("Blackout", std::make_pair("John", "Pork"));
    Reader adam{std::make_pair("Adam", "Kowalski")};
    adam.borrowedBooks.push_back(library.borrowBook("Blackout", std::make_pair("John", "Pork")));
}
