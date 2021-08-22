#include "stdio.h"
#include "math.h"

#define NONQUAD 1;
#define NO_SOL 2;
#define ONE_SOL 3;
#define TWO_SOL 4;
#define EXTRA 5;

int scan_variables (double a, double b, double c);
int solve_equation (double * coefa, double * coefb, double * coefc);
int print_answer (int * answerprint, double * xprint);

int main ()
{

    double a, b, c;
    a = 0;
    b = 0;
    c = 0;

    scan_variables (a, b, c);

    return 0;
}

int scan_variables (double a, double b, double c)
{

    printf ("This program can solve any of your quadratic equations!\n");
    printf ("The equation has the form: a*x^2+b*x+c=0.\n");
    printf ("Please enter the values of your coefficients.\n");
    printf ("(If any of them is zero or negative, enter 0 or the minus sign before the number).\n");
    printf ("a=");
    scanf ("%lf", &a);
    printf ("b=");
    scanf ("%lf", &b);
    printf ("c=");
    scanf ("%lf", &c);

    solve_equation (&a, &b, &c);

    return 0;
}

int solve_equation (double * coefa, double * coefb, double * coefc)
{
    double D;
    D = 0;
    int answer = 0;

    double epsilon = 0.00001;

    if (fabs (*coefa) < epsilon)
    {
        double x0 = 0;
        x0 = (-1.0)*(*coefc)/(*coefb);
        answer = NONQUAD;
        print_answer (&answer, &x0);
    }

    else
    {
        D = pow (*coefb,2) - 4.0*(*coefa)*(*coefc);

        if (D < 0)
        {
            answer = NO_SOL;
            double nosol = 0.0;
            print_answer (&answer, &nosol);
        }

        else if (fabs (D) < epsilon)
        {
            double x = 0;
            x = (-(*coefb))/(2.0*(*coefa));
            answer = ONE_SOL;
            print_answer (&answer, &x);
        }

        else
        {
            double x1 = 0, x2 = 0;
            x1 = ((-1.0)*(*coefb) + sqrt((double)D))/(2.0*(*coefa));
            x2 = ((-1.0)*(*coefb) - sqrt((double)D))/(2.0*(*coefa));

            answer = TWO_SOL;
            print_answer (&answer, &x1);
            answer = EXTRA;
            print_answer (&answer, &x2);
        }

        return 0;
    }
}

int print_answer (int * answerprint, double * xprint)
{

    if (*answerprint == 1)
    {
        printf ("Your equation has only one solution: x= %1.2lf\n", *xprint);
    }

    if (*answerprint == 2)
    {
        printf ("Your quadratic equation has no solutions.\n");
    }

    if (*answerprint == 3)
    {
        printf ("Your quadratic equation has one solution: x= %1.2lf\n", *xprint);
    }

    if (*answerprint == 4)
    {
        printf ("Your quadratic equation has two solutions:\nx1= %1.2lf\n", *xprint);
    }

    if (*answerprint == 5)
    {
        printf ("x2= %1.2lf\n", *xprint);
    }

    return 0;
}
