# 1. Создать базовый класс (абстрактный класс или интерфейс) с виртуальными функциями ввода и вывода.
# 2. Создать производные классы: класс «дата», класс «время».
# В производных классах определить: скрытые поля, конструктор по умолчанию,
# конструктор с параметрами (с проверкой на корректность), метод для установки значений полей
# (с проверкой на корректность), метод для получения значений полей, методы для ввода и вывода.
# 3. Разработать демонстрационный класс. В этом классе определить массив или коллекцию ссылок на объекты базового класса
# , методы для добавления и удаления экземпляров классов, метод для вывода всех элементов.
# 4. Продемонстрировать работоспособность всех методов  классов.
# 5. Разработать программу, которая демонстрировала бы возможности сериализации.
# Для проверки введите данные с клавиатуры, сохраните информацию в файл
# (требуется сохранить несколько объектов разных классов из задания 1),
# затем прочитайте данные в цикле и выведите информацию на экран
# (в этом цикле неизвестно количество и порядок объектов в файле).
import random
class Base:
    def Out(self):
        raise NotImplemented("Метод не переопределен")

    def Enter(self):
        raise NotImplemented("Метод не переопределен")


class Time(Base):
    def validate(self):
        while self.__seconds >=60:
            self.__seconds-=60
            self.__minutes+=1
        while self.__minutes >=60:
            self.__minutes-=60
            self.__hours+=1

    def setTime(self, s):
        if len(s.split(':')) == 3:
            self.__hours = int(s.split(':')[0])
            self.__minutes = int(s.split(':')[1])
            self.__seconds = int(s.split(':')[2])
            self.validate()
        else:
            raise TypeError("Error with time string")

    def Enter(self):
        self.__hours = int(input('Input hours: '))
        self.__minutes = int(input('Input minutes: '))
        self.__seconds = int(input('Input seconds: '))
        self.validate()

    def Out(self):
       print(str(self.__hours).zfill(2),str(self.__minutes).zfill(2),str(self.__seconds).zfill(2),sep=':')

    def __init__(self, hours=0, minutes=0, seconds=0):
        if type(hours) is int and type(minutes) is int and type(seconds) is int:
            self.__hours = hours
            self.__minutes = minutes
            self.__seconds = seconds
            self.validate()
        else:
            raise TypeError("Error with type of time")

class Date(Base):
    month_n_day_list=[31,28,31,30,31,30,31,31,30,31,30,31]
    def validate(self):
        if self.__years % 4 == 0:
            self.month_n_day_list[1] = 29
        else:
            self.month_n_day_list[1]=28
        while self.__months > 12:
            self.__months-=12
            self.__years+=1

        while self.__days > self.month_n_day_list[self.__months - 1]:
            self.__days-=self.month_n_day_list[self.__months - 1]
            self.__months+=1

    def setDate(self, s):
        if len(s.split('.')) == 3:
            self.__year = int(s.split('.')[0])
            self.__months = int(s.split('.')[1])
            self.__days = int(s.split('.')[2])
            self.validate()
        else:
            raise TypeError("Error with time string")

    def Enter(self):
        self.__year = int(input('Input hours: '))
        self.__months = int(input('Input minutes: '))
        self.__days = int(input('Input seconds: '))
        self.validate()

    def Out(self):
        print(str(self.__days).zfill(2), str(self.__months).zfill(2), str(self.__years).zfill(4), sep='.')

    def __init__(self, days=0, months=0, years=0):
        if type(years) is int and type(months) is int and type(days) is int:
            self.__years = years
            self.__months = months
            self.__days = days
            self.validate()
        else:
            raise TypeError("Error with type of time")


if __name__ == '__main__':
    l=[]
    j=[]
    # Коллекция
    for i in range(10):
       l.append(Time(random.randint(0,59),random.randint(0,59),random.randint(0,100)))
    for each in l:
        each.Out()

    for i in range(10):
        j.append(Date(random.randint(1,31), random.randint(1, 12), random.randint(1900, 2077)))
    for each in j:
        each.Out()
