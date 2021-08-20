#include "stdio.h"
#include "cmath"

 main ()
{
    float a, b, c, D, x1, x2, x0;

    //разъ€сн€ющие слова дл€ юзера

    printf ("This program can solve any of your quadratic equations!\n");
    printf ("The equation has the form: a*x^2+b*x+c=0.\n");
    printf ("Please enter the values of your coefficients.\n");
    printf ("(If any of them is zero or negative, enter 0 or the minus sign before the number).\n");
    printf ("a=");
    scanf ("%f", &a);
    printf ("b=");
    scanf ("%f", &b);
    printf ("c=");
    scanf ("%f", &c);

    if (a == 0)     //проверка на зануление коэффициента при х^2
    {
        x0 = (-1.0)*c/b;
        printf ("Your equation has one solution: x= %1.2f\n", x0);
    }

    else
    {
        D = b*b - 4.0*a*c;       //вычисление дискриминанта

        //сравнение D с нулЄм
        if (D < 0)
        {
            printf ("Your quadratic equation has no solutions.\n");
        }

        else if (D == 0)
        {
            x0 = (-b)/(2.0*a);
            printf ("Your quadratic equation has one solution: x= %1.2f\n", x0);
        }

        else
        {
            x1 = (-b + sqrt((double)D))/(2.0*a);
            x2 = (-b - sqrt((double)D))/(2.0*a);

            printf ("Your quadratic equation has two solutions:\nx1= %1.2f\n", x1);
            printf ("x2= %1.2f\n", x2);
        }
    return 0;
    }
}

