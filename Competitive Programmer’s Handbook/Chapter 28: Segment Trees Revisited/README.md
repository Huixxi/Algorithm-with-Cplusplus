# Segment Trees Revisited
```c++
int sum(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && y <= b) return tree[k];
    int d = (x + y) / 2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k+1, d+1, y);
}
```
