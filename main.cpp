#include <iostream>
#include <random>
#include <fstream>
#include <string>

#include <iomanip>
#include <windows.h>

#include "two_way_list/TwoWayList.h"
#include "binary_heap/BinaryHeap.h"
#include "dynamic_array/DynamicArray.h"
#include "red_black_tree/RedBlackTree.h"


using namespace std;
int input, index;
char operation;
//controls the main loop of the program
bool running = true;
//controls loop of given structure while working in specified mode
bool structure = true;
//controls loop of specified mode
bool mode = true;
//path to txt file, where randomly generated numbers are stored
string filepath = "random_numbers.txt";

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

long long int readQPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
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
                                        tree->add(input, tree->getRoot());
                                        break;
                                    case 'B':
                                        //removing
                                        break;
                                    case 'C':
                                        cout << "Liczba, ktora ma byc znaleziona: ";
                                        cin >> input;
                                        if (tree->contains(input, tree->getRoot()))
                                            cout << input << " znajduje sie w drzewie." << endl;
                                        else
                                            cout << input << " nie znajduje sie w drzewie" << endl;
                                        break;
                                    case 'D':
                                        //removing all nodes
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
                fstream file;
                string tmp;
                long long int frequency, start, elapsed = 0;
                QueryPerformanceCounter((LARGE_INTEGER *) &frequency);
                //variable used for measuring time of searching
                bool found;
                while (mode) {
                    structure = true;
                    cout << "-----------------Tryb pomiarowy----------------" << endl;
                    cout << "[1] Lista dwukierunkowa" << endl;
                    cout << "[2] Tablica dynamiczna" << endl;
                    cout << "[3] Kopiec binarny" << endl;
                    cout << "[4] Drzewo czerwono-czarne" << endl;
                    cout << "[5] Powrot do menu" << endl;
                    cout << ": ";
                    cin >> input;
                    switch (input) {
                        case 1: {
                            auto *list = new TwoWayList();
                            cout << "[1] Lista dwukierunkowa" << endl;
                            random_numbers_to_txt();

                            //fill the list with random numbers from txt file
                            file.open(filepath, ios::in);
                            while (getline(file, tmp))
                                list->addLast(atoi(tmp.c_str()));
                            file.close();

                            while (structure) {
                                cout << "DODAWANIE: (A) na poczatek  (B) na koniec  (C) w dowolne miejsce" << endl;
                                cout << "USUWANIE:  (D) z poczatku   (E) z konca    (F) z dowolnego miejsca" << endl;
                                cout << "INNE:      (G) Wyszukiwanie (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                if (operation == 'A' || operation == 'B' || operation == 'C') {
                                    cout << "Dodawana liczba: ";
                                    cin >> input;
                                    if (operation == 'A') {
                                        start = readQPC();
                                        list->addFirst(input);
                                        elapsed = readQPC() - start;
                                    } else if (operation == 'B') {
                                        start = readQPC();
                                        list->addLast(input);
                                        elapsed = readQPC() - start;
                                    } else {
                                        cout << "Na jaka pozycje: ";
                                        cin >> index;
                                        start = readQPC();
                                        list->add(input, index);
                                        elapsed = readQPC() - start;
                                    }
                                } else if (operation == 'D') {
                                    start = readQPC();
                                    list->removeFirst();
                                    elapsed = readQPC() - start;
                                } else if (operation == 'E') {
                                    start = readQPC();
                                    list->removeLast();
                                    elapsed = readQPC() - start;
                                } else if (operation == 'F') {
                                    cout << "Pozycja do usuniecia: ";
                                    cin >> index;
                                    start = readQPC();
                                    list->remove(index);
                                    elapsed = readQPC() - start;
                                } else if (operation == 'G') {
                                    cout << "Liczba do znalezienia: ";
                                    cin >> input;
                                    start = readQPC();
                                    found = list->contains(input);
                                    elapsed = readQPC() - start;
                                    if (found)
                                        cout << input << " znajduje sie na liscie" << endl;
                                    else
                                        cout << input << " nie znajduje sie na lisicie" << endl;
                                } else if (operation == 'X') {
                                    structure = false;
                                } else {
                                    cout << "Nieprawidlowy wybor sproboj ponownie!" << endl;
                                }

                                cout << "Time [s] = " << fixed << setprecision(30) << (float) elapsed /
                                                                                      frequency << endl;
                                cout << "Time [ms] = " << setprecision(30) << (1000.0 * elapsed) /
                                                                              frequency << endl;
                                cout << "Time [us] = " << setprecision(30) << (1000000.0 * elapsed) /
                                                                              frequency << endl;
                            }

                            delete list;
                            break;
                        }

                        case 2: {
                            auto *array = new DynamicArray();
                            int *tmp_array = nullptr;

                            cout << "[2] Tablica dynamiczna" << endl;
                            random_numbers_to_txt();
                            file.open(filepath, ios::in);
                            //size of the array
                            file >> input;
                            tmp_array = new int[input];
                            //fill the dynamic array with random numbers from txt file
                            for (int i = 0; i < input; i++)
                                file >> tmp_array[i];
                            file.close();
                            array->setArray(tmp_array);
                            delete tmp_array;

                            while (structure) {
                                cout << "DODAWANIE: (A) na poczatek  (B) na koniec (C) w dowolne miejsce" << endl;
                                cout << "USUWANIE:  (D) z poczatku   (E) z konca   (F) z dowolnego miejsca" << endl;
                                cout << "INNE:      (G) Wyszukiwanie (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                if (operation == 'A' || operation == 'B' || operation == 'C') {
                                    cout << "Dodawana liczba: ";
                                    cin >> input;
                                    if (operation == 'A') {
                                        start = readQPC();
                                        array->addFirst(input);
                                        elapsed = readQPC() - start;
                                    } else if (operation == 'B') {
                                        start = readQPC();
                                        array->addLast(input);
                                        elapsed = readQPC() - start;
                                    } else {
                                        cout << "Na jaka pozycje: ";
                                        cin >> index;
                                        start = readQPC();
                                        array->add(index, input);
                                        elapsed = readQPC() - start;
                                    }
                                } else if (operation == 'D') {
                                    start = readQPC();
                                    array->removeFirst();
                                    elapsed = readQPC() - start;
                                } else if (operation == 'E') {
                                    start = readQPC();
                                    array->removeLast();
                                    elapsed = readQPC() - start;
                                } else if (operation == 'F') {
                                    cout << "Pozycja do usuniecia: " << endl;
                                    cin >> index;
                                    start = readQPC();
                                    array->removeLast();
                                    elapsed = readQPC() - start;
                                } else if (operation == 'G') {
                                    cout << "Liczba do znalezienia: ";
                                    cin >> input;
                                    start = readQPC();
                                    found = array->contains(input);
                                    elapsed = readQPC() - start;
                                    if (found)
                                        cout << input << " znajduje sie w tablicy" << endl;
                                    else
                                        cout << input << " nie znajduje sie w tablicy" << endl;
                                } else if (operation == 'X') {
                                    structure = false;
                                } else {
                                    cout << "Nieprawidlowy wybor! Sproboj ponownie." << endl;
                                }
                                cout << "Time [s] = " << fixed << setprecision(30) << (float) elapsed /
                                                                                      frequency << endl;
                                cout << "Time [ms] = " << setprecision(30) << (1000.0 * elapsed) /
                                                                              frequency << endl;
                                cout << "Time [us] = " << setprecision(30) << (1000000.0 * elapsed) /
                                                                              frequency << endl << endl;
                            }
                            delete array;
                            break;
                        }

                        case 3: {
                            auto *heap = new BinaryHeap();
                            cout << "[3] Kopiec binarny" << endl;
                            random_numbers_to_txt();
                            //todo:think of reading numbers from txt file!
                            //fill the heap with random numbers form txt file
                            file.open(filepath, ios::in);
                            while (getline(file, tmp));
                            heap->add(atoi(tmp.c_str()));
                            file.close();

                            while (structure) {
                                cout << "(A) Dodawanie         (B) Usuwanie     (C) Wyszukiwanie" << endl;
                                cout << "(D) Czyszczenie kopca (X) Powrot" << endl;
                                cout << ": ";
                                cin >> operation;
                                switch (operation) {
                                    case 'A':
                                        cout << "Dodawana liczba: ";
                                        cin >> input;
                                        start = readQPC();
                                        heap->add(input);
                                        elapsed = readQPC() - start;
                                        break;
                                    case 'B':
                                        start = readQPC();
                                        heap->remove();
                                        elapsed = readQPC() - start;
                                        break;
                                    case 'C':
                                        cout << "Liczba do znalezienia: ";
                                        cin >> input;
                                        start = readQPC();
                                        found = heap->contains(input);
                                        elapsed = readQPC() - start;
                                        if (found)
                                            cout << input << "znajduje sie w kopcu." << endl;
                                        else
                                            cout << input << "nie znajduje sie w kopcu." << endl;
                                        break;
                                    case 'D':
                                        start = readQPC();
                                        heap->removeAll();
                                        elapsed = readQPC() - start;
                                        break;
                                    case 'X':
                                        structure = false;
                                        break;
                                    default:
                                        cout << "Nieprawidlowy wybor sproboj ponownie!" << endl;
                                        break;

                                }
                                cout << "Time [s] = " << fixed << setprecision(30) << (float) elapsed / frequency
                                     << endl;
                                cout << "Time [ms] = " << setprecision(30) << (1000.0 * elapsed) / frequency << endl;
                                cout << "Time [us] = " << setprecision(30) << (1000000.0 * elapsed) / frequency << endl;
                            }
                            break;
                        }

                        case 4: {
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

