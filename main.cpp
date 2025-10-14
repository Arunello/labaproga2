#include <chrono>
#include <cmath>
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime> 
#include <utility>

using namespace std;
using namespace chrono;

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int opora = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < opora) ++i;
        while (arr[j] > opora) --j;

        if (i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }

    if (left < j)  quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int TempArr [100];

int main() {
    
    setlocale(0, "");

    bool escape = false;
    int arr [100];
    srand(time(NULL));
    for (int i = 0; i<100; i++) {arr[i] = rand() % 199 - 99;}



    while (!escape) {

        for (int i = 0; i < 100; i++) {TempArr[i] = arr[i];}

        std::cout << "Текущий массив: " << "\n";
        for (int i = 0; i < 100; i++) {
            std::cout << arr[i] << " ";
            if (i % 33 == 0 && i != 0) {std::cout << "\n";}
        }

        std::cout << "\n"
        << "1. Сгенерировать новый массив из ста целых чисел" << "\n"
        << "2. Отсортировать массив" << "\n"
        << "3. Найти максимальный и минимальный элемент массива" << "\n"
        << "4. Найти среднее значение максимального и минимального элемента, индексы элементов в массиве равные среднему занчению и их количество в отсортированном и неотсортированном массиве" << "\n"
        << "5. Найти количество элементов меньше заданного числа в отсортированном массиве" << "\n"
        << "6. Найти количество элементов больше заданного числа в отсортированном массиве" << "\n"
        << "7. Проверка наличия произвольного элемента в массиве" << "\n"
        << "8. Поменять местами произвольные элементы массива" << "\n"
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
                auto start = steady_clock::now();


                bool sorted = false;
                while (!sorted) {
                    sorted = true;
                    for (int i = 0; i < 99; i++) {
                        if (TempArr[i] > TempArr[i + 1]) {
                            swap(TempArr[i], TempArr[i + 1]);
                            sorted = false;
                        }
                    }
                }


                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end-start);
                

                std::cout << "Время затраченное на сортировку: " << result.count() << " " << "наносекунд" << "\n\n" 
                << "Отсортированный массив: " << "\n";

                for (int i = 0; i < 100; i++) {
                    std::cout << TempArr[i] << " ";
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
                auto unsortedResult = duration_cast<nanoseconds>(end1 - start1);


                quickSort(TempArr, 0, 99);


                auto start2 = steady_clock::now();


                min = TempArr[0];
                max = TempArr[99];


                auto end2 = steady_clock::now();
                auto sortedResult = duration_cast<nanoseconds>(end2 - start2);
                

                std::cout << "Максимальный элемент: " << max << "\n"
                << "Минимальный элемент: " << min << "\n\n"
                << "Время затраченное на поиск элементов в неотсортированном массиве: " << unsortedResult.count() << "наносекунд" << "\n"
                << "Время затраченное на поиск элементов в отсортированном массиве: " << sortedResult.count() << "наносекунд" << "\n";



                std::cin.get();
                std::cout << "\n\n\n\n\n\n\n";
            break;
            } 





            case 4: {
                int max = -100;
                int min = 100;
                int avg;
                int k = 0;


                auto start1 = steady_clock::now();

                for (int i = 0; i < 100; i++) {
                    if (arr[i] < min) {min = arr[i];}
                    if (arr[i] > max) {max = arr[i];}
                }

                avg = round((max + min) / 2.0);

                std::cout << "Неотсортированный массив" << "\n\n"
                << "Среднее значение максимального и минимального элементов: " << avg << "\n"
                << "Индексы элементов равные среднему значению: ";

                bool found = false;
                for (int i = 0; i < 100; i++) {
                    if (arr[i] == avg) {
                        found = true;
                        std::cout << i << " ";
                        k++;
                    }
                }
                
                if (found == false) {std::cout << "индексы не найдены";}

                std::cout << "\nКоличество элементов равных среднему значению: " << k << "\n";


                auto end1 = steady_clock::now();
                auto unsortedResult = duration_cast<nanoseconds>(end1 - start1);

                std::cout << "Время затраченное на поиск среднего значения, индексов элементов равных среднему значению в неотсортированном массиве: " << unsortedResult.count()
                << "\n\n\n";



                max = -100;
                min = 100;
                k = 0;

                bool sorted = false;     
                int start = 0;
                int end = 99;

                while (!sorted) {
                    sorted = true;
                
                    for (int i = start; i < end; i++) {
                        if (TempArr[i] > TempArr[i + 1]) {
                        std::swap(TempArr[i], TempArr[i + 1]);
                        sorted = false;
                        }
                    }
                
                    if (sorted) {
                        break;
                    }

                    end--;
                
                    for (int i = end; i >= start; i--) {
                        if (TempArr[i] > TempArr[i + 1]) {
                            std::swap(TempArr[i], TempArr[i + 1]);
                            sorted = false;
                        }
                    }

                    start++;
                }


                auto start2 = steady_clock::now();


                min = TempArr[0];
                max = TempArr[99];
                avg = round((max + min) / 2.0);

                std::cout << "Отсортированный массив" << "\n\n"
                << "Среднее значение максимального и минимального элементов: " << avg << "\n"
                << "Индексы элементов равные среднему значению: ";

                int left = 0;
                int right = 99;
                int mid;
                found = false;

                while (left <= right) {
                    mid = left + (right - left) / 2;
                
                    if (TempArr[mid] == avg) {
                        found = true;
                        std::cout << mid << " ";
                        k++;
                    
                        int i = mid - 1;
                        while (i >= 0 && TempArr[i] == avg) {
                            std::cout << i << " ";
                            k++;
                            i--;
                        }
                        
                        i = mid + 1;
                        while (i < 100 && TempArr[i] == avg) {
                            std::cout << i << " ";
                            k++;
                            i++;
                        }
                        break;
                    }
                    if (TempArr[mid] < avg) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }

                if (!found) {std::cout << "индексы не найдены";}

                std::cout << "\nКоличество элементов равных среднему значению: " << k << "\n";


                auto end2 = steady_clock::now();
                auto sortedResult = duration_cast<nanoseconds>(end2 - start2);


                std::cout << "Время затраченное на поиск среднего значения, индексов элементов равных среднему значению в отсортированном массиве: " << sortedResult.count() << "\n";



                std::cin.get();
                std::cout << "\n\n\n\n\n\n\n";
            break;
            }





            case 5: {
                int a;
                std::cout << "Введите целое число..." << "\n";
                std::cin >> a;
                std::cin.ignore();



                int gap = 100;
                bool swapped = true;

                while (gap > 1 || swapped) {
                    gap = int(gap / 1.247);

                    if (gap < 1) {gap = 1;}
                    swapped = false;

                    for (int i = 0; i + gap < 100; i++) {
                        if (TempArr[i] > TempArr[i + gap]) {
                            swap(TempArr[i], TempArr[i + gap]);
                            swapped = true;
                        }
                    }
                }



                int left = 0;
                int right = 100;
                
                while (left < right) {
                    int mid = left + (right - left) / 2;

                    if (TempArr[mid] < a) {
                        left = mid + 1;
                    }
                    else {
                        right = mid;
                    }
                }

                int k = left;
                
                std::cout << "Количество элементов меньше заданного числа: " << k << "\n";



                std::cin.get();
                std::cout << "\n\n\n\n\n\n\n";
            break;
            }





            case 6: {
                int b;
                std::cout << "Введите целое число..." << "\n";
                std::cin >> b;
                std::cin.ignore();



                int gap = 100;
                bool swapped = true;

                while (gap > 1 || swapped) {
                    gap = int(gap / 1.247);

                    if (gap < 1) {gap = 1;}
                    swapped = false;

                    for (int i = 0; i + gap < 100; i++) {
                        if (TempArr[i] > TempArr[i + gap]) {
                            swap(TempArr[i], TempArr[i + gap]);
                            swapped = true;
                        }
                    }
                }



                int left = 0;
                int right = 100;
                
                while (left < right) {
                    int mid = left + (right - left) / 2;

                    if (TempArr[mid] < b) {
                        left = mid + 1;
                    }
                    else {
                        right = mid;
                    }
                }

                int k = 100 - left;
                
                std::cout << "Количество элементов больше заданного числа: " << k << "\n";



                std::cin.get();
                std::cout << "\n\n\n\n\n\n\n";
            break;
            }





            case 7: {
                int number;
                std::cout << "Введите целое число..." << "\n";
                std::cin >> number;
                std::cin.ignore();



                for (int i = 1; i < 100; i++) {
                    int key = TempArr[i];      
                    int j = i - 1;            

                    while (j >= 0 && TempArr[j] > key) {
                        TempArr[j + 1] = TempArr[j];
                        j--;
                    }

                    TempArr[j + 1] = key;
                }



                auto start1 = steady_clock::now();


                int left = 0;
                int right = 99;
                int mid;
                bool found = false;

                while (left <= right) {
                    mid = left + (right - left) / 2;

                    if (TempArr[mid] == number) {
                        found = true;
                        break;
                    }
                    if (TempArr[mid] < number) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }


                auto end1 = steady_clock::now();
                auto binaryResult = duration_cast<nanoseconds>(end1 - start1);

                std::cout << "Время затраченное на поиск бинарным поиском: " << binaryResult.count() << "\n";



                auto start2 = steady_clock::now();


                for (int i = 0; i < 100; i++) {
                    if (TempArr[i] == number) {
                        break;
                    }
                }


                auto end2 = steady_clock::now();
                auto notBinaryResult = duration_cast<nanoseconds>(end2 - start2);

                
                std::cout << "Время затраченное на поиск перебором: " << notBinaryResult.count() << "\n";
                cout << (found ? "Элемент найден\n" : "Элемент не найден\n");



                std::cin.get();
                std::cout << "\n\n\n\n\n\n\n";
            break;
            }





            case 8: {
                int firstNumber, secondNumber;

                std::cout << "Введите индекс первого элемента" << "\n";
                std::cin >> firstNumber;

                std::cout << "Введите индекс второго элемента" << "\n";
                std::cin >> secondNumber;
                
                std::cin.ignore();



                if ((0 <= firstNumber && firstNumber <= 99) && (0 <= secondNumber && secondNumber <= 99)) {
                    auto start = steady_clock::now();


                    swap(TempArr[firstNumber], TempArr[secondNumber]);


                    auto end = steady_clock::now();
                    auto result = duration_cast<nanoseconds>(end - start);

                    
                    std::cout << "Время затраченное на обмен: " << result.count() << "\n";
                }
                else {
                    std::cout << "Индексы выходят за пределы массива!";
                }



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

