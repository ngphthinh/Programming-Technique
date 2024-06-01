#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//  Bài toán quản lý sinh viên. Viết chương trình thực hiện các yêu cầu:
// Nhập dữ liệu các sinh viên vào một danh sách liên kết đơn, trường dữ liệu của mỗi
// nút bao gồm: Họ lót, tên, điểm toán, điểm tin. Sau đó lưu dữ liệu vào một tập tin có
// tên DULIEU.DAT
// In danh sach sinh viên vừa nhập
// Mở tập tin DULIEU.DAT để tu sửa các mẫu tin.
// Đọc nội dung tập tin DULIEU.DAT vào danh sách liên kết đơn (sau khi đã tu sủa)
// và hiển thị ra màn hình các mẫu tin
typedef struct
{
    char fisrtname[15];
    char lastname[10];
    float math, informatics;
} SV;
void input_Integer(int *n)
{
    printf("nhap n:");
    scanf("%d", n);
}
void scan_sv(SV *elm)
{
    fflush(stdin);
    printf("nhap ho:");
    gets(elm->fisrtname);
    printf("nhap ten:");
    gets(elm->lastname);
    printf("nhap diem:");
    scanf("%f %f", &elm->math, &elm->informatics);
    getchar();
}
void scan_dssv(SV *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        scan_sv(&list[i]);
    }
}
void print_dssv(SV list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s %s %.2f %.2f\n", list[i].fisrtname, list[i].lastname, list[i].math, list[i].informatics);
    }
}
void write_to_file(SV list[], int size)
{
    FILE *fp = fopen("file6bai5.DAT", "wb");
    fwrite(list, sizeof(SV), size, fp);
    fclose(fp);
}
void read_from_file(SV list[], int *n)
{
    FILE *fp = fopen("file6bai5.DAT", "rb");
    fseek(fp, 0, SEEK_SET);
    *n = ftell(fp) / sizeof(SV);
    rewind(fp);
    fread(list, sizeof(SV), *n, fp);
    fclose(fp);
}

int main()
{
    SV DSSV[100];
    int n;
    input_Integer(&n);
    scan_dssv(DSSV, n);
    print_dssv(DSSV, n);
    write_to_file(DSSV, n);

    int size;
    SV read_DSSV[100];
    read_from_file(read_DSSV, &size);
    print_dssv(read_DSSV, size);
    return 0;
}