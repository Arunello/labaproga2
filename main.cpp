#include <chrono>
#include <cmath>
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime> 
#include <utility>

using namespace std;
using namespace chrono;

// Необходимо написать программу, которая:
// 1)    Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.
// 3)    Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.
// 4)    Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения в отсортированном и неотсортированном. 
// Выводит индексы всех элементов, которые равны этому значению, и их количество. Подсчитайте время поиска.
// 5)    Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.
// 6)    Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.
// 7)    Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска. 
// Сравните скорость его работы с обычным перебором. (*)
// 8)     Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono.
// Должна присутствовать возможность запуска каждого пункта многократно.

int main() {
    
    setlocale(0, "");

    bool escape = false;
    int arr [100];
    srand(time(NULL));
    for (int i = 0; i<100; i++) {arr[i] = rand() % 199 - 99;}

    while (!escape) {

    std::cout << "Текущий массив: " << "\n";
    for (int i = 0; i<100; i++) {

        std::cout << arr[i] << " ";
        if (i % 33 == 0 && i != 0) {
            std::cout << "\n";
        }
        
    }

    std::cout << "\n"
    << "1. Сгенерировать новый массив из ста целых чисел" << "\n"
    << "2. Отсортировать массив и замерить время сортировки" << "\n"
    << "3. Найти максимальный и минимальный элемент массива" << "\n"
    << "9. Готово!" << "\n";
    
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    std::cout << "\n\n\n\n\n\n\n";
    
    switch (choice) {
        case 1:
            for (int i = 0; i<100; i++) {arr[i] = rand() % 199 - 99;}
        break;

        case 2: {
            int tempArr [100];
            for (int i = 0; i<100; i++) {tempArr[i] = arr[i];}
            auto start = steady_clock::now();

            bool sorted = false;
            while (!sorted) {
                sorted = true;
                for (int i = 0; i < 99; i++) {
                    if (tempArr[i] > tempArr[i + 1]) {
                        swap(tempArr[i], tempArr[i + 1]);
                        sorted = false;
                    }
                }
            }

            auto end = steady_clock::now();
            auto result = duration_cast<nanoseconds>(end-start);
            
            std::cout << "Время затраченное на сортировку: " << result.count() << " " << "наносекунд." << "\n\n" 
            << "Отсортированный массив: " << "\n";

            for (int i = 0; i < 100; i++){

                std::cout << tempArr[i] << " ";
                if (i % 33 == 0 && i != 0) {
                std::cout << "\n";
                }

            }

            std::cin.get();
            std::cout << "\n\n\n\n\n\n\n";
        break;
        }

        case 3: {

            int max = -100;
            int min = 100;

            
            auto start1 = steady_clock::now();

            for (int i = 0; i < 100; i++) {
                if (arr[i] < min) {min = arr[i];}
                if (arr[i] > max) {max = arr[i];}
            }

            auto end1 = steady_clock::now();
            auto unsortedResult = duration_cast<nanoseconds>(end1-start1);
            

            
            int tempArr [100];
            for (int i = 0; i<100; i++) {tempArr[i] = arr[i];}

            bool sorted = false;
            while (!sorted) {
                sorted = true;
                for (int i = 0; i < 99; i++) {
                    if (tempArr[i] > tempArr[i + 1]) {
                        swap(tempArr[i], tempArr[i + 1]);
                        sorted = false;
                    }
                }
            }

            auto start2 = steady_clock::now();

            min = tempArr[0];
            max = tempArr[99];

            auto end2 = steady_clock::now();
            
            auto sortedResult = duration_cast<nanoseconds>(end2-start2);
            
            std::cout << "Максимальный элемент: " << max << "\n"
            << "Минимальный элемент: " << min << "\n\n"
            << "Время затраченное на поиск элементов в неотсортированном массиве: " << unsortedResult.count() << "наносекунд" << "\n"
            << "Время затраченное на поиск элементов в отсортированном массиве: " << sortedResult.count() << "наносекунд" << "\n";

            std::cin.get();
            std::cout << "\n\n\n\n\n\n\n";
        break;
        }
        case 9:
        escape = true;
        break;
    }
}
}