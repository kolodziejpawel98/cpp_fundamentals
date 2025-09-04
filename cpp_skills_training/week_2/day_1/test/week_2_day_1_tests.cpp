#include <gtest/gtest.h>
#include "Library.hpp"

TEST(week_2_day_1, book)
{
    Book book{"Blackout", std::make_pair("John", "Pork")};
    EXPECT_EQ(book.info(), "Blackout John Pork");
}

TEST(week_2_day_1, basic_scenario)
{
    Library library{};
    library.addBook("Blackout", std::make_pair("John", "Pork"));

    Reader janKowalski{std::make_pair("Jan", "Kowalski")};
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 0);

    janKowalski.borrowBook(library.borrowBook("Blackout"));
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 1);

    EXPECT_THROW(library.addBook("Blackout", std::make_pair("John", "Pork")), std::invalid_argument);
}

TEST(week_2_day_1, adding_same_book_two_times)
{
    Library library{};
    EXPECT_EQ(library.getNumberOfBooks(), 0);

    library.addBook("Blackout", std::make_pair("John", "Pork")); // should I maybe pass Book object here?
    EXPECT_EQ(library.getNumberOfBooks(), 1);

    library.addBook("Blackout", std::make_pair("x", "y"));
    EXPECT_EQ(library.getNumberOfBooks(), 2);

    EXPECT_THROW(library.addBook("Blackout", std::make_pair("John", "Pork")), std::invalid_argument);
}

TEST(week_2_day_1, two_people_wants_to_borrow_same_book)
{
    Library library{};
    library.addBook("Blackout", std::make_pair("John", "Pork"));

    Reader janKowalski{std::make_pair("Jan", "Kowalski")};
    Reader piotrNowak{std::make_pair("Piotr", "Nowak")};

    janKowalski.borrowBook(library.borrowBook("Blackout"));
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 1);

    EXPECT_THROW(piotrNowak.borrowBook(library.borrowBook("Blackout")), std::invalid_argument);
}

// TODO:
//  - maybe Library::getBook() should get Book object instead of arguments?
//  - Library::borrowBook() must get authors name also
//  - add returning book to library logic