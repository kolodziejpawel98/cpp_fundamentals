<!-- Dzień 2 — shared_ptr i weak_ptr (wersja rozszerzona)

Krok po kroku
~~1) Instrumentacja obiektów~~

~~Zrób typ węzła grafu z identyfikatorem i listą sąsiadów.~~

~~Dodaj licznik żyjących instancji oraz destruktor wypisujący zniszczenie węzła.~~

~~Dodaj metodę printNeighbors(). W wersji z weak_ptr zamieniaj przez lock(), wypisuj expired, gdy węzeł już nie istnieje.~~

~~2) Wersja A — sąsiedzi jako shared_ptr~~

~~Zbuduj dwa węzły a, b.~~

~~ Połącz wzajemnie: a → b i b → a (cykl). ~~

Wypisz use_count() dla obu po każdym etapie: po utworzeniu, po dodaniu krawędzi, tuż przed wyjściem ze scope’a.

Zakończ funkcję (żaden zewnętrzny wskaźnik nie trzyma już a i b) i sprawdź, że destruktory się nie wywołały, a licznik żywych instancji nie wrócił do zera.

Zweryfikuj wycieki narzędziem: -fsanitize=address lub valgrind.

3) Wersja B — sąsiedzi jako weak_ptr

Ten sam scenariusz, ale lista sąsiadów to weak_ptr.

Powtórz pomiary use_count() po etapach.

Po wyjściu ze scope’a oczekuj wywołania destruktorów i spadku licznika żywych instancji do zera.

Użyj printNeighbors() po zwolnieniu węzła docelowego: lock() ma zwrócić pusty shared_ptr (nullptr).

4) Dodatkowe przypadki (rekomendowane)

Pętla do samego siebie: węzeł dodaje jako sąsiada samego siebie; pokaż różnicę shared_ptr vs weak_ptr.

Dłuższy cykl: 3–4 węzły w pierścieniu.

Zrywanie cyklu: z wersją shared_ptr wyzeruj jedną krawędź i pokaż, kiedy destruktory zaczynają się wywoływać.

Wymagania techniczne

Dwa typy węzłów: NodeS (sąsiedzi shared_ptr) i NodeW (sąsiedzi weak_ptr).

Metody:

void addNeighbor(...)

void printNeighbors() const

Globalne liczniki żywych instancji dla obu typów (lub statyczne pola klas).

Czytelny output etapów i liczników.

Budowa z -O0 -g -fsanitize=address -fno-omit-frame-pointer ułatwi weryfikację.

C++17+.

Testy akceptacyjne

Cykl z shared_ptr nie zwalnia pamięci

Po utworzeniu cyklu i wyjściu ze scope’a:

Brak linii ~NodeS(...) w logu.

Licznik żywych NodeS > 0.

ASan/valgrind raportuje wyciek.

Wersja z weak_ptr zwalnia pamięć

Po utworzeniu tego samego wzorca połączeń i wyjściu ze scope’a:

Pojawiają się linie ~NodeW(...) dla wszystkich węzłów.

Licznik żywych NodeW == 0.

Brak wycieków w ASan/valgrind.

weak_ptr::lock() po zwolnieniu

printNeighbors() wypisuje expired dla sąsiadów, którzy zostali już zwolnieni.

lock() zwraca pusty wskaźnik; sprawdzalne przez if (!p) ....

(Opcjonalnie) Self-loop

NodeS z krawędzią do siebie nie zwalnia się po wyjściu ze scope’a; NodeW zwalnia się. -->