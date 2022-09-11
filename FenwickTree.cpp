struct Fenwick{
    const int n;
    std::vector<T>tree;
    Fenwick(int n) : n(n+1), tree(n+1,0) {}
    void add(int x, T v) {
        for (int i = x; i <=n; i += i & -i)
            tree[i]^= v;
    }
    T query(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i)
            ans ^= tree[i];
        return ans;
    }
    T rangeQuery(int l, int r) {
        return query(r)^query(l-1);
    }
};
