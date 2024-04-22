#include <iostream>
#include <conio.h>
#include <chrono>

using namespace std;
using namespace chrono;

struct List {
    int data;
    List* head;
    List* tail;
};

List* createList(int length) {
    List* curr = nullptr, * next = nullptr;
    for (int i = 0; i < length; ++i) {
        curr = new List;
        curr->head = next;
        if (next)
            next->tail = curr;
        next = curr;
        curr->data = rand() % 199 - 99;
    }
    curr->tail = nullptr;
    return curr;
}

void deleteArr(int*& arr) {
    for (int i = 0; i < 25; i++) {
        arr[i] = 0;
    }
}

void deleteList(List*& beg) {
    List* next;
    while (beg) {
        next = beg->head;
        delete beg;
        beg = next;
    }
}

int getLength(List* beg) {
    int length = 0;
    while (beg) {
        ++length;
        beg = beg->head;
    }
    return length;
}

void addItem(List* beg, int length, int index, int num) {
    index--;
    List* item = new List;
    item->data = num;
    if (index == length) {
        List* temp = beg;
        while (temp->head != 0) {
            temp = temp->head;
        }
        item->head = temp->head;
        item->tail = temp;
        temp->head = item;
        return;
    }
    else if (index == 0) {
        item->head = beg;
        item->tail = nullptr;
        beg->tail = item;
        beg = item;
    }
    else {
        List* prevItem = beg;
        --index;
        while (prevItem->head && (index--)) {
            prevItem = prevItem->head;
        }
        item->head = prevItem->head;
        prevItem->head = item;
        item->tail = prevItem;
        item->head->tail = item;
    }
}

void addItem(int* arr, int length, int index, int num) {
    index--;
    for (int i = length; i > index; --i) {
        swap(arr[i], arr[i - 1]);
    }
    arr[index] = num;
}

void delItem(List*& beg, int index, int num) {
    if (index != 0) {
        List* curr = beg;
        index--;
        if (index == 0) {
            curr->head->tail = 0;
            beg = beg->head;
            delete curr;
            return;
        }
        while (curr->head != 0 && (index--)) {
            curr = curr->head;
        }
        List* prevItem = curr->tail;
        prevItem->head = curr->head;
        curr->head->tail = prevItem;
        delete curr;
        return;
    }
    else {
        List* curr = beg;
        index--;
        while (curr->data != num) {
            curr = curr->head;
        }
        List* prevItem = curr->tail;
        prevItem->head = curr->head;
        curr->head->tail = prevItem;
        delete curr;
        return;
    }
}

void delItem(int* arr, int length, int index, int num) {
    if (index != 0) {
        index--;
        arr[index] = 0;
        for (int i = index; i < length; i++) {
            swap(arr[i], arr[i + 1]);
        }
    }
    else {
        int i = 0;
        bool flag2 = false;
        while (i < length) {
            if (arr[i] == num && !flag2) {
                flag2 = true;
            }
            if (flag2) {
                swap(arr[i], arr[i + 1]);
            }
            i++;
        }
    }
}

void exchangeList(List*& beg, int index1, int index2) {
    List* curr = beg;
    if (index1 > index2)
        swap(index1, index2);
    index1--;
    index2--;
    for (int i = 0; i < index1; i++) {
        curr = curr->head;
    }
    List* list1 = curr;
    curr = beg;
    for (int i = 0; i < index2; i++) {
        curr = curr->head;
    }
    List* list2 = curr;
    List* temp = 0;
    if (list1->tail == list2)
    {
        if (list2->tail)
            list2->tail->head = list1;
        if (list1->head)
            list1->head->tail = list2;
        list1->tail = list2->tail;
        list2->head = list1->head;
        list2->tail = list1;
        list1->head = list2;
        if (list1 == beg)
            beg = list2;
        return;
    }
    if (list1->tail)
        list1->tail->head = list2;
    if (list2->tail)
        list2->tail->head = list1;
    if (list1->head)
        list1->head->tail = list2;
    if (list2->head)
        list2->head->tail = list1;
    temp = list1->tail;
    list1->tail = list2->tail;
    list2->tail = temp;
    temp = list1->head;
    list1->head = list2->head;
    list2->head = temp;
    if (list1 == beg)
        beg = list2;
    else if (list2 == beg)
        beg = list1;
    return;
}

void getItem(List*& beg, int index, int num) {
    if (index != 0) {
        List* curr = beg;
        index--;
        int temp = index;
        if (index == 0) {
            cout << "\nЭлемент №1 найден: " << curr->data;
            return;
        }
        while (curr->head != 0 && (index--)) {
            curr = curr->head;
        }
        cout << "\nЭлемент №" << temp+1 << " найден: " << curr->data;
        return;
    }
    else {
        List* curr = beg;
        index++;
        while (curr->data != num) {
            curr = curr->head;
            index++;
        }
        cout << "\nЭлемент №" << index << " найден: " << curr->data;
        return;
    }
}

void getItem(int* arr, int length, int index, int num) {
    if (index != 0) {
        index--;
        cout << "\nЭлемент в массиве найден: " << arr[index];
    }
    else {
        int i = 0;
        bool flag2 = false;
        while (i < length) {
            if (arr[i] == num && !flag2) {
                flag2 = true;
            }
            if (flag2) {
                cout << "\nЭлемент в массиве найден: " << arr[i];
                return;
            }
            i++;
        }
    }
}

List* copyList(int* arr, int length) {
    List* curr = nullptr, * next = nullptr;
    for (int i = 0; i < length; ++i) {
        curr = new List;
        curr->head = next;
        if (next)
            next->tail = curr;
        next = curr;
        curr->data = arr[i];
    }
    curr->tail = nullptr;
    return curr;
}

int* createMassive(List* beg) {
    int length = getLength(beg);
    int* arr2 = new int[length];
    int i = 0;
    List* curr = beg;
    while (curr) {
        arr2[i] = curr->data;
        curr = curr->head;
        ++i;
    }
    return arr2;
}

void printMassive(int* arr, int length) {
    cout << "Массив: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
}

void printList(List* beg) {
    List* curr = beg;
    int length = getLength(curr);
    for (int i = 1; i <= length; i++) {
        cout << "Элемент № " << i << ": " << curr->data << endl;
        curr = curr->head;
    }
    cout << endl;
}

void task1() {
    system("cls");
    List* list;
    int* arr = new int[25]();
    int size = 0;
    cout << "Введите размерность списка (массива): ";
    cin >> size;
    auto start1 = steady_clock::now();
    list = createList(size);
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    printList(list);
    deleteArr(arr);
    auto start2 = steady_clock::now();
    arr = createMassive(list);
    auto end2 = steady_clock::now();
    auto result2 = duration_cast<nanoseconds>(end2 - start2);
    printMassive(arr, size);
    cout << "\nВремя создания списка: " << result1.count() << " наносекунд\nВремя создания массива: " << result2.count() << " наносекунд";
    deleteList(list);
    deleteArr(arr);
    _getch();
}

void task2() {
    system("cls");
    List* list;
    int* arr = new int[25]();
    int size = 0;
    string s;
    bool flag = true;
    cout << "Введите элементы списка (массива), закончить словом 'end': \n";
    size = 0;
    while (flag) {
        cin >> s;
        if (s == "end") {
            flag = false;
        }
        else {
            arr[size] = stoi(s);
            size++;
        }
    }
    auto start1 = steady_clock::now();
    list = copyList(arr, size);
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    deleteArr(arr);
    auto start2 = steady_clock::now();
    arr = createMassive(list);
    auto end2 = steady_clock::now();
    auto result2 = duration_cast<nanoseconds>(end2 - start2);
    cout << "\nДвусвязный список: \n";
    printList(list);
    printMassive(arr, size);
    cout << "\nВремя создания списка: " << result1.count() << " наносекунд\nВремя создания массива: " << result2.count() << " наносекунд";
    deleteList(list);
    deleteArr(arr);
    _getch();
}

void task3() {
    system("cls");
    List* list;
    int size = 0;
    int* arr = new int[25]();
    cout << "Введите размерность списка (массива): ";
    cin >> size;
    list = createList(size);
    printList(list);
    deleteArr(arr);
    arr = createMassive(list);
    printMassive(arr, size);
    cout << "\n\nВведите номер нового элемента: ";
    int number, data;
    cin >> number;
    cout << "\nВведите значение элемента: ";
    cin >> data;
    auto start1 = steady_clock::now();
    addItem(list, size, number, data);
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    printList(list);
    auto start2 = steady_clock::now();
    addItem(arr, size, number, data);
    auto end2 = steady_clock::now();
    auto result2 = duration_cast<nanoseconds>(end2 - start2);
    size++;
    printMassive(arr, size);
    cout << "\nВремя добавления элемента в список: " << result1.count() << " наносекунд\nВремя добавления элемента в массив: " << result2.count() << " наносекунд";
    deleteList(list);
    deleteArr(arr);
    _getch();
}

void task4() {
    system("cls");
    int choice2;
    List* list;
    size_t size = 0;
    int* arr = new int[25]();
    cout << "Удаление \n1) по индексу\n2) по значению\n";
    cin >> choice2;
    if(choice2 == 1){
        cout << "Введите размерность списка (массива): ";
        cin >> size;
        list = createList(size);
        printList(list);
        deleteArr(arr);
        arr = createMassive(list);
        printMassive(arr, size);
        cout << "\n\nВведите номер удаляемого элемента: ";
        int number;
        cin >> number;
        auto start1 = steady_clock::now();
        delItem(list, number, 0);
        auto end1 = steady_clock::now();
        auto result1 = duration_cast<nanoseconds>(end1 - start1);
        printList(list);
        auto start2 = steady_clock::now();
        delItem(arr, size, number, 0);
        auto end2 = steady_clock::now();
        auto result2 = duration_cast<nanoseconds>(end2 - start2);
        size--;
        printMassive(arr, size);
        cout << "\nВремя удаления элемента в списке: " << result1.count() << " наносекунд\nВремя удаления элемента в массиве: " << result2.count() << " наносекунд";
        _getch();
    }
    if(choice2 == 2){
        cout << "Введите размерность списка (массива): ";
        cin >> size;
        list = createList(size);
        printList(list);
        deleteArr(arr);
        arr = createMassive(list);
        printMassive(arr, size);
        cout << "\n\nВведите значение удаляемого элемента: ";
        int data;
        cin >> data;
        auto start1 = steady_clock::now();
        delItem(list, 0, data);
        auto end1 = steady_clock::now();
        auto result1 = duration_cast<nanoseconds>(end1 - start1);
        printList(list);
        auto start2 = steady_clock::now();
        delItem(arr, size, 0, data);
        auto end2 = steady_clock::now();
        auto result2 = duration_cast<nanoseconds>(end2 - start2);
        size--;
        printMassive(arr, size);
        cout << "\nВремя удаления элемента в списке: " << result1.count() << " наносекунд\nВремя удаления элемента в массиве: " << result2.count() << " наносекунд";
        _getch();
    }
}

void task5() {
    List* list;
    int size = 0;
    int* arr = new int[25]();
    system("cls");
    cout << "Введите размерность списка (массива): ";
    cin >> size;
    list = createList(size);
    printList(list);
    deleteArr(arr);
    arr = createMassive(list);
    printMassive(arr, size);
    cout << "\n\nВведите номера обмениваемых элементов: ";
    int index1, index2;
    cin >> index1 >> index2;
    exchangeList(list, index1, index2);
    cout << "\nЭлементы поменялись\n";
    printList(list);
    swap(arr[index1 - 1], arr[index2 - 1]);
    printMassive(arr, size);
    _getch();
}

void task6() {
    system("cls");
    int choice2, size = 0;
    List* list;
    int* arr = new int[25]();
    int data;
    cout << "Получение \n1) по индексу\n2) по значению\n";
    cin >> choice2;
    if (choice2 == 1){
        cout << "Введите размерность списка (массива): ";
        cin >> size;
        list = createList(size);
        printList(list);
        deleteArr(arr);
        arr = createMassive(list);
        printMassive(arr, size);
        cout << "\n\nВведите номер элемента: ";
        int number;
        cin >> number;
        auto start1 = steady_clock::now();
        getItem(list, number, 0);
        auto end1 = steady_clock::now();
        auto result1 = duration_cast<nanoseconds>(end1 - start1);
        auto start2 = steady_clock::now();
        getItem(arr, size, number, 0);
        auto end2 = steady_clock::now();
        auto result2 = duration_cast<nanoseconds>(end2 - start2);
        cout << "\nВремя получения элемента в списке: " << result1.count() << " наносекунд\nВремя получения элемента из массива: " << result2.count() << " наносекунд";
        _getch();
    }
    else if(choice2 == 2){
        cout << "Введите размерность списка (массива): ";
        cin >> size;
        list = createList(size);
        printList(list);
        deleteArr(arr);
        arr = createMassive(list);
        printMassive(arr, size);
        cout << "\n\nВведите значение элемента элемента: ";
        cin >> data;
        auto start1 = steady_clock::now();
        getItem(list, 0, data);
        auto end1 = steady_clock::now();
        auto result1 = duration_cast<nanoseconds>(end1 - start1);
        auto start2 = steady_clock::now();
        getItem(arr, size, 0, data);
        auto end2 = steady_clock::now();
        auto result2 = duration_cast<nanoseconds>(end2 - start2);
        cout << "\nВремя получения элемента в списке: " << result1.count() << " наносекунд\nВремя получения элемента из массива: " << result2.count() << " наносекунд";
        _getch();
    }
}

void taskIdz() {
    system("cls");
    List* list;
    int size;
    int* arr = new int[25]();
    cout << "Введите размерность списка (массива): ";
    cin >> size;
    list = createList(size);
    printList(list);
    deleteArr(arr);
    arr = createMassive(list);
    printMassive(arr, size);
    cout << "\nСписок удалён, массив удалён";
    auto start1 = steady_clock::now();
    deleteList(list);
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    auto start2 = steady_clock::now();
    delete[] arr;
    auto end2 = steady_clock::now();
    auto result2 = duration_cast<nanoseconds>(end2 - start2);
    cout << "\nВремя удаления списка: " << result1.count() << " наносекунд\nВремя удаления массива: " << result2.count() << " наносекунд";
    _getch();
}

int main() {
    setlocale(0, "");
    int choice;
    int choice2;
    List* list;
    int* arr = new int[25]();
    int size = 0;
    string s;
    bool flag = true;
    while (flag) {
        system("cls");
        cout << "Что будем делать?\n";
        cout << "1. Создание двусвязного списка (динамического массива) размерности N\n";
        cout << "2. Создание двусвязного списка (динамического массива) неопределённой размерности (<25)\n";
        cout << "3. Вставка элемента в двусвязный список (динамический массив)\n";
        cout << "4. Удаление элемента двусвязного списка (динамического массива)\n";
        cout << "5. Обмен элемента двусвязного списка (динамического массива)\n";
        cout << "6. Получение элемента двусвязного списка (динамического массива)\n";
        cout << "7. Idz\n";
            cout << "8. Выход\n";
        cin >> choice;
        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7: 
            taskIdz();
            break;
        case 8:
            flag = false;
            system("cls");
            break;
        }

    }
    return 0;
}
