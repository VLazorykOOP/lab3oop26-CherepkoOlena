//
// Created by acer_ on 01.05.2026.
//

#include "tasks.h"

#include <iostream>
#include <ostream>

class Game {
    public:
    bool won = false;
    int field[3][3];
    int player = 0;

    Game() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                field[i][j] = 0;
    }

    void setPlayer(int id) {
        player = id;
    }

    void setField(int x, int y) {
        int activePlayer = player;
        if (activePlayer == 1)
            field[x][y] = 1;
        else field[x][y] = 2;
    }

    void printField() {
        std::cout << field[0][0] << "|" << field[0][1] << "|" << field[0][2] << std::endl;
        std::cout << "-|-|-" << std::endl;
        std::cout << field[1][0] << "|" << field[1][1] << "|" << field[1][2] << std::endl;
        std::cout << "-|-|-" << std::endl;
        std::cout << field[2][0] << "|" << field[2][1] << "|" << field[2][2] << std::endl;
    }

    void play() {
        if (player == 1)
            setPlayer(2);
        else if (player == 2)
            setPlayer(1);

        if (player == 0)
            setPlayer(1);

        std::cout << "Pick where to place your symbol" << std::endl;
        int x, y;
        std::cin >> x;
        std::cin >> y;

        std::cout << "Active player - " << player << std::endl;
        if (field[x][y] != 0)
            play();

        setField(x, y);
        printField();
        checkWin();
    }

    void checkWin() {
        if (field[0][0] == player && field[1][1] == player && field[2][2] == player)
            won = true;
        if (field[0][2] == player && field[1][1] == player && field[2][0] == player)
            won = true;
        for (int i = 0; i < 3; i++)
        {
            if (field[0][i] == player && field[1][i] == player && field[2][i] == player)
                won = true;
            if (field[i][0] == player && field[i][1] == player && field[i][2] == player)
                won = true;
        }
    }
};

void task1() {
    Game gam1 = Game();

    while (!gam1.won)
        gam1.play();

    std::cout << gam1.player << " is a winner" << std::endl;
}

class Vector {
    double arr[3];
    int state;
    static int objectCount;

public:
    // Пустий вектор
    Vector() {
        arr[0] = 0.0;
        arr[1] = 0.0;
        arr[2] = 0.0;
        state = 0;
        objectCount++;
    }
    // Одна змінна
    Vector(double val) {
        arr[0] = val;
        arr[1] = val;
        arr[2] = val;
        state = 0;
        objectCount++;
    }

    // Вказівник
    Vector(double* ptr) {
        if (ptr == nullptr) {
            arr[0] = 0.0;
            arr[1] = 0.0;
            arr[2] = 0.0;
            state = 1;
            std::cout << "Error NULL" << std::endl;
        } else {
            arr[0] = ptr[0];
            arr[1] = ptr[1];
            arr[2] = ptr[2];
            state = 0;
        }
        objectCount++;
    }

    //Деструктор
    ~Vector() {
        std::cout << "State when removed " << state << std::endl;
        objectCount--;
    }

    // Параметр за замовчуванням
    void setValue(double val = 3) {
        arr[0] = val;
        arr[1] = val;
        arr[2] = val;
        state = 0;
    }

    // 6. Функція, яка одержує деякий елемент масиву за індексом
    double getElement(int index) {
        if (index >= 0 && index < 3) {
            return arr[index];
        }
        std::cout << "Error: outside of array" << std::endl;
        return 0.0; 
    }

    //Друк
    void print() {
        std::cout << "[" << arr[0] << ", " << arr[1] << ", " << arr[2] << "] (State: " << state << ")" << std::endl;
    }

    // Додавання
    Vector add(Vector v) {
        Vector result;
        result.arr[0] = arr[0] + v.arr[0];
        result.arr[1] = arr[1] + v.arr[1];
        result.arr[2] = arr[2] + v.arr[2];
        return result;
    }

    // Віднімання
    Vector subtract(Vector v) {
        Vector result;
        result.arr[0] = arr[0] - v.arr[0];
        result.arr[1] = arr[1] - v.arr[1];
        result.arr[2] = arr[2] - v.arr[2];
        return result;
    }

    // Векторний добуток
    Vector crossProduct(Vector v) {
        Vector result;
        result.arr[0] = arr[1] * v.arr[2] - arr[2] * v.arr[1];
        result.arr[1] = arr[2] * v.arr[0] - arr[0] * v.arr[2];
        result.arr[2] = arr[0] * v.arr[1] - arr[1] * v.arr[0];
        return result;
    }

    // Ділення на ціле типу short
    void divideByShort(short divisor) {
        if (divisor == 0) {
            state = 2;
            std::cout << "Error: division by 0" << std::endl;
        } else {
            arr[0] = arr[0] / divisor;
            arr[1] = arr[1] / divisor;
            arr[2] = arr[2] / divisor;
        }
    }

    double getLengthSquare() {
        return arr[0]*arr[0] + arr[1]*arr[1] + arr[2]*arr[2];
    }

    // Порівняння
    bool isGreater(Vector v) {
        return getLengthSquare() > v.getLengthSquare();
    }

    bool isLess(Vector v) {
        return getLengthSquare() < v.getLengthSquare();
    }

    bool isEqual(Vector v) {
        return (arr[0] == v.arr[0] && arr[1] == v.arr[1] && arr[2] == v.arr[2]);
    }

    static int getCount() {
        return objectCount;
    }
};

int Vector::objectCount = 0;


void task2() {
    std::cout << "--- Test ---" << std::endl;
    Vector v1;
    std::cout << "v1 (no parameters): "; v1.print();

    Vector v2(5.0);
    std::cout << "v2 (one parameter): "; v2.print();

    double myArr[] = {1.5, 2.5, 3.5};
    Vector v3(myArr);
    std::cout << "v3 (with pointer): "; v3.print();

    Vector v4(nullptr);
    std::cout << "v4 (Error NULL): "; v4.print();

    std::cout << "\nObject count: " << Vector::getCount() << std::endl;

    std::cout << "\n--- Testing methods ---" << std::endl;
    v1.setValue();
    std::cout << "v1 after setValue(): "; v1.print();
    
    std::cout << "Get 2 element v3: " << v3.getElement(1) << std::endl;

    std::cout << "\n--- Math ---" << std::endl;
    Vector v_add = v2.add(v3);
    std::cout << "Sum (v2 + v3): "; v_add.print();

    Vector v_sub = v2.subtract(v3);
    std::cout << "Diff (v2 - v3): "; v_sub.print();

    Vector v_cross = v2.crossProduct(v3);
    std::cout << "Cross (v2 x v3): "; v_cross.print();

    std::cout << "\n--- Test division ---" << std::endl;
    short div1 = 2;
    v2.divideByShort(div1);
    std::cout << "v2 after division 2: "; v2.print();

    short div0 = 0;
    v2.divideByShort(div0);
    std::cout << "v2 after division on 0: "; v2.print();

   std::cout << "\n--- Test comparison ---" <<std::endl;
   std::cout << "v2 more v3? " << (v2.isGreater(v3) ? "Yes" : "No") <<std::endl;
   std::cout << "v2 less v3? " << (v2.isLess(v3) ? "yes" : "No") <<std::endl;
    
    Vector v_eq(v3);
   std::cout << "v3 equal v3? " << (v3.isEqual(v_eq) ? "Yes" : "No") <<std::endl;

   std::cout << "\n--- Destructors ---" <<std::endl;
}


