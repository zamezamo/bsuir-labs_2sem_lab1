/*
* 19/02/21
* Artyom Zamoyskiy
*
* Task:
* RU: 2. Структура содержит информацию о сотрудниках фирмы: шифр отдела (число), фамилию (указатель),
*     вложенную структуру – дату приёма на работу (строка фиксированной длины) и сумму оклада. 
*     Найти сотрудников с заданной фамилией. Удалить сотрудников с окладом ниже заданного.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct salary
{
    char date[10];
    int sum_salary;
};

struct employees
{
    int code;
    char *surname;
    struct salary empl;
};

//фунция ввода всех полей структуры
void input(struct employees *emp, int f)
{
    for (int i = 0; i < f; i++)
    {
        //запрос на ввод шифра
        printf("Enter a code of %d employee - ", i + 1);

        //проверка на ввод и ввод шифра
        while (1)
        {
            scanf("%d", &emp[i].code);
            fflush(stdin);
            if (emp[i].code > 9999 || emp[i].code < 0)
                printf("Enter only 4 digits! - ");
            else
                break;
        }

        //запрос на ввод фамилии
        printf("Enter a surname of %d employee - ", i + 1);
        emp[i].surname = (char *)malloc(20 * sizeof(char));

        //проверка на ввод и ввод фамилии
        while (1)
        {
            scanf("%s", emp[i].surname);
            fflush(stdin);
            if (emp[i].surname[0] > 'Z' || emp[i].surname[0] < 'A')
            {
                printf("Wrong text! Start with a capital English letter - ");
            }
            else
                break;
        }

        //заполнение дат принятия на работу и сумм оклада
        switch (i)
        {
        case 0:
        {
            strcpy(emp[0].empl.date, "12.08.2020");
            emp[0].empl.sum_salary = 2600;
            break;
        }
        case 1:
        {
            strcpy(emp[1].empl.date, "19.04.2020");
            emp[1].empl.sum_salary = 3000;
            break;
        }
        case 2:
        {
            emp[2].empl.sum_salary = 2400;
            strcpy(emp[2].empl.date, "14.03.2020");
            break;
        }
        case 3:
        {
            emp[3].empl.sum_salary = 2100;
            strcpy(emp[3].empl.date, "01.02.2021");
            break;
        }
        case 4:
        {
            emp[4].empl.sum_salary = 2500;
            strcpy(emp[4].empl.date, "09.08.2020");
            break;
        }
        case 5:
        {
            emp[5].empl.sum_salary = 1900;
            strcpy(emp[5].empl.date, "12.05.2020");
            break;
        }
        case 6:
        {
            emp[6].empl.sum_salary = 1700;
            strcpy(emp[6].empl.date, "23.09.2020");
            break;
        }
        case 7:
        {
            emp[7].empl.sum_salary = 1400;
            strcpy(emp[7].empl.date, "31.03.2020");
            break;
        }
        case 8:
        {
            emp[8].empl.sum_salary = 1500;
            strcpy(emp[8].empl.date, "21.04.2020");
            break;
        }
        }
    }
}

//функция вывода первых двух полей структуры
void output(struct employees *emp, int c)
{
    int i = 0;
    while (i < c)
    {
        printf("Code of %d employee - %d\n", i + 1, emp[i].code);
        printf("Surname of %d employee - %s\n", i + 1, emp[i].surname);
        i++;
    }
}

//функция поиска по фамилии
void search(struct employees *emp, int f)
{
    char tsurname[20];
    printf("Enter a surname of employee which you want to find - ");
    while (1)
    {
        scanf("%s", tsurname);
        fflush(stdin);
        if (tsurname[0] > 'Z' || tsurname[0] < 'A')
        {
            printf("Wrong text! Start with a capital English letter - ");
        }
        else
            break;
    }
    int tmp = 0;
    for (int i = 0; i < f; i++)
    {
        if (strcmp(tsurname, emp[i].surname) == 0)
        {
            printf("Found!\n%d %s %s %d\n", emp[i].code, emp[i].surname, emp[i].empl.date, emp[i].empl.sum_salary);
            tmp++;
        }
    }
    if (tmp == 0)
        printf("Not found!");
}

//функция удаления сотрудника с окладом, ниже заданного
void delete (struct employees *emp, int f)
{
    int salary;
    printf("Enter a sum of salary to delete sum of salaries, which are smaller - ");
    while (1)
    {
        scanf("%d", &salary);
        fflush(stdin);
        if (salary > 5000 || salary < 0)
        {
            printf("Wrong number! 0<..<5000 - ");
        }
        else
            break;
    }
    int p = 0;
    while (p < f)
    {
        if (emp[p].empl.sum_salary < salary)
        {
            for (int k = p; k < f - 1; k++)
            {
                emp[k].empl.sum_salary = emp[k + 1].empl.sum_salary;
                emp[k].surname = emp[k + 1].surname;
                emp[k].code = emp[k + 1].code;
                strcpy(emp[k].empl.date, emp[k + 1].empl.date);
            }
            f--;
        }
        else
            p++;
    }
    for (int i = 0; i < f; i++)
        printf("%s %d\n", emp[i].surname, emp[i].empl.sum_salary);
}

int main()
{
    int n;

    //запрос на ввод кол-ва сотрудников
    printf("Enter number of employees - ");
    while (1)
    {
        scanf("%d", &n);
        fflush(stdin);
        if (n < 1 || n > 9)
        {
            printf("Enter only a number less than 9! - ");
        }
        else
            break;
    }
    struct employees *emp = (struct employees *)malloc(n * sizeof(struct employees));
    input(emp, n);
    fflush(stdin);
    output(emp, n);
    int operation;
    do
    {
        printf("What you want to do?\nEnter 1 to found surname of employee\n");
        printf("Enter 2 to delete employer with smaller sum of salary than the specified\nEnter 3 to exit\nEnter number: ");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            search(emp, n);
            break;
        }
        case 2:
        {
            delete (emp, n);
            break;
        }
        case 3:
        {
            free(emp);
            return 0;
        }
        default:
        {
            free(emp);
            return 0;
        }
        }
    } while (1);
}