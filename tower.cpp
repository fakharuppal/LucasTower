#include <iostream>
#include <cmath>
using namespace std;

// steps count
int steps = 0;

// hanoi_algorithm function which will call itself (Recursion) to divide large problem into smaller
void hanoi_algorithm(int n, char src, char aux, char dest)
{
    if (n == 1)
    {
        ++steps;
        cout << "\033[1;34m" << steps << ":\033[0m Moving Disk \033[4m1\033[0m | " << src << " --> " << dest << " |" << endl;
        return;
    }
    // Moving n-1 disks from src to helper
    hanoi_algorithm(n - 1, src, dest, aux);

    // Moving nth disk
    steps++;
    cout << "\033[1;34m" << steps << ":\033[0m Moving Disk \033[4m" << n << "\033[0m | " << src << " --> " << dest << " |" << endl;

    // Moving n-1 disks from aux to dest
    hanoi_algorithm(n - 1, aux, src, dest);
}

// clearScreen function
void screenClear()
{
    system("cls");
    system("clear");
}

// intro Function
void display(int &n)
{
    screenClear();
    // Introduction
    cout << "                  \033[1;36mTower of Hanoi\033[0m\n"
         << endl;
    // No. of disk
    cout << "       Enter the no. of disk to solve: ";
    cin >> n;
    cout << "------------------------------------------------------\n";
    cout << "|There will be \033[1;35m" << pow(2, n) - 1 << " steps\033[0m to move all disks from A to C |" << endl;
    cout << "------------------------------------------------------\n";
    cout << "     A: Source |  B: Helper  |   C: Destination\n\n";
    cout << "\033[1;3;31m* Steps:\033[0m\n";
}
// Main function
int main()
{
    int n;
    display(n);
    // A is src, B is Auxilary(helping), C is dest
    hanoi_algorithm(n, 'A', 'B', 'C');
    return 0;
}