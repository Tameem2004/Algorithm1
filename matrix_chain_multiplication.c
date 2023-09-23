#include <stdio.h>
#include <limits.h>

void matrix(int d[], int num) {
    int i, j, l, k, q;
    int m[num][num]; // Matrix to store minimum multiplications
    int s[num][num]; // Matrix to store the optimal split points

    // Initialize m and s matrices
    for (i = 1; i < num; i++) {
        m[i][i] = 0;
    }

    // Calculate minimum multiplications & optimal split points
    for (l = 2; l < num; l++) {
        for (i = 1; i < num - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    //print minimum scelar multiplications
    for (i = 1; i < num; i++) {
        for (j = 1; j < num; j++) {
            printf("M%d%d (value=%d) ", i, j, m[i][j]);
        }
        printf("\n");
    }
    // Print optimal split points and k values
    printf("Optimal Split Points:\n");
    for (i = 1; i < num; i++) {
        for (j = 1; j < num; j++) {
            printf("M%d%d (k=%d) ", i, j, s[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num,d[100],i;
    printf("Enter the size of Array:\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Eneter %d Element",i);
        scanf("%d",&d[i]);
    }
    printf("Number of matrices: %d\n", num - 1); // Subtract 1 to get the number of matrices
    matrix(d, num);
    return 0;
}
