#include "calendar.h"

Calendar::Calendar(int year, int month, int day)
{
    mYear = year;
    mMonth = month;
    mDay = day;
}

void Calendar::SetDate(int year, int month, int day)
{
    mYear = year;
    mMonth = month;
    mDay = day;
}

void Calendar::AddYear(int year)
{
    int addYear = mYear + year;

    Calendar::PrintDate(addYear, mMonth, mDay);
}

void Calendar::AddMonth(int month)
{
    int addMonth = mMonth + month;
    int addYear = 0;

    addYear = mYear + (addMonth / 12);
    addMonth = addMonth % 12;

    Calendar::PrintDate(addYear, addMonth, mDay);
}

// 월의 날짜를 뺀거잖아
void Calendar::AddDay(int day)
{
    int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int addYear = mYear;
    int addMonth = mMonth;
    int addDay = mDay + day;

    while (addDay > MonthDay[addMonth])
    {
        if (2 == addMonth)
        {
            if (isLeapYear(addYear))
            {
                addDay -= 29;
            }
            else
            {
                addDay -= 28;
            }
        }
        else
        {
            addDay -= MonthDay[addMonth];
        }

        addMonth++;
        if (13 <= addMonth)
        {
            addYear++;
            addMonth = 1;
        }
    }

    Calendar::PrintDate(addYear, addMonth, addDay);
}

bool Calendar::isLeapYear(int year)
{
    if (0 == year % 4 && 0 != year % 100 || 0 == year % 400)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// TODO: 1년 달력 출력 구현하기
/* void Calendar::DisplayYear(int year)
{
    // 횡으로 3달을 한번에 출력해야 되는데...
}
 */

void Calendar::DisplayMonth(int year, int month)
{
    // 주어진 해, 달의 첫날의 요일은 ??
    std::cout << "...?....?\n";
}

void Calendar::PrintDate(int year, int month, int day)
{
    std::cout << "\n\n\n";
    std::cout << "설정된 날짜는 " << mYear << "년" << mMonth << "월" << mDay << "일 입니다. \n";
    std::cout << "새로운 날짜는 " << year << "년" << month << "월" << day << "일 입니다. \n" << std::endl;
}
