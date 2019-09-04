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
        Person person = new Person();
        person.setFirstName("Max");
        person.setLastName("K");
        person.setAge(23);
        System.out.println(person);
        FileOutputStream outputStream = new FileOutputStream("person.ser");
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(outputStream);

        // сохраняем игру в файл
        objectOutputStream.writeObject(person);

        //закрываем поток и освобождаем ресурсы
        objectOutputStream.close();

        person=null;

        System.out.println("Person = "+person);

        FileInputStream fileInputStream = new FileInputStream("person.ser");
        ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);

        person = (Person) objectInputStream.readObject();

        System.out.println(person);

        objectInputStream.close();


    }
}
