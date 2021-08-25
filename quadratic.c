/*!
	\brief  Quadratic equation solver.
	\author Katik
	\version 1.0
	\date 25.08.2021

	This program can solve any of your quadratic equations.
*/

#include <stdio.h>
#include <math.h>

enum answertags {  /// Constants for different numbers of quadratic equation solutions
     NO_SOL,    ///< For the case, when equation has no solutions
    NONQUAD,    ///< For the case, when equation has only one solution and the coefficien behind x^2 is zero
    ONE_SOL,    ///< For the case, when equation has one solution
    TWO_SOL,    ///< For the case, when equation has two solutions
    INFINITY_SOL    ///< For the case when equation has an infinite number of solutions
};


/*!
Displays the explanatory notes and scans the coefficients
\param a,b,c coeffitients of a quadartic equation
*/
int scan_variables (double* a, double* b, double* c);


/*!
Checks if a variable is zero
\param x gets the variable
\return true or false for comparison with zero
*/
bool is_zero (double x);


/*!
Prints answer(s) for all cases or says about mistakes
\param answer shows the amount of solutions
\param xprint1, xprint2 get variable assignments
*/
void print_answer (answertags answer, double* xprint1, double* xprint2);

/*!
Gets the coefficients assignments and solves the equation for all cases
\param coefa,coefb,coefc coeffitients of a quadartic equation
\param x1, x2 get solutions
\return answer different constants for different cases
*/
enum answertags solve_equation (double coefa, double coefb, double coefc, double* x1, double* x2);

/*!
Calls other functions and warns about errors
*/
int main ()
{
    double a = 0.5, b = 0.5, c = 0.5, x1 = 0, x2 = 0;   ///< a, b, c first, second and third coefficients of the quadratic equation respectively

    int error = scan_variables (&a, &b, &c);                  ///< callin the function to enter the coefficients values
    if (error == 1)                                           ///< checking the mistakes
    {
        printf ("You have entered wrong symbols.\n");         ///<warning for wrong symbol entered
        return 0;
    }

    enum answertags ret = solve_equation (a, b, c, &x1, &x2);  ///< callingthe function to give the coefficients values and get the answer(s)
    print_answer (ret, &x1, &x2);                              ///< callin the function to print the answer(s) or warnings

    return 0;
}

int scan_variables (double* a, double* b, double* c)
{
    ///< explanatory notes
    printf ("This program can solve any of your quadratic equations!\n");
    printf ("The equation has the form: a*x^2+b*x+c=0.\n");
    printf ("Please enter the values of your coefficients.\n");
    printf ("(If any of them is zero or negative, enter 0 or the minus sign before the number).\n\n");

    printf ("Enter coefficients a, b, c: \n");

    ///< wrong entered errors check
    if (3 != scanf ("%lg %lg %lg", a, b, c))
    {
        return 1;
    }

    return 0;
}

bool is_zero (double x)
{
    const double epsilon = 1e-5;  ///< the constant close to zero
    return fabs(x) < epsilon;
}

enum answertags solve_equation (double coefa, double coefb, double coefc, double* x1, double* x2)
{
    double D = 0;     ///< the variable for Discriminant values

    if (is_zero(coefa) && is_zero(coefb) && is_zero(coefc))  ///< checking if the equation has an infinite number of solutions
    {
        return INFINITY_SOL;
    }

    if (is_zero(coefa) && is_zero(coefb))                    ///< checking if the equation has no solutions due to x absence
    {
        return NO_SOL;
    }
                                                             ///< checking if the first coefficient is zero so the equation has onesolution
    if (is_zero(coefa))
    {
        *x1 = (-(coefc))/(coefb);
        return NONQUAD;
    }

    D = pow (coefb,2) - 4.0*(coefa)*(coefc);                 ///< Discriminant formula

    if (D < 0)                                               ///< checking if the equation has no solutions due to negative Discriminant
    {
        return NO_SOL;
    }

    if (is_zero(D))                                          ///< checking if the equation has no solutions due to Discriminant is zero
    {
        *x1 = (-(coefb))/(2.0*(coefa));
        return ONE_SOL;
    }

    *x1 = ((-1.0)*(coefb) + sqrt((double)D))/(2.0*(coefa));   ///< formulas for two solutions
    *x2 = ((-1.0)*(coefb) - sqrt((double)D))/(2.0*(coefa));
    return TWO_SOL;
}

void print_answer (enum answertags answer, double* xprint1, double* xprint2)
{
    ///< printing for every case of solutions
    switch (answer)
    {
        case NONQUAD:
            printf ("Your equation has only one solution: x = %lf\n", *xprint1);
            break;

        case NO_SOL:
            printf ("Your quadratic equation has no solutions.\n");
            break;

        case ONE_SOL:
            printf ("Your quadratic equation has one solution: x = %.2lf\n", *xprint1);
            break;

        case TWO_SOL:
            printf ("Your quadratic equation has two solutions:\nx1 = %.2lf\nx2 = %.2lf\n",
                *xprint1, *xprint2);
            break;

        case INFINITY_SOL:
            printf ("Your quadratic equation has an infinite number of roots.\n");
            break;

        default:
            printf ("Unexpected error");    ///< warning about an unexpected error
    }
}
