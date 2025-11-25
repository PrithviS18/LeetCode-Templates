typedef long long ll;

class Solution {
public:
    const ll MOD = 1000000007LL; // single prime modulus
    const ll BASE = 131LL;       // base for polynomial rolling hash

    // iterative fast exponentiation (modular)
    ll modPow(ll a, ll e, ll mod) {
        ll res = 1 % mod;
        a %= mod;
        while (e > 0) {
            if (e & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            e >>= 1;
        }
        return res;
    }

    // compute normalized hash of substring [l..r] given prefix hash and inv arrays
    ll substringHash(int l, int r, const vector<ll>& pref, const vector<ll>& inv) {
        ll val = pref[r];
        if (l > 0) {
            val = (val - pref[l - 1] + MOD) % MOD;
        }
        // normalize so that substring behaves as if at position 0
        val = (val * inv[l]) % MOD;
        return val;
    }

    string shortestPalindrome(string s) {
        int n = (int)s.size();
        if (n <= 1) return s;

        // allocate
        vector<ll> p_power(n), inv(n), pref_s(n), pref_rev(n);

        // compute powers p_power[i] = BASE^i mod MOD
        p_power[0] = 1;
        for (int i = 1; i < n; ++i) p_power[i] = (p_power[i - 1] * BASE) % MOD;

        // inv[i] = inverse of p_power[i] mod MOD
        inv[n - 1] = modPow(p_power[n - 1], MOD - 2, MOD); // Fermat since MOD is prime
        for (int i = n - 2; i >= 0; --i) inv[i] = (inv[i + 1] * BASE) % MOD;

        // prefix hash for s: pref_s[i] = sum_{k=0..i} (val(s[k]) * p_power[k])
        for (int i = 0; i < n; ++i) {
            ll val = ((ll)(s[i] - 'a' + 1) * p_power[i]) % MOD;
            pref_s[i] = val;
            if (i > 0) pref_s[i] = (pref_s[i] + pref_s[i - 1]) % MOD;
        }

        // prefix hash for reversed string
        string rev = s;
        reverse(rev.begin(), rev.end());
        for (int i = 0; i < n; ++i) {
            ll val = ((ll)(rev[i] - 'a' + 1) * p_power[i]) % MOD;
            pref_rev[i] = val;
            if (i > 0) pref_rev[i] = (pref_rev[i] + pref_rev[i - 1]) % MOD;
        }

        // find the largest i such that s[0..i] is palindrome
        int best = 0;
        for (int i = n - 1; i >= 0; --i) {
            // hash of s[0..i], normalized
            ll h1 = substringHash(0, i, pref_s, inv);
            // reverse counterpart in rev is rev[n-1-i .. n-1]
            int rl = n - 1 - i;
            int rr = n - 1;
            ll h2 = substringHash(rl, rr, pref_rev, inv);

            if (h1 == h2) { best = i; break; }
        }

        string suf = s.substr(best + 1);
        reverse(suf.begin(), suf.end());
        return suf + s;
    }
};
