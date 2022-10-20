#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <chrono>
#include <fstream>
void counting_sort(std::vector<unsigned int>& array) {
    unsigned int min, max;
    max = min = array[0];
    for (size_t i = 1; i < array.size(); i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    std::vector<unsigned int> counts(max - min + 1, 0);

    for (unsigned int i : array) {
        counts[i - min]++;
    }

    size_t index = 0;
    // пробегаем по всем счетчикам
    // count[i] - показывает сколько раз встречается то или иное число
    for (size_t i = 0; i < counts.size(); i++) {
        for (size_t j = 0; j < counts[i]; j++) {
            array[index++] = i + min;
        }
    }
}
/* сравнение двух целых */
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
void qsort(std::vector<unsigned int>& array){
    qsort(&array[0],array.size(),sizeof(int),compare);
}
void selection_sort(std::vector<unsigned int>& array) {
    for (auto it = array.begin(); it != array.end(); ++it) {
        std::swap(*it, *std::min_element(it, array.end()));
    }
}
std::vector<unsigned int> sixteen() {
    std::vector<unsigned int> array;
    std::ifstream file("/Users/kkrasilnikovv/CLionProjects/Laba_Algoritm/d16.txt");
    if (file) {
        while (true) {
            int n = 0;
            file >> n;
            array.push_back(n);
            if (file.eof()) {
                break;
            }
        }
    }
    return array;
}
std::vector<unsigned int> one_hundred() {
    std::vector<unsigned int> array;
    std::ifstream file("/Users/kkrasilnikovv/CLionProjects/Laba_Algoritm/d100.txt");
    if (file) {
        while (true) {
            int n = 0;
            file >> n;
            array.push_back(n);
            if (file.eof()) {
                break;
            }
        }
    }
    return array;
}
std::vector<unsigned int> five_hundred() {
    std::vector<unsigned int> array;
    std::ifstream file("/Users/kkrasilnikovv/CLionProjects/Laba_Algoritm/d500.txt");
    if (file) {
        while (true) {
            int n = 0;
            file >> n;
            array.push_back(n);
            if (file.eof()) {
                break;
            }
        }
    }
    return array;
}
std::vector<unsigned int> one_thousand() {
    std::vector<unsigned int> array;
    std::ifstream file("/Users/kkrasilnikovv/CLionProjects/Laba_Algoritm/d1000.txt");
    if (file) {
        while (true) {
            int n = 0;
            file >> n;
            array.push_back(n);
            if (file.eof()) {
                break;
            }
        }
    }
    return array;
}
std::vector<unsigned int> five_thousand() {
    std::vector<unsigned int> array;
    std::ifstream file("/Users/kkrasilnikovv/CLionProjects/Laba_Algoritm/d5000.txt");
    if (file) {
        while (true) {
            int n = 0;
            file >> n;
            array.push_back(n);
            if (file.eof()) {
                break;
            }
        }
    }
    return array;
}
void sixteen_sort(){
    std::cout<<"Размер входных данных: 16\n";
    std::vector<unsigned int> array1 = sixteen();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout<<'\n';
    std::cout<<'\n';
}
void one_hundred_sort(){
    std::cout<<"Размер входных данных: 100\n";
    std::vector<unsigned int> array1 = one_hundred();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout<<'\n';
    std::cout<<'\n';
}
void five_hundred_sort(){
    std::cout<<"Размер входных данных: 500\n";
    std::vector<unsigned int> array1 = five_hundred();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout<<'\n';
    std::cout<<'\n';
}
void one_thousand_sort(){
    std::cout<<"Размер входных данных: 1000\n";
    std::vector<unsigned int> array1 = one_thousand();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout<<'\n';
    std::cout<<'\n';
}
void five_thousand_sort(){
    std::cout<<"Размер входных данных: 5000\n";
    std::vector<unsigned int> array1 = five_thousand();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout<<'\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    std::cout<<"Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout<<'\n';
    std::cout<<'\n';
}

int main() {
    sixteen_sort();
    one_hundred_sort();
    five_hundred_sort();
    one_thousand_sort();
    five_thousand_sort();
}