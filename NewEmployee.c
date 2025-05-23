#include <stdio.h>  // สำหรับ input/output เช่น printf, scanf
#include <string.h> // สำหรับ strcpy, strcspn
#include <stdlib.h> // สำหรับ getchar เพื่อเคลียร์ buffer

//โครงสร้างข้อมูลชื่อ Employee
typedef struct {
    char name[20];
    char gender;
    int age;
    int exp;
} Employee;

//เรียกใช้โครงสร้าง และ ฟังก์ชั่นต่างๆ
void showdata(Employee *person);
Employee createEmployee();
void addExperience(Employee *person, int amount);

int main() {
    char choice;
    do {
        Employee current_employee = createEmployee(); // สร้างพนักงานใหม่และรับข้อมูล

        printf("\n--- ข้อมูลพนักงาน ---\n");
        showdata(&current_employee);

        // ตัวอย่างการเพิ่มค่า exp อัตโนมัติหลังจากแสดงข้อมูล
        addExperience(&current_employee, +10); // เพิ่ม exp 10 หน่วย
        printf("EXP เพิ่มขึ้น! EXP ใหม่: %d\n", current_employee.exp);
        printf("---------------------\n");

        printf("ต้องการเพิ่มรายชื่อพนักงานอีกคนหรือไม่? (y/n): ");
        scanf(" %c", &choice);

        // เคลียร์ input buffer เพื่อให้ fgets ในรอบถัดไปทำงานถูกต้อง
        while (getchar() != '\n' && getchar() != EOF);

    } while (choice == 'y' || choice == 'Y');

    printf("\nจบการทำงาน. พบกันใหม่!\n");
    return 0;
}

// ฟังก์ชันสำหรับแสดงข้อมูลพนักงาน (รับเป็น pointer)
void showdata(Employee *person) {
    printf("ชื่อ   = %s\n", person->name);    // ใช้ -> เพื่อเข้าถึงสมาชิกผ่าน pointer
    printf("เพศ  = %c\n", person->gender);
    printf("อายุ  = %d\n", person->age);
    printf("EXP  = %d\n", person->exp);     // แสดงค่า exp ด้วย
    printf("---------------\n");
}

// ฟังก์ชันสำหรับสร้างและรับข้อมูลพนักงานจากผู้ใช้
Employee createEmployee() {
    Employee newEmp;
    printf("\n--- กรอกรายละเอียดพนักงานใหม่ ---\n");
    printf("กรุณาป้อนชื่อ: ");
    fgets(newEmp.name, sizeof(newEmp.name), stdin); // ใช้ fgets เพื่ออ่านสตริงที่มีช่องว่างได้และป้องกัน buffer overflow
    // ลบ newline character ที่ fgets อาจอ่านเข้ามา
    newEmp.name[strcspn(newEmp.name, "\n")] = 0;

    //รับค่า + ตรวจสอบเพศ
    char temp_gender;
    int valid_input = 0;
    while (!valid_input) {
        printf("กรุณาป้อนเพศ (M/F): ");
        scanf(" %c", &temp_gender);
        while (getchar() != '\n' && getchar() != EOF);

        // ตรวจสอบเพศ
        if (temp_gender == 'M' || temp_gender == 'm' || temp_gender == 'F' || temp_gender == 'f') {
            newEmp.gender = temp_gender;
            valid_input = 1;
        } else {
            printf("ผิดพลาด: กรุณาป้อนค่าให้ถูกต้อง \n");
        }
    }

    //อายุ
    int valid_age_input = 0;
    while (!valid_age_input) {
        printf("กรุณาป้อนอายุ: ");

        //ตรวจสอบว่าใส่เลขหรือไม่
        if (scanf("%d", &newEmp.age) == 1) {
            //ตรวจสอบอายุ
            if (newEmp.age > 20 && newEmp.age < 80) {
                valid_age_input = 1;
            } else {
                printf("ผิดพลาด: อายุต้องเป็นตัวเลขบวกและสมเหตุสมผล\n");
            }
        } else {
            printf("ผิดพลาด: กรุณาป้อนอายุเป็นตัวเลขเท่านั้น.\n");
        }
        while (getchar() != '\n' && getchar() != EOF);
    }

    //ประสบการณ์
    int valid_exp_input = 0;
    while (!valid_exp_input) {
        printf("กรุณาป้อนประสบการณ์ (EXP): ");

        //ตรวจสอบว่าเป็นตัวเลขหรือไม่
        if (scanf("%d", &newEmp.exp) == 1) {
            //ประสบการณ์ต้องไม่น้อยกว่า 0
            if (newEmp.exp >= 0) {
                valid_exp_input = 1;
            } else {
                printf("ผิดพลาด: ประสบการณ์ต้องเป็นตัวเลขที่ไม่ติดลบ.\n");
            }
        } else {
            printf("ผิดพลาด: กรุณาป้อนประสบการณ์เป็นตัวเลขเท่านั้น.\n");
        }
        while (getchar() != '\n' && getchar() != EOF);
    }

    return newEmp;
}

// ฟังก์ชันสำหรับเพิ่มค่าประสบการณ์ให้กับพนักงาน
void addExperience(Employee *person, int amount) {
    person->exp += amount;// เพิ่มค่า exp ให้กับสมาชิก exp ของ struct ที่ pointer ชี้ไป
}