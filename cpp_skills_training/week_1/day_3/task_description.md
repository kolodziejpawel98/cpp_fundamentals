# 2) Hierarchia z `override` i `final`

### Teoria — pytania

* Co oznacza słowo kluczowe `override` i co wykryje kompilator?
* Czym jest „object slicing” i jak go odtworzyć w testach?
* Do czego służy `final` na metodzie vs na klasie?

### Zadanie

Stwórz hierarchię:

* `struct Shape { virtual ~Shape(); virtual double area() const = 0; virtual std::string name() const; }`
* `struct Rectangle : Shape { double w,h; ... }`
* `struct Circle : Shape { double r; ... }`
* `struct Square final : Rectangle { ... }`
* W `Rectangle::name()` i `Circle::name()` użyj `override`.
* Oznacz `Square` jako `final`. Spróbuj utworzyć pochodną `struct FancySquare : Square` (ma się nie kompilować — trzymaj to w oddzielnym pliku/komentarzu do testu kompilacji).

Dodaj fabrykę: `std::unique_ptr<Shape> make_shape(...)`, polimorficzne wywołania i kontener `std::vector<std::unique_ptr<Shape>>`.

### Wymagania i edge-case’y

* Precyzyjne typy zwracane, `const` poprawność metod.
* `area()` musi działać poprawnie polimorficznie.
* `name()` w bazie nie-czysto wirtualne i ma zwrócić „Shape”.
* Zademonstruj slicing przez kopię `Rectangle` do `Shape` by value (w osobnym fragmencie) i pokaż, co się traci.

### Co przetestować

* Polimorfizm:

  * wektor `unique_ptr<Shape>` z różnymi kształtami, suma pól zgodna.
* `override` w akcji:

  * sprawdź `name()` zwraca właściwe nazwy wirtualnie.
* `final`:

  * test „kompilacyjny”: plik, który próbuje dziedziczyć po `Square` i powinien failować w CI (jeśli robisz).
* Slicing:

  * przypisz `Rectangle` do `Shape` by value, porównaj zachowanie z wskaźnikiem/referencją.
* Wartości brzegowe:

  * promień/ wymiary 0 → area 0; ujemne → oczekuj `std::invalid_argument`.

### Rozszerzenia

* Dodaj `Triangle` i testy równania Herona.
* Wprowadź `virtual std::string info() const` i sprawdź dynamic\_cast.

---