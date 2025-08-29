
~~# 4) `constexpr` funkcja licząca silnię~~

~~ ### Teoria — pytania~~

~~ * Różnice między `constexpr` a `consteval` i kiedy użyć którego?~~
~~* Co oznacza, że wyrażenie jest ewaluowane w czasie kompilacji?~~
~~* Jak ograniczyć domenę (np. przepełnienie) na etapie kompilacji?~~

~~### Zadanie~~

~~Napisz:~~

~~```cpp~~
~~constexpr unsigned long long factorial(unsigned n);~~
~~```~~

~~Wersja iteracyjna lub~~ rekurencyjna. Dodaj `static_assert` dla kilku wartości. Zaimplementuj też `consteval` wariant do obliczeń stricte w CT jeśli chcesz.

### Wymagania i edge-case’y

~~* `factorial(0)==1`.~~
* Zabezpiecz overflow: dla `n` powyżej granicy typu zrób `throw` w czasie wykonywania lub `static_assert` w CT dla stałych (np. maksymalnie 20 dla `uint64_t`).
* Funkcja ma być używalna w kontekście stałym: rozmiar tablicy, parametr szablonu, `std::array<N>`.

### Co przetestować

* `static_assert(factorial(0)==1);`
* `static_assert(factorial(5)==120);`
* Użycie w `std::array<int, factorial(5)>` kompiluje się.
* Testy runtime dla wartości losowych w zakresie 0–12.
* Sprawdzenie błędu/wyjątku dla zbyt dużego `n` (tylko runtime).
* Porównanie wyników z tabelą znanych wartości.

### Rozszerzenia

* Dodaj `consteval factorial_ct(unsigned)` i pokaż różnicę w diagnostyce.
* Zaimplementuj wersję na `std::uint128_t` (jeśli masz).

---