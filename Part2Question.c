/* Question: Keep negative values
 * Keep only strictly negative elements, in input order.
 * See booklet for the common contract and line-count rule.
 */
#include <stdio.h>
#include <stdlib.h>

int solve(const int *a, int n, int *out)
{
}

int main(void)
{
    int inputs[5][20] = {
        {0},
        {7},
        {-3, 0, 2, -2, 5},
        {4, 4, 1, 0, 1, 4},
        {6, -1, 3, 3, 0, -4, 2, 8}
    };
    int lengths[5] = {0, 1, 5, 6, 8};
    int expected[5][20] = {
        {0},
        {0},
        {-3, -2},
        {0},
        {-1, -4}
    };
    int expected_lengths[5] = {0, 0, 2, 0, 2};
    int work[20], guarded[22];
    int k, i, got, ok, passed;
    passed = 0;
    for (k = 0; k < 5; ++k) {
        for (i = 0; i < 20; ++i) work[i] = inputs[k][i];
        for (i = 0; i < 22; ++i) guarded[i] = 12345;
        got = solve(work, lengths[k], guarded + 1);
        ok = got == expected_lengths[k];
        if (got < 0 || got > lengths[k]) ok = 0;
        if (ok) {
            for (i = 0; i < got; ++i)
                if (guarded[i + 1] != expected[k][i]) ok = 0;
        }
        for (i = 0; i < 20; ++i)
            if (work[i] != inputs[k][i]) ok = 0;
        if (guarded[0] != 12345 || guarded[lengths[k] + 1] != 12345) ok = 0;
        if (ok) ++passed;
        printf("Test %d: %s\n", k + 1, ok ? "PASS" : "FAIL");
    }
    printf("Passed %d/5 test cases\n", passed);
    return passed == 5 ? 0 : 1;
}
