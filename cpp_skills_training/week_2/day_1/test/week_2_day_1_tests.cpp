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

    janKowalski.borrowBook(library.borrowBook("Blackout", std::make_pair("John", "Pork")));
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 1);

    EXPECT_THROW(library.addBook("Blackout", std::make_pair("John", "Pork")), std::invalid_argument);
}

TEST(week_2_day_1, adding_same_book_two_times)
{
    Library library{};
    EXPECT_EQ(library.getNumberOfBooks(), 0);

    library.addBook("Blackout", std::make_pair("John", "Pork"));
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

    janKowalski.borrowBook(library.borrowBook("Blackout", std::make_pair("John", "Pork")));
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 1);

    EXPECT_THROW(piotrNowak.borrowBook(library.borrowBook("Blackout", std::make_pair("John", "Pork"))), std::invalid_argument);
}

TEST(week_2_day_1, borrow_not_existed_book)
{
    Library library{};
    library.addBook("Blackout", std::make_pair("John", "Pork"));

    Reader janKowalski{std::make_pair("Jan", "Kowalski")};

    EXPECT_THROW(janKowalski.borrowBook(library.borrowBook("Game Of Thrones", std::make_pair("George", "Martin"))), std::invalid_argument);
}

TEST(week_2_day_1, reader_returns_book)
{
    Library library{};
    library.addBook("Blackout", std::make_pair("John", "Pork"));

    Reader janKowalski{std::make_pair("Jan", "Kowalski")};
    janKowalski.borrowBook(library.borrowBook("Blackout", std::make_pair("John", "Pork")));
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 1);

    std::shared_ptr<Book> returnedBook = janKowalski.returnBook("Blackout", std::make_pair("John", "Pork"));
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 0);
    EXPECT_EQ(returnedBook->getTitle(), "Blackout");

    EXPECT_THROW(janKowalski.returnBook("Game Of Thrones", std::make_pair("George", "Martin")), std::invalid_argument);
}

TEST(week_2_day_1, library_get_returned_book)
{
    Library library{};
    library.addBook("Blackout", std::make_pair("John", "Pork"));
    EXPECT_TRUE(library.isBorrowingPossible("Blackout", std::make_pair("John", "Pork")));

    Reader janKowalski{std::make_pair("Jan", "Kowalski")};
    janKowalski.borrowBook(library.borrowBook("Blackout", std::make_pair("John", "Pork")));
    EXPECT_FALSE(library.isBorrowingPossible("Blackout", std::make_pair("John", "Pork")));

    library.retrieveReturnedBook(janKowalski.returnBook("Blackout", std::make_pair("John", "Pork")));
    EXPECT_TRUE(library.isBorrowingPossible("Blackout", std::make_pair("John", "Pork")));
}