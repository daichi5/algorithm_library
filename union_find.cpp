#include <vector>
using namespace std;

struct UnionFind {
  //親ならば集合の頂点数に-1を掛けたもの
  //子ならば親のid
  vector<int> r;

  UnionFind(int N) {
    r = vector<int>(N, -1);
  }

  // 親idを返す
  int root(int x) {
    if (r[x] < 0) {
      return x;
    }
    return r[x] = root(r[x]);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (r[x] > r[y]) swap(x, y); 
    r[x] += r[y];
    r[y] = x;
    return true;
  }

  int size(int x) {
    return -r[root(x)];
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }
};