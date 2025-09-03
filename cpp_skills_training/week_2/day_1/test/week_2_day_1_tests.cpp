#include <gtest/gtest.h>
#include "Library.hpp"

TEST(week_2_day_1, book)
{
    Library library{};
    library.addBook("Blackout", std::make_pair("John", "Pork"));
    EXPECT_EQ(book.info(), "Blackout John Pork");
}

// TEST(week_2_day_1, reader)
// {
//     Book book{"Blackout", std::make_pair("John", "Pork")};
//     EXPECT_EQ(book.info(), "Blackout John Pork");
// }

TEST(week_2_day_1, basic_scenario)
{
    Library library{};
    library.addBook("Blackout", std::make_pair("John", "Pork"));
    Reader janKowalski{std::make_pair("Jan", "Kowalski")};
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 0);
    library.borrowBook(janKowalski, "Blackout", std::make_pair("John", "Pork"));
    EXPECT_EQ(janKowalski.getNumberOfBorrowedBooks(), 1);
}