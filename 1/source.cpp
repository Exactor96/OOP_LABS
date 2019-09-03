/*1. Разработать класс CTime для работы со значениями времени. Класс должен содержать следующие элементы.
Поля (скрытые):
часы
минуты
секунды
Методы:
конструктор по умолчанию,  заполняющий все поля нулевыми значениями;
конструктор, параметрами которого являются заданные значения для часов, минут и секунд;
конструктор-копировщик
методы-функции для задания значений времени и получения часов, минут и секунд
метод-функция для вывода времени на экран в общепринятом формате «чч:мм:сс» (можно предусмотреть и сокращенный вывод «чч:мм»)
методы-функции для выражения заданного отрезка времени в секундах и для перевода заданного количества секунд в переменную типа CTime
2.  Реализовать для разработанного класса методы-операторы:
+, - (плюс и минус)  - для сложения и вычитания значений времени, при этом все данные должны быть типа CTime
++, --(два плюса или два минуса подряд) – уменьшение или увеличение значения времени на 1 секунду
== (два знака равенства подряд)  - для сравнения двух значений времени, результатом этой операции должен быть 0, если значения неравны, и любое ненулевое значение в противном случае
3. Разработать программу, которая демонстрировала бы работоспособность всех  методов данного класса.
*/
#include <iostream>
#include <string>
class CTime{
private:
  unsigned int hours;
  unsigned int minutes;
  unsigned int seconds;

  void validate(){
    while (seconds>=60) {
      seconds-=60;
      minutes++;
    }
    while (minutes>=60) {
      minutes-=60;
      hours++;
    }
  }

public:
  CTime setTime(int s_hours, int s_minutes, int s_seconds){
    if (s_hours>=0 && s_minutes >=0 && s_seconds >=0) {
      hours=s_hours;
      minutes=s_minutes;
      seconds=s_seconds;
      validate();
    }
    else{
      if (s_hours<0) {
        hours=-s_hours;
      } else {
        hours=s_hours;
      }
      if (s_minutes<0) {
        minutes=-s_minutes;
      } else {
        minutes=s_minutes;
      }
      if (seconds<0) {
        seconds=-s_seconds;
      } else {
        seconds=s_seconds;

        validate();
      }
    }
  }

  CTime(){
    hours=minutes=seconds=0;
  }
  CTime(int hours, int minutes, int seconds){
    setTime(hours,minutes,seconds);
  }
  CTime(const CTime &c){
    hours=c.hours;
    minutes=c.minutes;
    seconds=c.seconds;
  }
  unsigned int getHours(){
    return hours;
  }

  unsigned int getMinutes(){
    return minutes;
  }

  unsigned int getSeconds(){
    return seconds;
  }
  std::string getStringTime(){
    std::string res="";
    if (hours<=9) {
      res+="0"+std::to_string(hours)+":";
    }
    else{
      res+=std::to_string(hours)+":";
    }
    if (minutes<=9) {
      res+="0"+std::to_string(minutes)+":";
    }
    else{
      res+=std::to_string(minutes)+":";
    }
    if (seconds<=9) {
      res+="0"+std::to_string(seconds);
    } else {
      res+=std::to_string(seconds);
    }
    return res;
  }
  void fromseconds(int sec){
    hours=minutes=0;
    seconds=sec;
    validate();
  }
  unsigned int toseconds(){
    return 3600*hours+60*minutes+seconds;
  }

  CTime& operator++ () //преф
      {
          seconds += 1;
          validate();
          return *this;
      }
      CTime& operator-- ()//преф
      {
          seconds -= 1;
          validate();
          return *this;
      }

      CTime operator++ (int)
          {
              CTime prev = *this;
              ++*this;
              return prev;
          }
          CTime operator-- (int)
          {
              CTime prev = *this;
              --*this;
              return prev;
          }
          bool operator== (CTime &ct)
          {
            if ((seconds==ct.seconds) && (minutes==ct.minutes) && (hours==ct.hours))
            return 1;
          else
            return 0;
}

    CTime operator+ (CTime &ct){
      return CTime(hours+ct.getHours(),minutes+ct.getMinutes(),seconds+ct.getSeconds());
    }
    CTime operator- (CTime &ct){
      int r=toseconds();
      r-=ct.toseconds();

      if (r>=0) {
        return CTime(0,0,r);
      } else {
        return CTime(0,0,-r);
      }

    }

};


int main(int argc, char const *argv[]) {
  CTime ct1;
  std::cout << "empty constructor" << '\t' << ct1.getStringTime() << '\n';
  CTime ct2(0,1,123);
  std::cout << "0,1,123 constructor" << '\t' << ct2.getStringTime()<<'\n';
  CTime ct3(ct2);
  std::cout << "setting ct1 01:00:00" << '\n';
  ct1.setTime(1,0,0);
  std::cout << "copy-constructor" << '\t'<<ct3.getStringTime()<<'\n';
  std::cout << "== operator" << '\t'<< (ct3==ct2) << '\n';
  std::cout << "ct2-ct1" << '\t'<<(ct2-ct1).getStringTime() << '\n';
  std::cout << "ct2+ct1" << '\t'<<(ct2+ct1).getStringTime() << '\n';
  std::cout << "ct1++" << '\t'<<(ct1++).getStringTime()<<'\n';
  std::cout << "ct1--" << '\t'<<(ct1--).getStringTime()<<'\n';
  std::cout << "fromseconds 600" << '\t';
  ct3.fromseconds(600);
  std::cout << ct3.getStringTime() << '\n';
  std::cout << "toseconds" << '\t'<<ct3.toseconds()<<'\n';

  return 0;
}
