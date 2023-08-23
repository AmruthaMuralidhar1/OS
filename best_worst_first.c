#include <stdio.h>

#define max 25

void firstFit(int b[], int p[], int nb, int nf) {
    int i, j;
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, p[i], j + 1, b[j], b[j] - p[i]);
                b[j] -= p[i];
                break;
            }
        }
        if (j == nb) {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t-\t\t-", i + 1, p[i]);
        }
    }
}

void bestFit(int b[], int p[], int nb, int nf) {
    int i, j, idx;
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 0; i < nf; i++) {
        idx = -1;
        for (j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                if (idx == -1 || b[j] < b[idx]) {
                    idx = j;
                }
            }
        }
        if (idx != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, p[i], idx + 1, b[idx], b[idx] - p[i]);
            b[idx] -= p[i];
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t-\t\t-", i + 1, p[i]);
        }
    }
}

void worstFit(int b[], int p[], int nb, int nf) {
    int i, j, idx;
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 0; i < nf; i++) {
        idx = -1;
        for (j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                if (idx == -1 || b[j] > b[idx]) {
                    idx = j;
                }
            }
        }
        if (idx != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, p[i], idx + 1, b[idx], b[idx] - p[i]);
            b[idx] -= p[i];
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t-\t\t-", i + 1, p[i]);
        }
    }
}

int main() {
    int frag[max], b[max], p[max];
    int nb, nf, i, j, ch;

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("Enter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    do {
        printf("\nMemory Allocation Techniques:\n");
        printf("1. First Fit\n");
        printf("2. Best Fit\n");
        printf("3. Worst Fit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                firstFit(b, p, nb, nf);
                break;
            case 2:
                bestFit(b, p, nb, nf);
                break;
            case 3:
                worstFit(b, p, nb, nf);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (ch != 4);

    return 0;
}
