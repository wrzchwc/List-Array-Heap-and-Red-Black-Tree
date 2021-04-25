#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <chrono>

#include "two_way_list/TwoWayList.h"
#include "binary_heap/BinaryHeap.h"
#include "dynamic_array/DynamicArray.h"
#include "red_black_tree/RedBlackTree.h"

using namespace std;
using namespace std::chrono;

int input, index;
char operation;
bool running = true;                    //controls the main loop of the program
bool structure = true;                  //controls loop of given structure while working in specified mode
bool mode = true;                       //controls loop of specified mode
string filepath = "random_numbers.txt"; //path to txt file, where randomly generated numbers are stored

void random_numbers_to_txt() {
    fstream file;
    random_device device;
    mt19937 generator(device());
    int extreme, number;

    cout << "Maksymalna wartosc w strukturze: ";
    cin >> extreme;
    cout << "Minimalna wartosc w strukturze: " << -extreme << endl;
    cout << "Ile liczb do wylosowania: ";
    cin >> number;

    uniform_int_distribution<> distribution(-extreme, extreme);

    file.open(filepath, ios::out);
    file << number << endl;
    for (int i = 0; i < number; i++)
        file << distribution(generator) << endl;
    file.close();

}


int main() {

    cout << "--------------------------------SDiZO Projekt--------------------------------" << endl;
    cout << "Jakub Wierzchowiec, 04.2021" << endl;
    while (running) {
        cout << "[0] Zakoncz program" << endl;
        cout << "[1] Tryb kontrolny" << endl;
        cout << "[2] Tryb pomiarowy" << endl;
        cout << ": ";
        cin >> input;
        switch (input) {
            case 0: {
                running = false;
                break;
            }
            case 1: {
                while (mode) {
                    cout << "-------------------------------Tryb kontrolny-------------------------------" << endl;
                    cout << "[1] Lista dwukierunkowa" << endl;
                    cout << "[2] Tablica dynamiczna" << endl;
                    cout << "[3] Kopiec binarny" << endl;
                    cout << "[4] Drzewo czerwono-czarne" << endl;
                    cout << "[5] Powrot do menu" << endl;
                    cout << ": ";
                    cin >> input;
                    switch (input) {
                        case 0: {
                            mode = false;
                            break;
                        }
                        case 1: {
                            structure = true;
                            auto *list = new TwoWayList();
                            cout << "[1] Lista dwukierunkowa" << endl;
                            while (structure) {
                                list->show();
                                cout << "DODAWANIE: (A) na poczatek  (B) na koniec     (C) w dowolne miejsce" << endl;
                                cout << "USUWANIE:  (D) z poczatku   (E) z konca       (F) z dowolnego miejsca" << endl;
                                cout << "INNE:      (G) Wyszukiwanie (H) Wyczysc liste (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;

                                switch (operation) {
                                    case 'A':
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        list->addFirst(input);
                                        break;

                                    case 'B':
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        list->addLast(input);
                                        break;

                                    case 'C':
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        cout << "Na jaka pozycje: ";
                                        cin >> index;
                                        list->add(input, index);
                                        break;

                                    case 'D':
                                        list->removeFirst();
                                        break;

                                    case 'E':
                                        list->removeLast();
                                        break;

                                    case 'F':
                                        cout << "Indeks elementu do usuniecia: ";
                                        cin >> index;
                                        list->remove(index);
                                        break;

                                    case 'G':
                                        cout << "Liczba, ktora ma zostac znaleziona: ";
                                        cin >> input;
                                        if (list->contains(input))
                                            cout << input << " znajduje sie na liscie." << endl;
                                        else
                                            cout << input << " nie znajduje sie na liscie" << endl;
                                        break;

                                    case 'H':
                                        list->removeAll();
                                        break;

                                    case 'X':
                                        structure = false;
                                        break;

                                    default:
                                        cout << "Niepoprawny wybor! Sproboj ponownie" << endl;
                                        break;
                                }
                            }
                            delete list;
                            break;
                        }

                        case 2: {
                            structure = true;
                            auto *array = new DynamicArray();
                            cout << "[2] Tablica dynamiczna" << endl;

                            while (structure) {
                                array->show();
                                cout << "DODAWANIE: (A) na poczatek  (B) na koniec (C) w dowolne miejsce" << endl;
                                cout << "USUWANIE:  (D) z poczatku   (E) z konca   (F) z dowolnego miejsca" << endl;
                                cout << "INNE:      (G) Wyszukiwanie (H) Wyczysc   (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;

                                switch (operation) {
                                    case 'A': {
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        array->addFirst(input);
                                        break;
                                    }

                                    case 'B': {
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        array->addLast(input);
                                        break;
                                    }

                                    case 'C': {
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        cout << "Na jaka pozycje: ";
                                        cin >> index;
                                        array->add(index, input);
                                        break;
                                    }

                                    case 'D': {
                                        array->removeFirst();
                                        break;
                                    }

                                    case 'E': {
                                        array->removeLast();
                                        break;
                                    }

                                    case 'F': {
                                        cout << "Pozycja do usuniecia: ";
                                        cin >> index;
                                        array->remove(index);
                                        break;
                                    }

                                    case 'G': {
                                        cout << "Liczba do znalezienia: ";
                                        cin >> input;
                                        if (array->contains(input))
                                            cout << input << " znajduje sie w tablicy." << endl;
                                        else
                                            cout << input << " nie znajduje sie w tablicy." << endl;
                                        break;
                                    }

                                    case 'H': {
                                        array->removeAll();
                                        break;
                                    }

                                    case 'X': {
                                        structure = false;
                                        break;
                                    }

                                    default: {
                                        cout << "Niepoprawny wybor! Sproboj ponownie." << endl;
                                        break;
                                    }

                                }
                            }
                            delete array;
                            break;
                        }
                        case 3: {
                            structure = true;
                            auto *heap = new BinaryHeap();
                            cout << "[3] Kopiec binarny" << endl;
                            while (structure) {
                                heap->show();
                                cout << "(A) Dodawanie (B) Usuwanie (C) Wyszukiwanie (D) Czyszczenie kopca ";
                                cout << "(X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                switch (operation) {
                                    case 'A':
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        heap->add(input);
                                        break;
                                    case 'B':
                                        heap->remove();
                                        break;
                                    case 'C':
                                        cout << "Liczba, która ma być znaleziona: ";
                                        cin >> input;
                                        if (heap->contains(input))
                                            cout << input << " znajduje sie w kopcu." << endl;
                                        else
                                            cout << input << " nie znajduje sie w kopcu. " << endl;
                                        break;
                                    case 'D':
                                        heap->removeAll();
                                        break;
                                    case 'X':
                                        structure = false;
                                        break;
                                    default:
                                        cout << "Niepoprwany wybor! Sproboj ponownie" << endl;
                                        break;
                                }
                            }
                            delete heap;
                            break;
                        }
                        case 4: {
                            structure = true;
                            auto *tree = new RedBlackTree();
                            cout << "[4] Drzewo czerwono - czarne" << endl;
                            while (structure) {
                                cout << "(rodzic adres wartosc kolor)" << endl;

                                tree->show(tree->getRoot());
                                cout << endl;
                                cout << "(A) Dodawanie (B) Usuwanie (C) Wyszukiwanie";
                                cout << " (D) Czyszczenie drzewa (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                switch (operation) {
                                    case 'A':
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        tree->add(input);
                                        break;
                                    case 'B':
                                        cout << "Usuwana liczba: ";
                                        cin >> input;
                                        tree->remove(input);
                                        break;
                                    case 'C':
                                        cout << "Liczba, ktora ma byc znaleziona: ";
                                        cin >> input;
                                        if (tree->contains(input))
                                            cout << input << " znajduje sie w drzewie." << endl;
                                        else
                                            cout << input << " nie znajduje sie w drzewie" << endl;
                                        break;
                                    case 'D':
                                        tree->removeAll(tree->getRoot());
                                        tree = new RedBlackTree();
                                        break;
                                    case 'X':
                                        structure = false;
                                        break;
                                    default:
                                        cout << "Niepoprawny wybor! Sproboj ponownie." << endl;
                                        break;
                                }
                            }
                            delete tree;
                            break;
                        }
                        case 5: {
                            mode = false;
                            break;
                        }
                        default: {
                            cout << "Niepoprawny wybor! Sproboj ponownie." << endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 2: {
                fstream file;       // handle for .txt file
                string tmp;         //used for reading from .txt file
                double time = 0.0;  //time of code execution
                bool found;         //variable used for measuring time of searching
                while (mode) {
                    structure = true;
                    cout << "--------------------------------Tryb pomiarowy-------------------------------" << endl;
//                    cout<<"PLIK TXT W TYM SAMYM FOLDERZE, CO PLIK EXE! NAZWA PLIKU W FORMACIE nazwa.txt!"<<endl;
//                    cout<<"Nazwa pliku zawierajacego dane: ";
//                    cin >> filepath;
                    cout << "[1] Lista dwukierunkowa" << endl;
                    cout << "[2] Tablica dynamiczna" << endl;
                    cout << "[3] Kopiec binarny" << endl;
                    cout << "[4] Drzewo czerwono-czarne" << endl;
                    cout << "[5] Powrot do menu" << endl;
                    cout << ": ";
                    cin >> input;
                    switch (input) {
                        case 1: {
                            bool ready = false;
                            auto *list = new TwoWayList();
                            cout << "[1] Lista dwukierunkowa" << endl;
                            random_numbers_to_txt();

                            //fill the list with random numbers from txt file
                            file.open(filepath, ios::in);
                            while (getline(file, tmp)) {
                                if (ready)
                                    list->addLast(atoi(tmp.c_str()));
                                else
                                    ready = true;
                            }
                            file.close();

                            while (structure) {
                                cout << "DODAWANIE: (A) na poczatek  (B) na koniec  (C) w dowolne miejsce" << endl;
                                cout << "USUWANIE:  (D) z poczatku   (E) z konca    (F) z dowolnego miejsca" << endl;
                                cout << "INNE:      (G) Wyszukiwanie (H) Wyswietl   (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                if (operation == 'A' || operation == 'B' || operation == 'C') {
                                    cout << "Dodawana liczba: ";
                                    cin >> input;
                                    if (operation == 'A') {
                                        auto start = steady_clock::now();
                                        list->addFirst(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());

                                    } else if (operation == 'B') {
                                        auto start = steady_clock::now();
                                        list->addLast(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());

                                    } else {
                                        cout << "Na jaka pozycje: ";
                                        cin >> index;
                                        auto start = steady_clock::now();
                                        list->add(input, index);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                } else if (operation == 'D') {
                                    auto start = steady_clock::now();
                                    list->removeFirst();
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());

                                } else if (operation == 'E') {
                                    auto start = steady_clock::now();
                                    list->removeLast();
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());

                                } else if (operation == 'F') {
                                    cout << "Pozycja do usuniecia: ";
                                    cin >> index;
                                    auto start = steady_clock::now();
                                    list->remove(index);
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());

                                } else if (operation == 'G') {
                                    cout << "Liczba do znalezienia: ";
                                    cin >> input;
                                    auto start = steady_clock::now();
                                    found = list->contains(input);
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());

                                    if (found)
                                        cout << input << " znajduje sie na liscie" << endl;
                                    else
                                        cout << input << " nie znajduje sie na lisicie" << endl;
                                } else if (operation == 'X') {
                                    structure = false;
                                } else if (operation == 'H')
                                    list->show();
                                else {
                                    cout << "Nieprawidlowy wybor sproboj ponownie!" << endl;
                                }
                                cout << "Czas wykonania operacji: " << time << " ns" << endl;
                            }
                            delete list;
                            break;
                        }

                        case 2: {
                            cout << "[2] Tablica dynamiczna" << endl;
                            random_numbers_to_txt();
                            int size;
                            int *tmp_array;
                            file.open(filepath, ios::in);
                            getline(file, tmp);
                            size = atoi(tmp.c_str());
                            tmp_array = new int[size];
                            for (int i = 0; i < size; i++) {
                                getline(file, tmp);
                                tmp_array[i] = atoi(tmp.c_str());
                            }
                            file.close();
                            auto *array = new DynamicArray(tmp_array, size);
                            delete tmp_array;
                            while (structure) {
                                cout << "DODAWANIE: (A) na poczatek  (B) na koniec (C) w dowolne miejsce" << endl;
                                cout << "USUWANIE:  (D) z poczatku   (E) z konca   (F) z dowolnego miejsca" << endl;
                                cout << "INNE:      (G) Wyszukiwanie (H) Wyswietl  (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                if (operation == 'A' || operation == 'B' || operation == 'C') {
                                    cout << "Dodawana liczba: ";
                                    cin >> input;
                                    if (operation == 'A') {
                                        auto start = steady_clock::now();
                                        array->addFirst(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    } else if (operation == 'B') {
                                        auto start = steady_clock::now();
                                        array->addLast(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    } else {
                                        cout << "Na jaka pozycje: ";
                                        cin >> index;
                                        auto start = steady_clock::now();
                                        array->add(index, input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                } else if (operation == 'D') {
                                    auto start = steady_clock::now();
                                    array->removeFirst();
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());
                                } else if (operation == 'E') {
                                    auto start = steady_clock::now();
                                    array->removeLast();
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());
                                } else if (operation == 'F') {
                                    cout << "Pozycja do usuniecia: " << endl;
                                    cin >> index;
                                    auto start = steady_clock::now();
                                    array->removeLast();
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());
                                } else if (operation == 'G') {
                                    cout << "Liczba do znalezienia: ";
                                    cin >> input;
                                    auto start = steady_clock::now();
                                    found = array->contains(input);
                                    auto end = steady_clock::now();
                                    time = double(duration_cast<nanoseconds>(end - start).count());
                                    if (found)
                                        cout << input << " znajduje sie w tablicy" << endl;
                                    else
                                        cout << input << " nie znajduje sie w tablicy" << endl;
                                } else if (operation == 'H') {
                                    array->show();
                                } else if (operation == 'X') {
                                    structure = false;
                                } else {
                                    cout << "Nieprawidlowy wybor! Sproboj ponownie." << endl;
                                }
                                cout << "Czas wykonania operacji: " << time << " ns" << endl;
                            }
                            delete array;
                            break;
                        }

                        case 3: {
                            bool ready = false;
                            auto *heap = new BinaryHeap();
                            cout << "[3] Kopiec binarny" << endl;
                            random_numbers_to_txt();
                            //fill the heap with random numbers from txt file
                            file.open(filepath, ios::in);
                            while (getline(file, tmp)) {
                                if (ready)
                                    heap->add(atoi(tmp.c_str()));
                                else
                                    ready = true;
                            }
                            file.close();

                            while (structure) {
                                cout << "(A) Dodawanie (B) Usuwanie (C) Wyszukiwanie ";
                                cout << "(D) Czyszczenie kopca (E) Wyswietl (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                switch (operation) {
                                    case 'A': {
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        auto start = steady_clock::now();
                                        heap->add(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                        break;
                                    case 'B': {
                                        auto start = steady_clock::now();
                                        heap->remove();
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                        break;
                                    case 'C': {
                                        cout << "Liczba do znalezienia: ";
                                        cin >> input;
                                        auto start = steady_clock::now();
                                        found = heap->contains(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());

                                        if (found)
                                            cout << input << " znajduje sie w kopcu." << endl;
                                        else
                                            cout << input << " nie znajduje sie w kopcu." << endl;
                                    }
                                        break;
                                    case 'D': {
                                        auto start = steady_clock::now();
                                        heap->removeAll();
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                        break;
                                    case 'E':
                                        heap->show();
                                        break;
                                    case 'X':
                                        structure = false;
                                        break;
                                    default:
                                        cout << "Nieprawidlowy wybor! Sproboj ponownie." << endl;
                                        break;
                                }
                                cout << "Czas wykonania operacji: " << time << " ns" << endl;
                            }
                            break;
                        }

                        case 4: {
                            bool ready = false;
                            auto *tree = new RedBlackTree();
                            cout << "[4] Drzewo czerwono-czarne" << endl;
                            random_numbers_to_txt();
                            //fill the tree with random numbers from txt file
                            file.open(filepath, ios::in);
                            file >> tmp;
                            while (getline(file, tmp)) {
                                if (ready)
                                    tree->add(atoi(tmp.c_str()));
                                else
                                    ready = true;
                            }
                            file.close();

                            while (structure) {
                                cout << "(A) Dodawanie (B) Usuwanie (C) Wyszukiwanie (D) Czyszczenie drzewa ";
                                cout << "(E) Wyswietl (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                switch (operation) {
                                    case 'A': {
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        auto start = steady_clock::now();
                                        tree->add(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                        break;
                                    case 'B': {
                                        cout << "Usuwana liczba: ";
                                        cin >> input;
                                        auto start = steady_clock::now();
                                        tree->remove(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                        break;
                                    case 'C': {
                                        cout << "Liczba do znalezienia: ";
                                        cin >> input;
                                        auto start = steady_clock::now();
                                        found = tree->contains(input);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        if (found)
                                            cout << input << " znajduje sie w drzewie" << endl;
                                        else
                                            cout << input << " nie znajduje sie w drzewie" << endl;
                                    }
                                        break;
                                    case 'D': {
                                        auto start = steady_clock::now();
                                        tree->removeAll(tree->getRoot());
                                        tree = new RedBlackTree();
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                    }
                                        break;
                                    case 'E':
                                        tree->show(tree->getRoot());
                                        break;
                                    case 'X':
                                        structure = false;
                                        break;
                                    default:
                                        cout << "Nieprawidlowy wybor! Sproboj ponownie." << endl;
                                        break;
                                }
                                cout << "Czas wykonania operacji: " << time << " ns" << endl;
                            }
                            delete tree;
                            break;
                        }
                        case 5: {
                            mode = false;
                            break;
                        }
                        default: {
                            cout << "Niepoprawny wyobr! Sproboj ponownie" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            default: {
                cout << "Niepoprawny wybor! Sproboj ponownie." << endl;
                break;
            }
        }
        mode = true;
    }
    return 0;
}

