#pragma once

#include <iostream>

class Calendar
{
    // 1800.1.1 is Wed;
  private:
    int mYear;
    int mMonth;
    int mDay;

    bool isLeapYear(int year);
    void PrintDate(int year, int month, int day);

  public:
    Calendar() = default;
    Calendar(int year = 1800, int month = 1, int day = 1);

    void SetDate(int year, int month, int day);
    void AddYear(int year);
    void AddMonth(int month);
    void AddDay(int day);

    // TODO: 1년 달력 출력이 필요함
    // void DisplayYear(int year);
    void DisplayMonth(int year, int month);
};