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
    std::cout << "\n\n\n";
    std::cout << "설정된 날짜는 " << mYear << "년" << mMonth << "월" << mDay << "일 입니다. \n";
    std::cout << year << "년이 지나면 \n";
    year += mYear;
    std::cout << "새로운 날짜는 " << year << "년" << mMonth << "월" << mDay << "일 입니다. \n" << std::endl;
}

void calendar::AddMonth(int month)
{
    mMonth += month;
    calendar::PrintDate(mMonth);
}

void calendar::AddDay(int day)
{
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

void calendar::PrintDate(int day)
{
    std::cout << day << std::endl;
}
