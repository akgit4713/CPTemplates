struct DSU {
  vector<int> p;
  int n;
 
  DSU(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  bool merge(int x, int y){
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
