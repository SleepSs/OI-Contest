const int N = 1e5 + 10;
// 第一个元素在1
int stk[N], tt;

void push(int x) {stk[++ tt] = x;}
int pop() {return stk[tt--];}
bool isEmpty() {return tt == 0;}
int query() {return stk[tt];}