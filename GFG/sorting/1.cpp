#include <iostream>
#include <algorithm> // for sort
using namespace std;

struct Point {
    int x, y;
};

bool myCmp(Point p1, Point p2) {
    return (p1.y < p2.y); // sort by y-coordinate
}

int main() {
    Point arr[] = { {3, 10}, {2, 8}, {5, 4} };

    sort(arr, arr + 3, myCmp); // fixed: added semicolon

    for (auto i : arr) {
        cout << i.x << " " << i.y << endl;
    }

    return 0;
}
