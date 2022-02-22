#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // building a vector containing vectors
    vector<vector<int>> v;
    
    // appending vectors to the vector
    v.push_back(vector<int>{1, 2, 3});
    v.push_back(vector<int>{50, 60});
    v.push_back(vector<int>{100, 200, 300});

    // popping vectors from the vector
    v.pop_back();

    // appending to the vector in the vector
    v[0].push_back(4);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            // accessing datas of the vector in the vector
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    // output:
    // 1 2 3 4
    // 50 60
    return 0;
}