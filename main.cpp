#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <chrono>
#include <fstream>

bool check_sort(std::vector<unsigned int> &array) {
    for (int i = 0; i < array.size(); i++) {
        if (i + 1 != array.size()) {
            if (array.at(i) > array.at(i + 1)) {
                return false;
            }
        }
    }

    return true;
}

void counting_sort(std::vector<unsigned int> &array) {
    int const SIZE = array.size();
    int *count = new int[SIZE];
    std::vector<unsigned int> temp(SIZE);
    for (int i = 0; i < SIZE; i++) {
        count[i] = 0;
    }
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (array[i] < array[j])
                count[j]++;
            else
                count[i]++;
        }
    }
    for (int i = 0; i < array.size(); i++) {
        temp[count[i]] = array.at(i);
    }
    array = temp;
}


/* сравнение двух целых */
int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void qsort(std::vector<unsigned int> &array) {
    qsort(&array[0], array.size(), sizeof(int), compare);
}


void selection_sort(std::vector<unsigned int> &array) {
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
    array.pop_back();
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
    array.pop_back();
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
    array.pop_back();
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
    array.pop_back();
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
    array.pop_back();
    return array;
}

void sixteen_sort() {
    std::cout << "Размер входных данных: 16\n";
    std::vector<unsigned int> array1 = sixteen();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array1)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array1)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array3)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << '\n';
    std::cout << '\n';
}

void one_hundred_sort() {
    std::cout << "Размер входных данных: 100\n";
    std::vector<unsigned int> array1 = one_hundred();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array1)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array2)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array3)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << '\n';
    std::cout << '\n';
}

void five_hundred_sort() {
    std::cout << "Размер входных данных: 500\n";
    std::vector<unsigned int> array1 = five_hundred();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array1)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array2)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array3)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << '\n';
    std::cout << '\n';
}

void one_thousand_sort() {
    std::cout << "Размер входных данных: 1000\n";
    std::vector<unsigned int> array1 = one_thousand();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array1)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array2)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array3)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << '\n';
    std::cout << '\n';
}

void five_thousand_sort() {
    std::cout << "Размер входных данных: 5000\n";
    std::vector<unsigned int> array1 = five_thousand();
    std::vector<unsigned int> array2 = array1;
    std::vector<unsigned int> array3 = array1;
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    counting_sort(array1);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array1)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка подсчетом: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    selection_sort(array2);
    const std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array2)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Сортировка выбором: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << '\n';
    const std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
    qsort(array3);
    const std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
    if (!check_sort(array3)) {
        std::cout << "Предыдущая сортировка неверна!\n";
    }
    std::cout << "Время алгоритма - Qsort: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << '\n';
    std::cout << '\n';
}

int main() {
    sixteen_sort();
    one_hundred_sort();
    five_hundred_sort();
    one_thousand_sort();
    five_thousand_sort();
}