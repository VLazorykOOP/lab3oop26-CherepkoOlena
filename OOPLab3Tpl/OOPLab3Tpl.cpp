// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

// Ваші файли загловки 
//
#include "Lab3Example.h"
#include "tasks.h"

int main()
{
    std::cout << " Lab #3  !\n";
    std::cout << "Select a task " << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Task 1 - Game Class " << std::endl;
    std::cout << "2. Task 2 - Vector Class " << std::endl;
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту

   int task = 0;
    std::cout << "Enter the task number " << std::endl;
    std::cin >> task;

    if (task == 1)
        task1();
    else if (task == 2)
        task2();

}

