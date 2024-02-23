#include "calendar.h"

int main()
{
    Calendar cal(2024, 2, 23);

    cal.AddYear(3);
    cal.AddMonth(3);
    cal.AddDay(10);
    cal.AddDay(1000);

    cal.DisplayMonth(2024, 10);

    cal.DisplayMonth(2024, 4);

    return 0;
}