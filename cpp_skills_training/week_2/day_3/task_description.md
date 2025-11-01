🧩 Dzień 5 – Perfect Forwarding i std::forward (wersja rozszerzona bez kodu)
🎯 Cel ćwiczenia

Twoim zadaniem jest:

Zrozumieć różnicę między zwykłym przekazywaniem argumentów, rvalue, lvalue, a perfect forwardingiem.

Nauczyć się pisać funkcje szablonowe, które potrafią przekazać argument dalej bez utraty jego „natury” (czy był lvalue, czy rvalue).

Stworzyć funkcję ogólną (fabrykę obiektów), która potrafi tworzyć dowolny typ na podstawie argumentów jego konstruktora — bez zbędnych kopii.

🔍 Część I – Teoria (zrozumienie pojęć)

Zanim przejdziesz do kodu, przypomnij sobie lub opisz:

Co oznacza zapis T&& w szablonie funkcji.
Wyjaśnij sobie, że może on oznaczać dwie różne rzeczy:

Zwykłą referencję do rvalue (np. w konstruktorze klasy).

Lub tzw. referencję uniwersalną, jeśli występuje w kontekście dedukcji typu T w szablonie.

Dlaczego std::forward jest potrzebny, skoro istnieje std::move.
(Pomyśl: std::move zawsze zamienia argument w rvalue, a std::forward tylko wtedy, gdy oryginalny argument też był rvalue).

W jakich miejscach w standardowej bibliotece można znaleźć ten wzorzec (np. std::make_unique, std::make_shared, emplace_back, std::thread).

⚙️ Część II – Funkcja szablonowa „fabryka obiektów”

Twoim zadaniem jest napisać szablon funkcji, która działa podobnie do std::make_unique, ale nie korzysta z dynamicznej alokacji.

Opis kroków:

Funkcja ma przyjmować dowolną liczbę argumentów — użyj składni z wielokropkiem (parametry szablonu i funkcji z „pakietem argumentów”).

Każdy argument ma być przekazany dalej do konstruktora typu, który chcesz utworzyć.

Parametry funkcji mają być przekazywane jako referencje uniwersalne, by zachować informację o tym, czy były lvalue, czy rvalue.

Wewnątrz funkcji utwórz obiekt żądanego typu, przekazując argumenty z użyciem std::forward.

Zwróć ten obiekt przez wartość.

Celem jest, żeby funkcja działała w taki sposób, że:

jeśli przekażesz do niej zmienną (lvalue), zostanie użyty konstruktor kopiujący,

jeśli przekażesz wynik std::move, zostanie użyty konstruktor przenoszący.

🧍‍♂️ Część III – Klasy testowe

Zaimplementuj trzy klasy, każda z innym zestawem konstruktorów i zachowań.
Dzięki temu zobaczysz, jak perfect forwarding zachowuje się w różnych sytuacjach.

1. Klasa Person

Powinna przechowywać napis (np. imię).

Zrób dwa konstruktory: jeden przyjmujący stałą referencję do napisu, a drugi przyjmujący napis jako rvalue.

W każdym konstruktorze wypisz na ekran informację, która wersja została wywołana.

Możesz też dodać konstruktor kopiujący i przenoszący, które również wypisują komunikaty.

2. Klasa Car

Niech ma kilka pól, np. nazwę modelu i rok produkcji.

Zrób konstruktor przyjmujący te dwa argumenty.

Dodaj logikę wypisującą, który konstruktor lub operacja została użyta (kopiowanie, przenoszenie).

Możesz dodać destruktor wypisujący komunikat, żeby zobaczyć, kiedy obiekt jest niszczony.

3. Klasa Book

Niech posiada kilka przeciążonych konstruktorów, np. jeden przyjmujący tylko tytuł, inny tytuł i autora.

Również wprowadź logowanie w konstruktorach, by wiedzieć, która wersja jest używana.

🧪 Część IV – Testy i obserwacje

Zrób serię eksperymentów, żeby zrozumieć, jak zachowuje się Twój kod.

Tworzenie prostych obiektów

Utwórz zmienną std::string i użyj jej jako argumentu przy tworzeniu obiektu Person poprzez Twoją funkcję.

Następnie zrób to samo, ale przekaż argument przez std::move.

Zobacz, który konstruktor się uruchamia.

Różne kombinacje argumentów

Dla Car wywołaj funkcję z dwoma zwykłymi zmiennymi.

Potem zrób to samo, ale jeden z argumentów przekaż jako std::move.

Zaobserwuj różnicę w komunikatach z konstruktorów.

Dodawanie do kontenera

Utwórz wektor obiektów (std::vector) i dodaj do niego elementy, korzystając z Twojej funkcji fabrykującej.

Obserwuj, czy przy wstawianiu obiektów do wektora są wywoływane kopiowania, czy przenoszenia.

Wypisz liczbę wywołań każdego typu operacji, jeśli chcesz się upewnić, że forwarding działa poprawnie.

💡 Część V – Dodatkowe zadania dla chętnych

Wersja na stercie
Stwórz wariant funkcji, która zamiast zwracać obiekt przez wartość, tworzy go na stercie i zwraca wskaźnik inteligentny (unique_ptr).
Dzięki temu zasymulujesz działanie std::make_unique.

Porównanie z std::move
Zrób wersję funkcji, w której zamiast std::forward użyjesz std::move.
Następnie przetestuj ją i zaobserwuj różnicę w zachowaniu (zwróć uwagę na przypadki, gdy przekazujesz lvalue).

Fabryka funkcji
Napisz funkcję, która przyjmuje jako argument inną funkcję lub lambdę, i przekazuje do niej argumenty z użyciem perfect forwardingu.
Dzięki temu zobaczysz, jak można forwarding zastosować nie tylko przy konstruktorach, ale też przy wywoływaniu funkcji.

🧠 Część VI – Analiza i refleksja

Na koniec odpowiedz sobie na kilka pytań:

W których przypadkach Twój kod wykonał kopiowanie, a w których przeniesienie?

Co by się zmieniło, gdybyś usunął std::forward i przekazywał argumenty bez niego?

Jakie realne problemy mogłyby się pojawić w dużych projektach, gdyby programiści zapomnieli o std::forward?

Kiedy warto stosować perfect forwarding, a kiedy jest to zbędne skomplikowanie kodu?