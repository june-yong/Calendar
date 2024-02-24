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
        if (FEB == addMonth)
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
} */

int Calendar::GetWeek(int year, int month)
{
    int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int LeapYearCount = 0;
    int DisplayWeek = 0;
    int DisplayMonth = 0;

    if (1800 > year)
    {
        Calendar::DisplayError(1);
    }

    for (int i = 1800; i <= year; ++i)
    {
        if (isLeapYear(i))
        {
            LeapYearCount++;
        }
    }

    // 달력 표시할 전달까지의 날짜수 구하기
    if (FEB < month)
    {
        DisplayWeek = (year - 1800) * 365;
        DisplayWeek += LeapYearCount;

        for (int i = 1; i <= month - 1; ++i)
        {
            DisplayWeek += MonthDay[i];
        }
    }
    else
    {
        DisplayWeek = (year - 1800) * 365;
        DisplayWeek += (LeapYearCount - 1);

        for (int i = 0; i <= month - 1; ++i)
        {
            DisplayWeek += MonthDay[i];
        }
    }

    DisplayWeek += 3; // 1800.1.1 WED (3)
    DisplayWeek %= 7;

    return DisplayWeek;
}

void Calendar::DisplayMonth(int year, int month)
{
    int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int DisplayWeek = 0;
    int DisplayMonth = 0;

    DisplayWeek = Calendar::GetWeek(year, month);
    DisplayMonth = MonthDay[month];
    if (isLeapYear(year) == true)
    {
        if (FEB == month)
        {
            DisplayMonth = 29;
        }
    }

    std::cout << "\n\n\n";
    std::cout << "      " << year << " 년    " << month << " 월\n";
    std::cout << "----------------------------\n";
    std::cout << " SUN MON TUE WED THU FRI SAT\n";
    for (int i = 0; i < DisplayWeek; ++i)
    {
        std::printf("%4s", " ");
    }

    for (int i = 1; i <= DisplayMonth; ++i)
    {

        std::printf("%4d", i);

        if (0 == (i + DisplayWeek) % 7)
        {
            std::cout << std::endl;
        }
    }
    std::cout << "\n\n\n";
}

void Calendar::PrintDate(int year, int month, int day)
{
    std::cout << "\n\n\n";
    std::cout << "설정된 날짜는 " << mYear << "년" << mMonth << "월" << mDay << "일입니다.\n";
    std::cout << "새로운 날짜는 " << year << "년" << month << "월" << day << "일입니다.\n";
}

void Calendar::DisplayError(int error)
{
    std::cout << "\n\n\n";

    if (error == 1)
    {
        std::cout << "년도는 1800년 이상을 입력해 주세요.\n";
    }
}
