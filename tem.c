#include <stdio.h>

void transpose2(float b[2][2]);
void transpose3(float b[3][3]);
int two_p();
int three_p();

int main() {
    printf("Enter the order of matrices: ");
    int n = 0;
    scanf("%d", &n);
    switch (n) {
        case 2:
            two_p();
            break;
        case 3:
            three_p();
            break;
        default:
            printf("In future, when I'll be smart enough, Maybe....");
            break;
    }
    return 0;
}

void transpose2(float b[2][2]) {
    float temp;
    temp = b[0][1];
    b[0][1] = b[1][0];
    b[1][0] = temp;
}

void transpose3(float b[3][3]) {
    float temp;
    temp = b[0][1];
    b[0][1] = b[1][0];
    b[1][0] = temp;

    temp = b[0][2];
    b[0][2] = b[2][0];
    b[2][0] = temp;

    temp = b[1][2];
    b[1][2] = b[2][1];
    b[2][1] = temp;
}

int two_p() {
    float a[2][2], b[2][2], pro[2][2];
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%f", &b[i][j]);
        }
    }
    transpose2(b);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            float r = 0;
            for (int k = 0; k < 2; k++) {
                r += a[i][k] * b[j][k];
            }
            pro[i][j] = r;
        }
    }
    printf("The product of the two given matrices is:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", pro[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int three_p() {
    float a[3][3], b[3][3], pro[3][3];
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &b[i][j]);
        }
    }
    transpose3(b);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float r = 0;
            for (int k = 0; k < 3; k++) {
                r += a[i][k] * b[j][k];
            }
            pro[i][j] = r;
        }
    }
    printf("The product of the two given matrices is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", pro[i][j]);
        }
        printf("\n");
    }
    return 0;
}