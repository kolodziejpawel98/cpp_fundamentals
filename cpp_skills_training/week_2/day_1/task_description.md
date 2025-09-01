## 💡 Zadanie — „Model biblioteki”

**Cel:** przećwiczenie `unique_ptr`, `shared_ptr` i `weak_ptr` w jednym projekcie.

---

### Opis

Napisz prosty model systemu biblioteki:

* **Książka** (`Book`)

  * trzymana wewnętrznie w bibliotece,
  * obiekt zarządzany przez `unique_ptr` (biblioteka ma pełną własność).

* **Czytelnik** (`Reader`)

  * może wypożyczać książki,
  * potrzebujesz współdzielonego dostępu, bo książka powinna istnieć dopóki ktoś ją wypożycza → użyj `shared_ptr`.

* **Wypożyczenie** (`Loan`)

  * łączy czytelnika i książkę,
  * aby nie tworzyć cyklu (Reader ↔ Loan ↔ Book), w jednym miejscu użyj `weak_ptr`.
  * np. `Loan` może trzymać `weak_ptr<Reader>` i `weak_ptr<Book>`.

---

### Zadanie – szczegóły implementacyjne

~~1. **Klasa `Book`**~~

   ~~* ma tytuł i autora,~~
   ~~* metoda `info()`.~~

~~2. **Klasa `Reader`**~~

  ~~ * ma imię,~~
   ~~* lista aktualnie wypożyczonych książek (`std::vector<std::shared_ptr<Book>>`).~~

3. **Klasa `Library`**

   * przechowuje wszystkie książki w kolekcji (np. `std::vector<std::unique_ptr<Book>>`).
   * metoda `add_book(title, author)` zwraca wskaźnik do książki.
   * metoda `borrow_book(reader, title)` zwraca `shared_ptr<Book>` — książka przechodzi do czytelnika, ale pozostaje też w bibliotece.

4. **Klasa `Loan`**

   * przechowuje informację, kto wypożyczył którą książkę,
   * używa `weak_ptr` do czytelnika i książki (żeby nie utrwalać obiektów sztucznie).
   * metoda `is_valid()` sprawdza, czy obiekt czytelnika/książki nadal istnieje (`lock()`).

---

### Wymagania

* Biblioteka ma być jedynym właścicielem książek (`unique_ptr`).
* Czytelnik ma dostęp do książki tylko wtedy, gdy istnieje (przez `shared_ptr`).
* Wypożyczenie (`Loan`) nie może utrzymywać obiektów przy życiu — dlatego `weak_ptr`.
* Jeśli czytelnik zostanie usunięty, to wszystkie jego wypożyczenia stają się nieaktywne.

---

### Co przetestować

* Dodanie kilku książek do biblioteki i wypożyczenie ich.
* Licznik referencji w `shared_ptr` rośnie po wypożyczeniu.
* Usunięcie czytelnika → sprawdzenie, że `Loan::is_valid()` zwraca `false`.
* Po zakończeniu programu wszystkie obiekty są poprawnie zwalniane (możesz dodać logi w destruktorach).
