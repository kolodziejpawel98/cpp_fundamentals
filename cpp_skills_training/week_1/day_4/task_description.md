3) Konwersja starego enum na enum class — wersja łatwiejsza
Teoria — pytania
    • Różnice: zakres nazw, konwersje niejawne, typ bazowy.
    • Jak z enum class zrobić proste bitmaski (tylko | + sprawdzanie bitu)?
    • Dlaczego enum class poprawia bezpieczeństwo API?

Zadanie
Masz legacy:
enum Status { OK, WARN, ERROR };
enum Permission { READ=1, WRITE=2, EXEC=4 };
Zmień na:
enum class Status : uint8_t { Ok, Warn, Error };
enum class Permission : uint8_t { Read=1, Write=2, Exec=4 };
Dodaj minimalny zestaw:
    • Operatory bitowe tylko dla Permission: | oraz |=.
    • Alias PermSet na typ bazowy Permission.
    • Proste API operujące na PermSet: has(PermSet, Permission) oraz set(PermSet, Permission).
    • Funkcje konwersji na string: to_string(Status) i to_string(Permission).
Uwaga: bez wrappera, tylko alias. Bez &, ^, ~ — nie są wymagane w tej wersji.

Wymagania i ograniczenia
    • Brak niejawnych konwersji: jeśli potrzebujesz liczby, używaj rzutowania przez typ bazowy.
    • Operatory | i |= mają działać wyłącznie na Permission.
    • PermSet to alias typu bazowego Permission (np. using PermSet = std::underlying_type_t<Permission>;).
    • to_string(Status) i to_string(Permission) muszą obsłużyć każdy wariant (bez „domyślnego” uciekania).
    • Dla „pustego zestawu” uprawnienia = PermSet{0}.
    • Kod kompiluje się bez ostrzeżeń w trybie „normalnym” (bez extra sanitizerów).

Co dostarczyć
    1. Definicje enumów (Status, Permission) z typem bazowym uint8_t.
    2. Operatory:
        ◦ Permission operator|(Permission, Permission)
        ◦ Permission& operator|=(Permission&, Permission)
    3. Alias:
        ◦ using PermSet = std::underlying_type_t<Permission>;
    4. API na PermSet:
        ◦ bool has(PermSet, Permission)
        ◦ PermSet set(PermSet, Permission)
    5. Stringi:
        ◦ std::string to_string(Status)
        ◦ std::string to_string(Permission)
(Nazwy dokładnie takie jak wyżej — ułatwi to review.)

Scenariusze użycia (co powinno działać)
    • Permission p = Permission::Read | Permission::Write;
    • p |= Permission::Exec;
    • PermSet s = 0; s = set(s, Permission::Read);
    • has(s, Permission::Read) == true
    • to_string(Status::Warn) == "Warn"
    • to_string(Permission::Write) == "Write"

Testy (krótka lista)
    • Permission::Read | Permission::Write daje zestaw z dwoma bitami (sprawdź has).
    • set(0, Permission::Exec) ustawia bit Exec.
    • has(0, Permission::Read) == false oraz has(set(0, Permission::Read), Permission::Read) == true.
    • to_string(Status::Ok), to_string(Status::Error) zwracają dokładne nazwy.
    • to_string(Permission::Read) zwraca "Read".
    • static_assert(sizeof(Status) == 1); oraz static_assert(sizeof(Permission) == 1);

Podpowiedzi (bez kodu)
    • W operatorach rzutuj przez typ bazowy std::underlying_type_t<Permission>.
    • has sprawdza bit przez AND na liczbach (PermSet).
    • to_string zrób przez switch z każdą gałęzią osobno.

Rozszerzenia (opcjonalne, jeśli chcesz więcej)
    • Dodaj to_string(PermSet) zwracające np. "Read|Write" lub "None".
    • Dodaj reset(PermSet, Permission) i toggle(PermSet, Permission).

