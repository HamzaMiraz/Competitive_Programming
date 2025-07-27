#include <bits/stdc++.h>

using namespace std;
const int n = 7;
bool vis[n][n];
string path;
void move(int r, int c, int &ans, int steps)
{
    if (r == n - 1 && c == 0)
    {
        ans += (steps == n * n - 1);
        return;
    }
 
    // if you hit a wall or a path (can only go left or right); return
    if (((r + 1 == n || (vis[r - 1][c] && vis[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c + 1 == n || (vis[r][c - 1] && vis[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !vis[r - 1][c] && !vis[r + 1][c]) ||
        ((r == 0 || (vis[r + 1][c] && vis[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c == 0 || (vis[r][c + 1] && vis[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !vis[r - 1][c] && !vis[r + 1][c]))
        return;
    
    vis[r][c] = true;
 
    if (path[steps] != '?')
    {
        if (path[steps]=='U' && r - 1 >= 0 && !vis[r - 1][c])
            move(r - 1, c, ans, steps+1);

        if (path[steps]=='R' && c + 1 < n && !vis[r][c + 1])
            move(r, c + 1, ans, steps+1);
        
        if (path[steps]=='D' && r + 1 < n && !vis[r + 1][c])
            move(r + 1, c, ans, steps+1);
        
        if (path[steps]=='L' && c - 1 >= 0 && !vis[r][c - 1])
            move(r, c - 1, ans, steps+1);

        vis[r][c] = false;
        return;
    }
 
    if (r + 1 < n && !vis[r + 1][c])
        move(r + 1, c, ans, steps+1);

    if (c + 1 < n && !vis[r][c + 1])
        move(r, c + 1, ans, steps+1);
 
    if (r - 1 >= 0 && !vis[r - 1][c])
        move(r - 1, c, ans, steps+1);

    if (c - 1 >= 0 && !vis[r][c - 1])
        move(r, c - 1, ans, steps+1);

    vis[r][c] = false;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> path;
    int ans = 0, steps = 0;
    move(0, 0, ans, steps);
    cout << ans;
    return 0;
}