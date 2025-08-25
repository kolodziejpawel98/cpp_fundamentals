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

Dodaj fabrykę: `std::unique_ptr<Shape> make_shape(...)`, polimorficzne wywołania i kontener `std::vector<std::unique_ptr<Shape>>`.’


REVIEW:
API i semantyka
    • Zastanów się, czy jednoargumentowe konstruktory (np. Circle, Square) powinny być konwersyjne, czy jednak wolisz je oznaczyć tak, by przypadkowe konwersje były niemożliwe.
    • Przeanalizuj, czy name() w bazie powinno mieć domyślną implementację, czy wymuszać implementację w pochodnych (co chcesz osiągnąć dydaktycznie?).
    • Pomyśl, czy globalny shapes powinien być publicznie widoczny z nagłówka. Czy wolisz uniknąć globalnego stanu albo przynajmniej ograniczyć jego zasięg?
Wyjątki i walidacja
    • Sprawdź, jakiego mechanizmu rzucania używasz i czy jest to publiczne API standardu, a nie „wewnętrzny helper” konkretnej biblioteki.
    • Ustal spójnie politykę dla argumentów skrajnych (0, liczby ujemne, NaN, inf). Czy wszędzie zachowujesz się tak samo?
    • W fabryce przemyśl, co się dzieje przy złej liczbie parametrów w initializer_list. Czy na pewno zabezpieczasz się przed dereferencją spoza zakresu?
Obliczenia i stałe
    • Oceń, czy stała dla π powinna być precyzyjniejsza i jednoźródłowa (jeden punkt prawdy), a nie „rozsiana” po kodzie testów i implementacji.
    • Rozważ, czy porównania zmiennoprzecinkowe w testach powinny być dokładne, czy raczej z tolerancją.
Fabryka (makeShape)
    • Pomyśl, czy wybór implementacji na podstawie ShapeType jest dla Ciebie bardziej czytelny jako switch z jawnie obsłużonym „defaultem”/błędem.
    • Zastanów się nad zwracaniem wprost wyniku z fabryki, bez wprowadzania lokalnych pojemników, oraz nad atrybutem sugerującym, że wynik trzeba wykorzystać.
    • Przejrzyj, czy użycie iteratorów jest bezpieczne przy krótszych listach i czy nie zaufano nadmiernie initializer_list.
Testy
    • Rozważ EXPECT_NEAR zamiast EXPECT_EQ dla double. Ustal jedną tolerancję i używaj jej wszędzie.
    • Zwróć uwagę, że globalny shapes może zanieczyszczać stan między testami. Czy chcesz czyścić go po każdym teście / w TearDown?
    • Dołóż testy na złe wejścia fabryki (za mało/za dużo parametrów) i skrajne wartości (bardzo duże/małe).
    • Przemyśl, czy test polimorfizmu powinien sprawdzić nie tylko name(), ale też że area() woła się wirtualnie (np. porównanie z oczekiwaną wartością).
    • Zastanów się nad testami parametryzowanymi dla wielu przypadków (wymiary → oczekiwane pole).
Styl i spójność
    • Przejrzyj, czy wszystkie override są konsekwentnie oznaczone, a to, co ma być „ostateczne”, jest odpowiednio zablokowane.
    • Ujednolić komunikaty wyjątków (język, treść) i ewentualnie DRY dla walidacji (żeby nie kopiować tej samej logiki).
    • Pomyśl, czy chcesz dodać atrybuty typu [[nodiscard]] do funkcji, których wynik nie powinien być ignorowany.
Organizacja kodu
    • Zastanów się nad minimalizacją include’ów w nagłówku i przeniesieniem cięższych (<iostream>, <fstream>) tam, gdzie są potrzebne.
    • Przeanalizuj, czy pragma once i ochrona wielokrotnego włączenia są spójne z polityką projektu.








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
