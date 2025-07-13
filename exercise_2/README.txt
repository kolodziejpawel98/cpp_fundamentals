🧠 Zadanie: Hierarchia pojazdów i centrum serwisowe
🎯 Cel:

Stworzyć hierarchię klas reprezentujących różne typy pojazdów, zastosować dziedziczenie, polimorfizm oraz użyć wirtualnych destruktorów.
📋 Treść zadania:

Stwórz hierarchię klas reprezentującą różne pojazdy, które mogą zostać zarejestrowane w centrum serwisowym.
1. Klasa bazowa Vehicle

    Zawiera:

        std::string brand — marka pojazdu

        std::string model

        int year

    Wirtualną metodę void printInfo() const — wypisuje dane pojazdu

    Wirtualny destruktor (!)

2. Klasy pochodne: Car, Motorcycle, Truck

Każda dziedziczy po Vehicle i dodaje własne pole oraz nadpisuje metodę printInfo():

    Car

        int numberOfDoors

    Motorcycle

        bool hasSidecar

    Truck

        double maxLoadTons

3. Klasa ServiceCenter

    Przechowuje pojazdy w wektorze wskaźników: std::vector<Vehicle*>

    Metoda addVehicle(Vehicle*) — dodaje pojazd do systemu

    Metoda printAll() — wypisuje dane wszystkich pojazdów (polimorfizm!)

    Destruktor — usuwa wszystkie wskaźniki (symuluje zarządzanie pamięcią)

✅ Wymagania techniczne:

    Użyj polimorfizmu w metodzie printInfo()

    Upewnij się, że destruktory są wirtualne, by uniknąć wycieków

    Na koniec, przetestuj wszystko w funkcji main():

        Utwórz 2–3 obiekty różnych klas

        Dodaj je do ServiceCenter

        Wywołaj printAll()

🔁 Rozszerzenia (opcjonalnie):

    Zmień surowe wskaźniki na std::unique_ptr<Vehicle>

    Dodaj funkcję usuwania pojazdu po ID

    Użyj typeid lub dynamic_cast by sprawdzić typ konkretnego pojazdu

Daj znać, jeśli chcesz od razu szkic rozwiązania lub wersję z użyciem smart pointerów.
