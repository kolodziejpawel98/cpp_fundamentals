1️⃣ Klasa Document

Reprezentuje dokument tekstowy, który przechowuje dynamicznie alokowany string lub wektor znaków (std::vector<char>).

Każdy dokument ma:

tytuł (std::string)

zawartość (std::vector<char>)

statyczny licznik żyjących dokumentów

2️⃣ Co implementujesz

Konstruktor domyślny (pusty dokument)

Konstruktor kopiujący: tworzy niezależną kopię zawartości

Operator przypisania kopiującego

Konstruktor przenoszący: przejmuje zawartość, obiekt źródłowy zostaje pusty

Operator przypisania przenoszącego

3️⃣ Ćwiczenia z move semantics

Twórz kilka dokumentów i kopiuj/przenoś je między zmiennymi, wypisując wskaźniki do zawartości.

Wstaw dokumenty do wektora. Obserwuj, jak przenoszenie działa podczas realokacji wektora.

Stwórz funkcję merge(Document&& other), która dokleja zawartość innego dokumentu i zeruje obiekt źródłowy.

Twórz dokumenty o dużej zawartości (np. 1 MB tekstu) i zobacz różnicę w wydajności kopiowania vs przenoszenia.

4️⃣ Rozszerzone wyzwania

Dodaj mapę dokumentów (std::unordered_map<std::string, Document>) i wstawiaj do niej obiekty przez przeniesienie.

Obserwuj, kiedy wywołuje się konstruktor kopiujący, a kiedy przenoszący.

Spróbuj eksperymentować z std::move przy wysyłaniu dokumentu do funkcji, która go przetwarza i zwraca.

Dodaj funkcję split(size_t pos) — tworzy nowy dokument z częścią zawartości przy użyciu przenoszenia.