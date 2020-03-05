// Ugur Gudelek
// ugurgudelek@gmail.com

/*
 * Reversed Triangle (n=5)
 * *********        row:0, 0space-9star-0space
 *  *******         row:1, 1space-7star-1space
 *   *****          row:2, 2space-5star-2space
 *    ***           row:3, 3space-3star-3space
 *     *            row:4, 4space-1star-4space
 *
 *
 * Diamond (n=5)
 *     *            row:0, 4space       -1star      -4space
 *    * *           row:1, 3space-1star-1space-1star-3space
 *   *   *          row:2, 2space-1star-3space-1star-3space
 *  *     *         row:3, 1space-1star-5space-1star-3space
 * *********        row:4, 0space       -9star      -0space
 *  *     *         row:5, 1space-1star-5space-1star-3space
 *   *   *          row:6, 2space-1star-3space-1star-3space
 *    * *           row:7, 3space-1star-1space-1star-3space
 *     *            row:8, 4space       -1star      -4space
 * */



#include <stdio.h>


void reversed_triangle_row(int, int);
void reversed_triangle_loop(int);
void reversed_triangle_recursive(int, int);

void diamond_row(int, int);
void diamond_loop(int);
void diamond_recursive(int, int);

int main() {

    int n = 5;
    printf("\n=====Reversed Triangle Loop (n=5)=====\n");
    reversed_triangle_loop(n);
    printf("\n=====Reversed Triangle Recursive (n=5)=====\n");
    reversed_triangle_recursive(0, n);
    printf("\n=====Diamond Loop (n=5)=====\n");
    diamond_loop(n);
    printf("\n=====Diamond Recursive (n=5)=====\n");
    diamond_recursive(0, n);
    return 0;
}

void reversed_triangle_row(int i, int n){
    int space_cnt = i;      // left and right space count wrt i
    int star_cnt = 2 * (n - i) - 1; // middle start count wrt i
    for (int j = 0; j < space_cnt; j++) printf(" ");  //print left hand side spaces
    for (int j = 0; j < star_cnt; j++) printf("*");   //print middle stars
    for (int j = 0; j < space_cnt; j++) printf(" ");  //print right hand side spaces
    printf("\n");
}
void reversed_triangle_loop(int n) {
    for (int i = 0; i < n; i++) { // iterate over rows
        reversed_triangle_row(i, n);
    }
}
void reversed_triangle_recursive(int i, int n) {
    if (i == n) return; //base case
    reversed_triangle_row(i, n);
    reversed_triangle_recursive(++i, n);
}

void diamond_row(int i, int n) {
    if (i > n - 1) {    // mapping between upper and lower triangle
        // for example:
        // row 0 and row 8,
        // row 1 and row 7 are the same rows. So, mapping can be applied.
        // When we generalize this idea:
        // row i and row 2*n-2-i are shown to be the same row.
        i = 2 * n - 2 - i;
    }

    if (i == 0) {// first or last row
        // (n-1)space       1star      (n-1)space
        for (int j = 0; j < n - 1; j++) printf(" ");
        printf("*");
        for (int j = 0; j < n - 1; j++) printf(" ");
    } else if (i == n - 1) { // middle row
        for (int j = 0; j < 2 * n - 1; j++)
            printf("*");

    } else { // other rows
        //(n-i-1)space  1star   (2*i-1)space    1star   (n-i-1)space
        for (int j = 0; j < n - i - 1; j++) printf(" ");
        printf("*");
        for (int j = 0; j < 2 * i - 1; j++) printf(" ");
        printf("*");
        for (int j = 0; j < n - i - 1; j++) printf(" ");
    }
    printf("\n");

}
void diamond_loop(int n) {
    // n is the upper triangle row size
    for (int i = 0; i < 2 * n - 1; i++) {
        diamond_row(i, n);
    }
}
void diamond_recursive(int i, int n){
    if(i > 2*n-2) return;
    diamond_row(i, n);
    return diamond_recursive(++i, n);
}