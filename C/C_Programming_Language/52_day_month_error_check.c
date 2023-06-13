static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day) {
  int i, leap;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (month < 1 || month > 12) {
    printf("error: month must be between 1 and 12\n");
    return -1;
  }
  if (day < 1 || day > daytab[leap][month]) {
    printf("error: day must be between 1 and %d\n", daytab[leap][month]);
    return -1;
  }
  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (yearday < 1 || yearday > (leap ? 366 : 365)) {
    printf("error: yearday must be between 1 and %d\n", leap ? 366 : 365);
    return;
  }
  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}