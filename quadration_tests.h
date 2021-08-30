#include <stdio.h>
#include <math.h>

enum {N_TESTS = 7};

void TEST_Solve_linear_equations ();
void TEST_Solve_quad_equations ();
bool is_equal (double x, double y);
int TEST ();


int TEST ()
{
    TEST_Solve_quad_equations ();
    TEST_Solve_linear_equations ();

    return 0;
}


void TEST_Solve_linear_equations ()
{
             /// test number:    0   1      2        3        4    5  6
    double coefb    [N_TESTS] = {1,  2,     6,      6.2,     6452, 0, 0};
    double coefc    [N_TESTS] = {0,  1,     8,     -5.64,  988754, 4, 0};
    double x_ans    [N_TESTS] = {0, -0.50, -1.333, 0.909, -153.25, 0, 0};
    int sate_ans    [N_TESTS] = {1,  1,     1,       1,       1,   0, 4};

    double x = 0;

    for (int i = 0; i <= N_TESTS - 1; i++)
    {
        enum answertags state = solve_linear_equations(coefb[i], coefc[i], &x);

        if (! state == sate_ans[i])
        {
            printf ("State error test %d\n", i);
        }

        if (! is_equal (x, x_ans[i]))
        {
            printf ("Error test %d Lin_solver.\n", i);
            printf ("x = %lf, b = %lf, c = %lf\n",
                     x, coefb[i], coefc[i]);
            printf ("Should be: x = %lf\n\n", x_ans[i]);
        }
        else
            printf ("Test %d OK!\n\n", i);
        }
    }


void TEST_Solve_quad_equations ()
{
        /// test number:    0     1        2      3         4     5      6
    double coefa     [N_TESTS] = {8,    8,      2.9,   -58,       4,    8,   -125};
    double coefb     [N_TESTS] = {0,    0,     -6.8,   185,      -4,   -3,   0.65};
    double coefc     [N_TESTS] = {0,   -6,      -6,    -54,       1,    9,      9};
    double x1_ans    [N_TESTS] = {0,  0.866,   3.029,  0.323,    0.50,  0, -0.266};
    double x2_ans    [N_TESTS] = {0, -0.866,  -0.684,  2.864,     0,    0,  0.271};
    int state_ans    [N_TESTS] = {2,    3,       3,     3,        2,    0,      3};

    double x1 = 0, x2 = 0;

    for (int k = 0; k <= N_TESTS - 1; k++)
    {
        enum answertags state = solve_quad_equation (coefa[k], coefb[k], coefc[k], &x1, &x2);

        if (! state == state_ans[k])
        {
            printf ("State error test %d\n", k);
        }

        if (! is_equal (x1, x1_ans[k]) || ! is_equal (x2, x2_ans[k]))
        {
            printf ("Error test %d Quad_solver.\n", k);
            printf ("x1 = %lf, x2 = %lf, a = %lf, b = %lf, c = %lf\n",
                     x1, x2, coefa[k], coefb[k], coefc[k]);
            printf ("Should be: x1 = %lf\nx2 = %lf\n\n", x1_ans[k], x2_ans[k]);
        }
        else
        {
            printf ("Test %d OK!.\n\n", k);
    }   }
}


bool is_equal (double x, double y)
{
    return is_zero (y - x);
}
