#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int son[26][N], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(string &str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[u][p]) son[u][p] = ++ idx;
        p = son[u][p];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(string &str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[u][p]) return 0;
        p = son[u][p];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        char OP;
        cin >> OP;
        string s;
        cin >> s;
        if (OP == 'I')
        {
            insert(s);
        }
        else if (OP == 'Q')
        {
            cout << query(s) << endl;
        }
    }
}