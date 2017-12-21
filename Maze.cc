#include <iostream>
#include "Stack.h"
using namespace std;

struct offsets {
    int a, b;
};

enum directions {N, NE, E, SE, S SW, W, NW};
offsets move[8];

struct Items {
    int x, y, dir;
};

// Output a path (if any) in the maze; maze[0][i] = maze[m+1][i]
void Path(const int m, const int p) {

    // start at (1,1)
    mark[1][1] = 1;
    Stack<Items> stack(m*p);
    Items temp(1, 1, E); // set temp.x, temp.y, temp.dir
    stack.Push(temp);

    while (!stack.IsEmpty()) { // stack not empty
        temp = stack.Top();
        stack.Pop(); // unstack
        
        int i = temp.x, j = temp.y, d = temp.dir;
        while (d < 8) { // move forward
            int g = i + move[d].a;
            int h = j + move[d].b;
            if ((g == m) && (h == p)) { // reached exit
                cout << stack;
                cout << i << " " << j << endl; // last two squares on the path
                cout << m << " " << p << endl;
                return;
            }


            if ((!maze[g][h]) && (!mark[g][h])) {
                mark[g][h] = 1;
                temp.x = i; temp.y = j; temp.dir = d + 1;
                stack.Push(temp); // stack it
                i = g; j = h; d = N;// move to (g, h)
            } else d++; // try next direction
        }
    }
    cout << "No path in maze." << endl;
}

int main() {
    return 0;
}
