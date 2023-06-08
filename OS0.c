#include<stdio.h>
#include<conio.h>
void matrixAdd(int **matA, int **matB, int **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            *(*(result + i) + j) = *(*(matA + i) + j) + *(*(matB + i) + j);
        }
    }
}

void matrixMultiply(int **matA, int **matB, int **result, int rowsA, int colsA, int colsB) {
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            *(*(result + i) + j) = 0;
            for(int k = 0; k < colsA; k++) {
                *(*(result + i) + j) += *(*(matA + i) + k) * *(*(matB + k) + j);
            }
        }
    }
}

int isSymmetric(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(*(*(matrix + i) + j) != *(*(matrix + j) + i)) {
                return 0;
            }
        }
    }
    return 1;
}

void transposeMatrix(int **matrix, int **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            *(*(result + j) + i) = *(*(matrix + i) + j);
        }
    }
}

void displayMatrix(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);
    
    int **matA = (int**) malloc(rows * sizeof(int*));
    int **matB = (int**) malloc(rows * sizeof(int*));
    int **result = (int**) malloc(rows * sizeof(int*));
    int **transpose = (int**) malloc(cols * sizeof(int*));
    
    for(int i = 0; i < rows; i++) {
        matA[i] = (int*) malloc(cols * sizeof(int));
        matB[i] = (int*) malloc(cols * sizeof(int));
        result[i] = (int*) malloc(cols * sizeof(int));
        transpose[i] = (int*) malloc(rows * sizeof(int));
    }
    
    printf("Enter the elements of matrix A:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", (*(matA + i) + j));
        }
    }
    
    printf("Enter the elements of matrix B:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", (*(matB + i) + j));
        }
    }
    
    printf("Matrix A:\n");
    displayMatrix(matA, rows, cols);
    
    printf("Matrix B:\n");
    displayMatrix(matB, rows, cols);
    
    matrixAdd(matA, matB, result, rows, cols);
    
    printf("Matrix A + B:\n");
    displayMatrix(result, rows, cols);
    
    matrixMultiply(matA, matB, result, rows, cols, cols);
    
    printf("Matrix A * B:\n");
    displayMatrix(result, rows, cols);
    
    int isSymmetricA = isSymmetric(matA, rows, cols);
    int isSymmetricB = isSymmetric(matB, rows, cols);
    
    printf("Matrix A is%s symmetric.\n", (isSymmetricA ? "" : " not"));
    printf("Matrix B is%s symmetric.\n", (isSymmetricB ? "" : " not"));
    
    transposeMatrix(matA, transpose, rows, cols);
    
    printf("Transpose of matrix A:\n");
    displayMatrix(transpose, cols, rows);

    return 0;
}
