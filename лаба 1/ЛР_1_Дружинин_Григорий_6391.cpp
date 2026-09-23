#include <iostream>
using namespace std;

#define ld long double
#define pd pair<ld, ld>
#define x first
#define y second

int main() {
    pd A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    // Нахождение прямого угла
    bool IsDown = false;
    int flag = -1;

    if (A.x != A.y)
        flag = 1;

    // Меняем координаты вершин местами, исходный треугольник не меняется
    if (B.x != B.y) {
        flag = 1;

        swap(A, B);
    }

    // Меняем координаты вершин местами, исходный треугольник не меняется
    if (C.x != C.y) {
        flag = 1;

        swap(A, C);
    }

    // Треугольник является точкой
    if (flag == -1) {
        cout << "The triangle is degenerate";
        return 0;
    }

    // Определяем, находится ли прямой угол снизу
    if (A.x > A.y) IsDown = true;

    pd Point;
    // Ввод координат точки до пары {0,0}
    while ((cin >> Point.x >> Point.y) && ((Point.x != 0) || (Point.y != 0))) {
        if (IsDown) {
            if ((Point.x <= A.x) && (Point.y >= A.y) && (Point.x >= Point.y))
                cout << "A point inside the triangle\n";
            else
                cout << "A point outside the triangle\n";
        }
        else {
            if ((Point.x >= A.x) && (Point.y <= A.y) && (Point.x <= Point.y))
                cout << "A point inside the triangle\n";
            else
                cout << "A point outside the triangle\n";
        }
    }
    return 0;
}
