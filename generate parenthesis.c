#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **res, int *returnSize, char *current, int pos, int open, int close, int n) {
    // Base case: if we've used all parentheses
    if (pos == 2 * n) {
        current[pos] = '\0';  // Null-terminate the string
        res[*returnSize] = strdup(current); // Duplicate the string
        (*returnSize)++;
        return;
    }

    // Add '(' if we still have some left
    if (open < n) {
        current[pos] = '(';
        backtrack(res, returnSize, current, pos + 1, open + 1, close, n);
    }

    // Add ')' if it's valid to close one
    if (close < open) {
        current[pos] = ')';
        backtrack(res, returnSize, current, pos + 1, open, close + 1, n);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    int maxCombinations = 1 << (2 * n); // upper bound (not exact but safe)
    char **res = malloc(maxCombinations * sizeof(char *));
    char *current = malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;

    backtrack(res, returnSize, current, 0, 0, 0, n);

    free(current);
    return res;
}
