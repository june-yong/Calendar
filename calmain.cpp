#include "calendar.h"

int main()
{
    Calendar cal(2024, 2, 23);

    cal.AddYear(3);
    cal.AddMonth(3);
    cal.AddDay(10);

    return 0;
}