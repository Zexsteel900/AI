#include <iostream>
using namespace std;

class graph
{
public:
    int m[20][20];
    int visited[20];
    int n;
    void accept();
    void display();
    void dfs(int);
    void bfs(int);
    int returnN()
    {
        return n;
    }
};

void graph::accept()
{
    cout << "\nEnter number of vertices:\n";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    cout << "\nEnter the adjacency matrix:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
}

void graph::display()
{
    cout << "\nThe adjacency matrix is:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "\n";
        for (int j = 1; j <= n; j++)
        {
            cout << "\t" << m[i][j];
        }
    }
}

void graph::dfs(int v)
{
    cout << "\n"
         << v;
    visited[v] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (m[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

void graph::bfs(int v)
{
    int queue[20];
    int front = 0, rear = 0;
    visited[v] = 1;
    cout << "\n"
         << v;
    queue[++rear] = v;
    while (front != rear)
    {
        v = queue[++front];
        for (int j = 1; j <= n; j++)
        {
            if (m[v][j] == 1 && visited[j] == 0)
            {
                queue[++rear] = j;
                visited[j] = 1;
                cout << j << " ";
            }
        }
    }
}

int main()
{
    int ch;
    graph g;
    char ans;
    do
    {
        cout << "\nMenu\n1: Accept\n2: Display\n3: DFS Recursive\n4: BFS \n5: Reset to try either BFS or DFS \nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g.accept();
            break;

        case 2:
            g.display();
            break;

        case 3:
            cout << "\nDepth-first display of vertices: ";
            g.dfs(1);
            break;
        case 4:
            cout << "\nBreadth First Display of Vertices: ";
            g.bfs(1);
            break;
        case 5:
            int n;
            cout << "\nEnter the number of vertices: ";
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                g.visited[i] = 0;
            }
        }
        cout << "\nContinue(y/n): ";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}
// 3 vertices  0 1 0 1 0 1 0 1 0 dfs 1 2 3 bfs 123