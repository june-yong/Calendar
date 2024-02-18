#pragma once

#include <iostream>

class calendar
{
  private:
    int mYear;
    int mMonth;
    int mDay;

    bool isLeapYear(int year);
    void PrintDate(int year, int month, int day);

  public:
    calendar() = default;
    calendar(int year = 1800, int month = 1, int day = 1);

    void SetDate(int year, int month, int day);
    void AddYear(int year);
    void AddMonth(int month);
    void AddDay(int day);

    void DisplayYear(int year);
    void DisplayMonth(int month);
};