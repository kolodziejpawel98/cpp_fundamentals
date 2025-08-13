Dzień 1 — RAII + Rule of 0/3/5 (wersja „ty piszesz”)
Krok 1 — Mikro-teoria (5–10 min)
    • Zdefiniuj w jednym zdaniu: RAII i Rule of 0/3/5.
    • Zanotuj w 2–3 punktach, kiedy kopiowanie wrappera zasobu ma sens, a kiedy powinno być zabronione.
Krok 2 — FileWrapper v1 (zarządzasz surowym uchwytem)
Cel: klasa zarządzająca uchwytem do pliku w trybie odczytu.
Wymagania:
    • Konstruktor: otwiera plik do odczytu; na błąd — sygnalizacja wyjątkiem.
    • Destruktor: zwalnia zasób.
    • API: bool readLine(std::string&) czyta jedną linię; true jeśli cokolwiek przeczytano.
    • Kopiowanie: zabronione (kompilator ma zgłosić błąd, gdy spróbujesz).
    • Przenoszenie: dozwolone i noexcept.
    • Obiekt po przeniesieniu ma być w stanie „pustym, ale bezpiecznym”.
Kryteria akceptacji:
    • Przekazanie obiektu przez wartość do funkcji nie kopiuje, tylko przenosi.
    • Po przeniesieniu ze źródła wywołanie readLine nie powoduje UB/crasha (może zwrócić false).
Testy (zrób mały main):
    • Utwórz obiekt dla istniejącego pliku, wczytaj pierwszą linię.
    • Wywołaj funkcję foo(FileWrapper) z std::move(obj) i sprawdź, że działa.
    • Spróbuj skompilować kopiowanie — ma nie przejść.
    • Zbuduj z: -std=c++20 -O2 -Wall -Wextra -Werror -pedantic -fsanitize=address,undefined.
Jeśli utkniesz:
    • Zastanów się, jak „unieważnić” uchwyt po przeniesieniu.
    • Pomyśl, co powinien robić operator przypisania przenoszącego, gdy lewa strona już trzyma zasób.
Krok 3 — FileWrapper v2 (Rule of 0)
Cel: ta sama funkcjonalność, ale bez ręcznego zarządzania zasobem.
Wymagania:
    • Wewnątrz użyj gotowego RAII typu z STL (masz dwie sensowne opcje — wybór należy do Ciebie).
    • Nie dopisuj żadnych specjalnych metod (zero własnego dtor/ctorów kopiujących/przenoszących).
Kryteria akceptacji:
    • Kod kompiluje się bez Twoich specjalnych metod.
    • Semantyka przenoszenia/kopiowania wynika z użytego typu RAII.
Jeśli utkniesz:
    • Zadaj sobie pytanie: „Czy biblioteka standardowa ma już coś, co otwiera i zamyka plik automatycznie?”
Krok 4 — FileWrapper v3 (RAII przez unique_ptr z deleterem)
Cel: hybryda — nadal używasz surowego uchwytu, ale zarządza nim gotowy smart pointer.
Wymagania:
    • Przechowuj uchwyt w inteligentnym wskaźniku z niestandardowym deleterem.
    • Zadbaj, by konstruktor sygnalizował błąd otwarcia.
    • API jak w v1.
Kryteria akceptacji:
    • Nie musisz własnoręcznie pisać destruktora/przenoszeń.
    • Zachowanie odpowiada v1.
Jeśli utkniesz:
    • Zastanów się, jak przekazać funkcję zamykającą do inteligentnego wskaźnika.
Krok 5 — Eksperymenty z kopiowaniem/przenoszeniem
Zadania:
    • Spróbuj włączyć kopiowanie w v1 i sam oceń, dlaczego to zły pomysł dla uchwytów do plików.
    • Zrób wersję operatora przypisania przenoszącego, która daje silną gwarancję wyjątków. Czy to ma sens w Twoim przypadku?
Krok 6 — Refleksja (zapiskami, 6–8 zdań max)
    • Co realnie może pójść źle, jeśli destruktor nie zamknie pliku?
    • Jakie mierzalne korzyści dało przenoszenie (np. brak kopiowania zasobu, prostsze API)?
    • W których wersjach Twoja klasa spełnia Rule of 0 i czemu to jest korzystne?

