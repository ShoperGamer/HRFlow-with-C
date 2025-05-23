
# HRFlow-with-C: ระบบลงทะเบียนพนักงานใหม่ (ภาษาไทย)

นี่คือโปรเจกต์ **HRFlow-with-C** ซึ่งเป็นโปรแกรมคอนโซลอย่างง่ายที่พัฒนาด้วยภาษา C สำหรับการลงทะเบียนและจัดการข้อมูลพนักงานใหม่เบื้องต้น โปรแกรมนี้ช่วยให้สามารถบันทึกข้อมูลสำคัญของพนักงานได้แก่ ชื่อ, เพศ, อายุ, และค่าประสบการณ์ (EXP) รวมถึงการตรวจสอบความถูกต้องของข้อมูลที่ป้อนเข้ามา

## คุณสมบัติหลัก

-   **บันทึกข้อมูลพนักงาน:** สามารถกรอกข้อมูลพนักงานใหม่ (ชื่อ, เพศ, อายุ, EXP) ได้
-   **แสดงข้อมูล:** แสดงรายละเอียดของพนักงานที่บันทึกไว้
-   **เพิ่มค่าประสบการณ์:** มีฟังก์ชันสำหรับเพิ่มค่า EXP ให้กับพนักงาน
-   **การตรวจสอบข้อมูล:**
    -   ตรวจสอบเพศ (M/F) (ชาย/หญิง)
    -   ตรวจสอบอายุ (ต้องเป็นตัวเลข, >20 และ <80)
    -   ตรวจสอบ EXP (ต้องเป็นตัวเลข, >= 0)
-   **ทำงานแบบวนซ้ำ:** สามารถเพิ่มพนักงานใหม่ได้หลายคนจนกว่าผู้ใช้จะเลือกหยุด

## วิธีการใช้งาน

1.  **คอมไพล์โปรแกรม:** ใช้คอมไพเลอร์ C เช่น GCC:
    
    Bash
    
    ```
    gcc HRFlow-with-C.c -o HRFlow-with-C
    
    ```
    
2.  **รันโปรแกรม:**
    
    Bash
    
    ```
    ./HRFlow-with-C
    
    ```
    
3.  **ทำตามคำแนะนำ:** โปรแกรมจะขอให้คุณป้อนข้อมูลพนักงาน และคุณสามารถเลือกที่จะเพิ่มพนักงานคนต่อไปได้

## โครงสร้างโค้ด

-   **`struct Employee`**: โครงสร้างข้อมูลสำหรับเก็บรายละเอียดของพนักงาน
-   **`createEmployee()`**: ฟังก์ชันสำหรับรับข้อมูลพนักงานใหม่จากผู้ใช้ พร้อมการตรวจสอบข้อมูลเบื้องต้น
-   **`showdata()`**: ฟังก์ชันสำหรับแสดงข้อมูลพนักงาน
-   **`addExperience()`**: ฟังก์ชันสำหรับเพิ่มค่าประสบการณ์ให้กับพนักงาน
-   **`main()`**: ฟังก์ชันหลักที่ควบคุมการทำงานของโปรแกรมให้เป็นไปตามวัฏจักรของการเพิ่มและแสดงผลพนักงาน

----------

# HRFlow-with-C: New Employee Registration System (English)

This is the **HRFlow-with-C** project, a simple console-based program developed in C for basic new employee registration and management. This program allows you to record essential employee information, including name, gender, age, and experience points (EXP), along with input validation.

## Key Features

-   **Employee Data Entry:** Allows inputting new employee details (name, gender, age, EXP).
-   **Data Display:** Displays the recorded employee information.
-   **Experience Increment:** Includes a function to add EXP to an employee.
-   **Input Validation:**
    -   Validates gender (M/F). (Male/Female)
    -   Validates age (must be a number, >20 and <80).
    -   Validates EXP (must be a number, >= 0).
-   **Looping Functionality:** You can add multiple new employees until you choose to stop.

## How to Use

1.  **Compile the Program:** Use a C compiler like GCC:
    
    Bash
    
    ```
    gcc HRFlow-with-C.c -o HRFlow-with-C
    
    ```
    
2.  **Run the Program:**
    
    Bash
    
    ```
    ./HRFlow-with-C
    
    ```
    
3.  **Follow the Prompts:** The program will prompt you to enter employee data, and you can choose to add more employees.

## Code Structure

-   **`struct Employee`**: A data structure to hold employee details.
-   **`createEmployee()`**: A function to gather new employee information from the user, including basic input validation.
-   **`showdata()`**: A function to display employee information.
-   **`addExperience()`**: A function to increment an employee's experience points.
-   **`main()`**: The main function that controls the program's loop for adding and displaying employees.