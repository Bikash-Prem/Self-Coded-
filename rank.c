#include <stdio.h>
int m,n;
float a[10][10], Augmented[10][10], solution[10];
int rankA = 0, rankAug =0;

void gauss_elimination();
void rank();
void back_substitution();

int main(){
    int i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    printf("Enter the coeffients of equation: \n");
    for (i = 0; i < m; i++){
        for (j=0; j<n; j++){
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        Augmented[i][j] = a[i][j];
    }

    printf("Enter the constants: ");
    for (i = 0; i < m; i++)
    {
        scanf("%f", & Augmented[i][n]);
    }
    gauss_elimination();
    rank();
    if (rankA == rankAug)
    {
        if (rankA == m)
        {
            printf("The system has a unique solution.\n");
            back_substitution();
        }
        else if (rankA < m)
        {
            printf("The system has infinite number of solution.");
        }
    }

    else
    {
        printf("The system has no solution.");
    }

    return 0;
}

void gauss_elimination()
{
    int i, j, k;
    float factor, temp;
    for (i = 0; i < m; i++)
    {
        if (a[i][i] == 0)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[j][i] != 0)
                {
                    for (k = 0; k < n; k++)
                    {
                        temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }
                    for (k = 0; k <= n; k++)
                    {
                        temp = Augmented[i][k];
                        Augmented[i][k] = Augmented[j][k];
                        Augmented[j][k] = temp;
                    }
                    break;
                }
            }
        }
        if (a[i][i] != 0)
        {
            for (j = i + 1; j < m; j++)
            {
                factor = a[j][i] / a[i][i];
                for (k = i; k < n; k++)
                {
                    a[j][k] -= factor * a[i][k];
                }
                for (k = i; k <= n; k++)
                {
                    Augmented[j][k] -= factor * Augmented[i][k];
                }
            }
        }
    }
}

void rank(){
    int i, j, k, zero;
    for (i = 0; i < m; i++)
    {
        zero = 1;
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                zero = 0;
            }
        }
        if (!zero)
            rankA++;
    }

    for (i = 0; i < m; i++)
    {
        zero = 1;
        for (j = 0; j <= n; j++)
        {
            if (Augmented[i][j] != 0)
            {
                zero = 0;
            }
        }
        if (!zero)
            rankAug++;
    }
}

void back_substitution(){
    int i, j;
    for(i=m-1; i>=0; i--){
        solution[i] = Augmented[i][n];
        for (j = i + 1; j < m; j++)
        {
            solution[i] -= Augmented[i][j] * solution[j]; // Subtract the known values
        }
        solution[i] /= Augmented[i][i];
    }
    for (i = 0; i < m; i++)
    {
        printf("x%d = %.2f\n", i+1, solution[i]);
    }
    
}