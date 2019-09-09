package com.company;
/*1. Создать базовый класс «фигура» (абстрактный класс или интерфейс) с виртуальными функциями: площадь поверхности,
  объем, ввод и вывод информации о фигуре.
Создать производные классы: параллелепипед, тетраэдр, шар.
В производных классах определить: скрытые поля, конструктор по умолчанию, конструктор с параметрами,
методы для установки и получения значение полей, методы для расчета площади и объема, ввода и вывода информации.
2. Разработать программу, которая демонстрировала бы работоспособность всех методов  классов. Для проверки определить
коллекцию ссылок на базовый класс, которым присваиваются адреса различных объектов.
3. Разработать программу, которая демонстрировала бы возможности сериализации. Для проверки введите данные с клавиатуры,
 сохраните информацию в файл, затем прочитайте данные в цикле и выведите информацию на экран.
*/


import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Ball b = new Ball(10);
        b.info();
        Parallelepiped p = new Parallelepiped(1, 2, 3);
        p.info();
        Tetrahedron t = new Tetrahedron(4);
        t.info();


        Person [] arr = new Person[3];
        arr[0] = new Person();
        arr[1] = new Person();
        arr[2] = new Person();

        arr[0].setAge(23);
        arr[1].setAge(25);
        arr[2].setAge(21);

        arr[0].setFirstName("Max");
        arr[1].setFirstName("Ivan");
        arr[2].setFirstName("Kolya");

        arr[0].setLastName("K");
        arr[1].setLastName("B");
        arr[2].setLastName("T");

//        for (Person per: arr
//             ) {
//            System.out.println(per);
//
//        }



        FileOutputStream outputStream = new FileOutputStream("persons.ser");
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(outputStream);

        // сохраняем игру в файл
        for (Person pr: arr
             ) {
            objectOutputStream.writeObject(pr);
        }


        //закрываем поток и освобождаем ресурсы
        objectOutputStream.close();




        FileInputStream fileInputStream = new FileInputStream("persons.ser");
        ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);

        Person [] arr1 = new Person[3];
        int i=0;
        try {
            while(true) {
                arr1[i] = (Person) objectInputStream.readObject();
                System.out.println(arr1[i]);
                i++;
            }
        }catch (EOFException e){
            System.out.println("CATCHED: end of the file");
        }
        objectInputStream.close();



    }
}
