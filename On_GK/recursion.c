#include <stdio.h>
#include <math.h>
typedef struct {
    char fullname[30];
    int year;
    double gpa;
} Student;

// Viết hàm nhập sinh viên(theo thứ tự khai báo
// thành phần cấu trúc trên) có tên ScanStudent() và trả về sinh viên đó

// Dùng fgets(string_variable, sizeof(string_variable), stdin) để nhập chuỗi.

// For example:

// Test	Input	Result
// Student S = ScanStudent();
// printf("%s %d %4.2lf",S.fullname ,S.year,S.gpa);
// Le Thanh Hung
// 2021
// 7.8
// Le Thanh Hung 2021 7.80
// Le Thanh Hung\0
Student ScanStudent() {
    Student a1;
    // fflush(stdin);
    fgets(a1.fullname,30,stdin);
    a1.fullname[strlen(a1.fullname)-1]='\0';
    scanf("%d",&a1.year);
    scanf("%lf",&a1.gpa);
    return a1;
}

int main()
{
    Student S = ScanStudent();
    printf("%s %d %4.2lf", S.fullname, S.year, S.gpa);
    return 0;
}
