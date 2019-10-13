// bayesdecisiontheory.cpp
#include <bits/stdc++.h>
using namespace std;
double cond_prob(int fval, int j, int cls, vector<vector<int>> &f, vector<int> &c, int t)
{
    double num = 0, denom = 0;
    int i;
    for (i = 0; i < t; i++)
    {
        denom += (c[i] == cls);
        num += (f[i][j] == fval && c[i] == cls);
    }
    if (denom == 0)
        return 0;
    return num / denom;
}
int main()
{
    int n, x, t, i, j;
    cout << "Enter x number of features and n number of classes\n";
    cin >> x >> n;
    cout << "Enter number of test sets\n";
    cin >> t;
    vector<vector<int>> f(t, vector<int>(x));
    vector<int> c(t);
    cout << "Enter features for training sets followed by their class\n";
    for (i = 0; i < t; i++)
    {
        // cout<<"Enter features for "<< i <<"training set\n";
        for (j = 0; j < x; j++)
            cin >> f[i][j];
        // cout<<"Enter class for the specific training set (0 to n-1)\n";
        cin >> c[i];
    }
    vector<double> pc(n); // probability of classes P(c)
    for (i = 0; i < t; i++)
        pc[c[i]]++;
    for (i = 0; i < n; i++)
        pc[i] /= t;

    cout << "Now, Enter Features of the new object and its classes will be determined\n";
    vector<int> fo(x);
    for (i = 0; i < x; i++)
        cin >> fo[i];
    vector<double> cp(n, 1);
    // product of p(f1/ci)*p(f2/ci)*..*p(ci)
    for (i = 0; i < n; cp[i] *= pc[i], i++)
        for (j = 0; j < x; j++)
            cp[i] *= cond_prob(fo[j], j, i, f, c, t);
    double ma = 0, mai;
    for (i = 0; i < n; i++)
    {
        if (cp[i] > ma)
        {
            ma = cp[i];
            mai = i;
        }
        cout << cp[i] << ' ';
    }
    cout << '\n';
    cout << "Class is: " << mai << " with probaility " << ma << '\n';
    return 0;
}
/*
Enter x number of features and n number of classes
3 2
Enter number of test sets
10
Enter features for training sets followed by their class
0 0 0 1
0 0 0 0
0 0 0 1
1 0 0 0
1 0 1 1
1 1 1 0
1 1 1 1
1 1 0 0
0 1 1 0
0 1 1 1
Now, Enter Features of the new object and its classes will be determined
1 0 1
0.048 0.072 
Class is: 1 with probaility 0.072
*/
