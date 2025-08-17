1) Rule of 5 na klasie z dynamiczną tablicą
Teoria — pytania na rozgrzewkę

Kiedy potrzebujesz Rule of 5, a kiedy Rule of 0?

Czym różni się kopia głęboka od płytkiej i jak je wykryć w testach?

Co musi gwarantować silna/pośrednia słaba gwarancja wyjątku przy operacji przypisania?

Zadanie

Zaimplementuj klasę Buffer zarządzającą dynamiczną tablicą int.
Wymagane elementy: ctor domyślny, ctor(n, value), dtor, copy ctor, 

################################## poprawki: ##################################
	Co dzieje się z początkowymi wartościami pól po wywołaniu konstruktora domyślnego? 	
Czy destruktor ma wtedy na czym legalnie działać?
    • Gdy rozmiar to 0, czy na pewno chcesz jeszcze coś alokować/kopiować? Pomyśl o „wczesnym wyjściu”.
    • W pętli kopiującej: czy zmieniasz wskaźnik, czy kopiujesz elementy pod wskaźnikami? Sprawdź, co dokładnie przypisujesz w każdym kroku.
    • Czy inwariant „array_ == nullptr ⇔ arraySize_ == 0” zawsze jest zachowany na końcu konstruktora?
    • Zastanów się, co się stanie, jeśli alokacja/kopia rzuci wyjątek — w jakim stanie zostaje obiekt?
    • Pomyśl o Rule of 5: skoro masz surowe new/delete, czy nie brakuje „reszty zestawu”?
    • Czy self-copy (kopiowanie obiektu do samego siebie) jest możliwe w Twoim kodzie i jak na nie reagujesz?
    • Czy inicjalizacja pól w listach inicjalizacyjnych nie byłaby bezpieczniejsza/czytelniejsza niż przypisania w ciele?
    • Czy chcesz, by po błędzie kopiowania stan był niezmieniony (silna gwarancja), czy wystarczy podstawowa? Jak byś to osiągnął?



move ctor, copy assign, move assign, size(), data(), operator[], at(), push_back(int), resize(size_t), swap(Buffer&), równość/nie-równość.

Wymagania i edge-case’y

Kopia ma własną pamięć (brak współdzielenia).

Move nie może rzucać (noexcept) i zostawia źródło w stanie pustym, ale ważnym.

operator[] bez sprawdzania, at() rzuca std::out_of_range.

resize() zachowuje istniejące elementy, nowe inicjalizuje zerem.

Silna gwarancja dla push_back i resize (albo przynajmniej podstawowa i jasno to zaznacz).

swap w noexcept i w O(1).

Co przetestować (GoogleTest)

Konstrukcja i rozmiar:

Buffer b(3, 7); EXPECT_EQ(b.size(), 3); EXPECT_EQ(b[0], 7);

Kopia jest głęboka:

skopiuj, zmień kopię, oryginał bez zmian.

Przenoszenie:

przenieś do nowego; nowy ma dane, źródło puste (size()==0, data()==nullptr ok).

Przypisanie kopią i przeniesieniem (self-assign też).

at() rzuca dla złych indeksów.

resize skracanie i wydłużanie; nowe elementy==0.

push_back przy pustym i zapelnionym.

swap zamienia w O(1).

Operator ==/!= dla różnych/identycznych zawartości.

noexcept dla move/swap (sprawdź noexcept w static_assert).

Rozszerzenia

Silna gwarancja przez technikę copy-and-swap.

Wewnętrzna „pojemność” i strategia realokacji.

Iterator forward; testy z algorytmami STL.
