#include "calendar.h"

/// @brief 인수를 갖는 생성자
/// @param year, month, day (default 1800, 1, 1)
calendar::calendar(int year = 1800, int month = 1, int day = 1)
{
    mYear = year;
    mMonth = month;
    mDay = day;
}

void calendar::SetDate(int year, int month, int day)
{
    mYear = year;
    mMonth = month;
    mDay = day;
}

void calendar::AddYear(int year)
{
    int addYear = mYear + year;

    calendar::PrintDate(addYear, mMonth, mDay);
}

void calendar::AddMonth(int month)
{
    int addMonth = mMonth + month;
    int addYear = 0;

    addYear = mYear + (addMonth / 12);
    addMonth = addMonth % 12;

    calendar::PrintDate(addYear, addMonth, mDay);
}

void calendar::AddDay(int day)
{
    int MonthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int addYear = 0;
    int addMonth = 0;
    int addDay = 0;
    int index = 0;

    addDay = mDay + day;
    addYear = mYear + (addDay / 365);
    addDay = addDay % 365;

    // TODO: 윤년과 2월에 대한 처리가 안되고 있다....

    while (MonthDay[mMonth - 1 + index] < addDay)
    {
        addMonth++;
        addDay -= MonthDay[mMonth - 1 + index];
        index++;
        // TODO:for문으로 변경할까 ?
        if (12 == (mMonth - 1 + index))
        {
            index = 0;
        }
    }
}

bool calendar::isLeapYear(int year)
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

void calendar::DisplayYear(int year)
{
}

void calendar::DisplayMonth(int month)
{
}

void calendar::PrintDate(int year, int month, int day)
{
    std::cout << "\n\n\n";
    std::cout << "설정된 날짜는 " << mYear << "년" << mMonth << "월" << mDay << "일 입니다. \n";
    std::cout << "새로운 날짜는 " << year << "년" << month << "월" << day << "일 입니다. \n" << std::endl;
}
