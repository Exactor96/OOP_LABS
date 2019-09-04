/*1. Разработать класс для работы с массивом чисел переменной длины. Класс должен содержать следующие элементы.
Поля (скрытые):
//количество элементов в массиве
//указатель на элементы массива
Методы:
//конструктор по умолчанию,  формирующий массив из 10 элементов, заполненный нулями
//конструктор, формирующий массив из заданного количества элементов, заполненных нулями
//конструктор-копировщик
//деструктор
метод для задания отдельных элементов массива
методы для ввода элементов массива с клавиатуры и вывода на экран
метод для удаления из массива  последнего элемента (при этом нужно уменьшить на 1 размер массива и освободить память)
метод для добавления в массив  последнего элемента (при этом нужно увеличить на 1 размер массива и выделить память для добавляемого элемента)
метод-функция для поиска требуемого элемента в массиве (метод возвращает -1, если элемент не найден, или индекс элемента в противном случае)
2. Реализовать для разработанного класса методы-операторы:
+ (плюс)  -  для  соединения двух массивов, при этом длина нового массива должна равняться сумме длин исходных массивов; в новом массиве сначала располагаются все элементы первого массива, а затем все элементы второго массива.
== (два знака равенства подряд)  - для сравнения двух массивов, результатом этой операции должно быть любое ненулевое значение, если массивы имеют одинаковые размеры и все соответствующие элементы равны между собой; в противном случае результату присвоить значение 0.
= (знак равенства) - присваивание
3. Реализовать класс в виде шаблона, позволяющего хранить данные различных типов.
4. Разработать программу, которая демонстрировала бы работоспособность всех методов данного класса.*/

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Vector{
    int count;
    T* data;
public:
    Vector(){
        count = 10;
        data = new T[count];
        for (int i = 0; i< count; i++){
            *(data+i) = 0;
        }
    }
    Vector(int elementsCount){
        count = elementsCount;
        data = new T[count];
        for (int i = 0; i< count; i++){
            *(data+i) = 0;
        }
    }
    Vector(const Vector<T> &vec){
        count = vec.count;
        data = new T[count];
        for (int i = 0; i < count; i++){
            *(data+i) = *(vec.data+i);
        }
    }
    void print(){
        for (int i = 0; i != count; i++){
            cout << *(data+i) << ' ' ;
        }
        cout << endl;
    }
    ~Vector(){
        delete[] data;
    }
    Vector<T> setElementOnPosition(int n, T element){
        if (n >= count)
            throw range_error("Index is out of range");
        *(data + n) = element;

        return *this;
    }

    Vector<T> enter(){
        for (int i = 0; i < count; i++)
            cin >> *(data + i);
        return *this;
    }

    Vector<T> pop_back(){
        if (count != 0){
            T* newData = new T[count--];
            for (int i = 0; i< count; i++)
                *(newData+i) = *(data + i);
            delete[] data;
            data = newData;
        }

        return *this;
    }

    Vector<T> push_back(T newElement){
        T* newData = new T[count++];
        for (int i = 0; i< count -1; i++)
            *(newData+i)= *(data + i);
        *(newData+count-1) = newElement;
        delete[] data;
        data = newData;

        return *this;
    }

    int search(T element){
        int found = -1;
        for (int i = 0; i < count; i++){
            if (*(data+i) == element){
                found = i;
                break;
            }
        }

        return found;
    }

    Vector<T> operator+(const Vector<T> &addictive){
        Vector<T> returnable(count+addictive.count);
        for (int i = 0; i < count; i++){
            *(returnable.data+i) = *(data+i);
        }
        for (int i = 0; i< addictive.count; i++){
            *(returnable.data+count+i) = *(addictive.data+i);

        }

        return returnable;
    }

    bool operator==(const Vector<T> comparing){
        if (count == comparing.count){
            for (int i = 0; i < count; i++) {
                if (*(data+i) != *(comparing.data+i))
                    return false;
            }
            return true;
        }
        return false;
    }

    Vector<T>& operator= (const Vector<T> &value){
        if (&value == this)
            return *this;
        delete[] data;
        count = value.count;
        data = new T[count];
        for (int i = 0; i < count; ++i) {
            *(data+i) = *(value.data+i);
        }
        return *this;
    }

};

int main() {
    Vector<int> v1;
    Vector<double> v2(5);
    cout << "v1: ";
    v1.print();
    cout << "v2: ";
    v2.print();
    try {
        v2.setElementOnPosition(4, 3);
    } catch (range_error &err){
        cout << err.what() << endl;
    }
    cout << "v2 after setting a new element at 4th position: ";
    v2.print();
    cout << "enter elements to set new numbers\nin v2 and copy the result in v4: ";
    Vector<double> v4 = v2.enter();
    cout << "new v2: ";
    v2.print();
    cout << "v4: ";
    v4.print();
    cout << "Equality of v2 and v4: " << (v2 == v4) << endl;
    v4.pop_back();
    v4.pop_back();
    cout << "v4 after popping 2 elements: ";
    v4.print();
    cout << "Equality of v2 and popped v4: " << (v2 == v4) << endl;
    v1.push_back(17);
    cout << "v1 after pushing 17: ";
    v1.print();
    v2.push_back(5.1);
    cout << "v2 after pushing 5.1: ";
    v2.print();
    cout << "position of 17 in v1:" << v1.search(17) << endl;
    v4 = v4 + v2;
    cout << "v4 after addition to v2: ";
    v4.print();
    v4 = v2;
    cout << "v4 after assigning a new vector: ";
    v4.print();
    cout << "there is v2 to compare it with v4: ";
    v2.print();

    return 0;
}
