🧩 Task: Managing a file resource using RAII and smart pointers
Goal:

Create a FileWrapper class that manages a text file safely, ensuring proper opening and closing of the file using RAII principles and smart pointers to avoid resource leaks and double closures.
Task details:

    FileWrapper class

        In the constructor, open a file given its path (e.g., using std::fopen).

        In the destructor, close the file (e.g., std::fclose).

        Disable copying (delete copy constructor and copy assignment operator).

        Support move semantics (move constructor and move assignment operator).

        Use an appropriate smart pointer (unique_ptr with a custom deleter or shared_ptr) to manage the FILE* pointer.

        Add methods:

            bool isOpen() const — returns whether the file is currently open.

            void write(const std::string &text) — appends text to the file (check if file is open).

    Unit tests (e.g. with GoogleTest) — step-by-step:

        Test creation and destruction of FileWrapper:

            Create a FileWrapper object that opens a new file.

            Check that isOpen() returns true.

            Destroy the object and verify the file is closed (indirectly — e.g., by trying to reopen the same file exclusively).

        Test copy prevention:

            Attempt to compile code that copies a FileWrapper (e.g., FileWrapper f2 = f1;).

            This should fail because copy operations are deleted.

        Test move semantics:

            Create a FileWrapper and write some text.

            Move it to another object (FileWrapper f2 = std::move(f1);).

            Verify that the file is open in f2, and that f1 no longer owns the file (is “empty”).

            Try writing to the file using f2 — it should work.

            Try writing using f1 — it should throw or do nothing.

        Test writing to the file:

            Create a FileWrapper and write some text.

            Destroy the object (which closes the file).

            Read the file from disk and verify the contents are as expected.

Hints (without full code):

    Think about how unique_ptr allows custom deleters — perfect for managing FILE*.

    Use move constructors and move assignment to transfer ownership safely.

    Delete copy operations explicitly.

    Use std::move in tests to check moving behavior.

    Tests might need to create temporary files — consider setup and teardown for cleanup.