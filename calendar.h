#pragma once

#include <iostream>

enum YEAR { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
enum WEEK { SUN = 0, MON, TUE, WED, THU, FRI, SAT };

class Calendar
{

  private:
    int mYear;
    int mMonth;
    int mDay;

    bool isLeapYear(int year);
    void PrintDate(int year, int month, int day);
    void DisplayError(int error);
    int GetWeek(int year, int month);

  public:
    Calendar() = default;
    Calendar(int year = 1800, int month = 1, int day = 1);

    void SetDate(int year, int month, int day);
    void AddYear(int year);
    void AddMonth(int month);
    void AddDay(int day);
    void DisplayMonth(int year, int month); // 1800.1.1일, Wed(수)요일 (3)
    // void DisplayYear(int year);          // TODO: 1년 달력 출력이 필요함
};