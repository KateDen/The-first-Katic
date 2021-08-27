/*!
	\brief  Quadratic equation solver.
	\author Kate_Den
	\version 1.0
	\date 25.08.2021

	This program can solve any of your quadratic equations of the form ax^2 + bx + c = 0.
*/


#include <stdio.h>
#include <math.h>
#include <assert.h>
//#include "C:\projects\quadration_tests.c"

/// Constants for different state of equation solutions
enum answertags
    {
     NO_SOL,          ///< no solutions
     ONE_SOL_NONQUAD, ///< only one solution of a non quadration eqiation
     ONE_SOL,         ///< one solution
     TWO_SOL,         ///< two solutions
     INFINITY_SOL     ///< an infinite number of solutions
    };


/*!
Displays the explanatory notes and scans the coefficients
\param [in] a, b, c coeffitients of a quadartic equation
*/
int scan_variables (double* a, double* b, double* c);


/*!
Checks if a double variable is zero
\param [in] x gets the variable
\return true or false for comparison with zero
*/
bool is_zero (double x);


/*!
Prints answer(s) for all cases
\param [in] answer shows the state of solution
\param [in] xprint1, xprint2 get variable assignments
*/
void print_answer (answertags answer, double xprint1, double xprint2);

/*!
Solves the linear equation and checks coefficients b and c
\param [in] coefb, coefc gets the coefficients' values
\param [out] x gets the solution
\return
*/
answertags solve_linear_equations (double coefb, double coefc, double* x);


/*!
Gets the coefficients' values and solves the equation for all cases
\param [in] coefa, coefb, coefc coefficients of a quadartic equation
\param [out] x1, x2 get solutions
\return answer different constants for different cases
*/
answertags solve_quad_equation (double coefa, double coefb, double coefc, double* x1, double* x2);

#include "quadration_tests.h"
/*!
Displays the solver
*/
int main ()
{
    TEST ();

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;   /// a, b, c first, second and third coefficients of the quadratic equation respectively

    int error = scan_variables (&a, &b, &c);
    if (error == 1)
    {
        printf ("You have entered wrong symbols.\n");
        return 0;
    }

    answertags ret = solve_quad_equation (a, b, c, &x1, &x2);  /// ret gets returned values
    print_answer (ret, x1, x2);

    return 0;
}

int scan_variables (double* a, double* b, double* c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    assert (isfinite(*a));
    assert (isfinite(*b));
    assert (isfinite(*c));

    printf ("This program can solve any of your quadratic equations!\n");
    printf ("The equation has the form: a*x^2+b*x+c=0.\n");
    printf ("Please enter the values of your coefficients.\n\n");

    printf ("Enter coefficients a, b, c: \n");

    if (3 != scanf ("%lg %lg %lg", a, b, c))
    {
        return 1;
    }

    return 0;
}

bool is_zero (double x)
{
    const double epsilon = 1e-2;
    return fabs(x) < epsilon;
}

answertags solve_quad_equation (double coefa, double coefb, double coefc, double* x1, double* x2)
{
    assert (x1);
    assert (x2);
    assert (isfinite(coefa));
    assert (isfinite(coefb));
    assert (isfinite(coefc));

    if (is_zero (coefa))
    {
        return solve_linear_equations (coefb, coefc, x1);
    }

    double D = pow (coefb,2) - 4.0*(coefa)*(coefc);                 /// Discriminant formula

    if (D < 0)
    {
        *x1 = 0;
        *x2 = 0;
        return NO_SOL;
    }

    if (is_zero(D))
    {
        *x1 = (-(coefb)) / (2.0*(coefa));
        *x2 = 0;
        return ONE_SOL;
    }

    *x1 = ((-1.0)*(coefb) + sqrt((double)D)) / (2.0*(coefa));   /// formulas for two solutions
    *x2 = ((-1.0)*(coefb) - sqrt((double)D)) / (2.0*(coefa));
    return TWO_SOL;
}

answertags solve_linear_equations (double coefb, double coefc, double* x)
{
    assert (isfinite(coefb));
    assert (isfinite(coefc));

    if (is_zero(coefb) && is_zero(coefc))
    {
        return INFINITY_SOL;
    }

    if (is_zero(coefb))
    {
        *x = 0;
        return NO_SOL;
    }

    *x = (-(coefc))/(coefb);
    return ONE_SOL_NONQUAD;
}

void print_answer (answertags answer, double xprint1, double xprint2)
{
    assert (isfinite(xprint1));
    assert (isfinite(xprint1));

    switch (answer)
    {
        case ONE_SOL_NONQUAD:
            printf ("Your equation has only one solution: x = %.2lf\n", xprint1);
            break;

        case NO_SOL:
            printf ("Your quadratic equation has no solutions.\n");
            break;

        case ONE_SOL:
            printf ("Your quadratic equation has one solution: x = %.2lf\n", xprint1);
            break;

        case TWO_SOL:
            printf ("Your quadratic equation has two solutions:\nx1 = %.2lf\nx2 = %.2lf\n",
                    xprint1, xprint2);
            break;

        case INFINITY_SOL:
            printf ("Your quadratic equation has an infinite number of roots.\n");
            break;

        default:
            printf ("Unexpected error");
    }
}
