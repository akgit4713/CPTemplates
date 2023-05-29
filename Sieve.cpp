struct Siever {
    static constexpr int MAXN = 1e5;
    int spf[MAXN + 1];
    Siever() {
        for (int i = 0; i <= MAXN; i++) spf[i] = i;
        for (int i = 4; i <= MAXN; i += 2) spf[i] = 2;
        for (int i = 3; i <= MAXN; i += 2)
            if (spf[i] == i) {
                for (int j = 2 * i; j <= MAXN; j += i)
                    spf[j] = i;
            }
    }

    vector<int> getPrimes(int num) {
        set<int> primes;
        while (num != 1) {
            int prime = spf[num];
            primes.emplace(prime);
            num /= prime;
        }
        return vector<int>(begin(primes), end(primes));
    }

} siever;
