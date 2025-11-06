#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 MOD = 998244353;

int64 modpow(int64 a, unsigned long long e){
    int64 r = 1 % MOD;
    a %= MOD;
    while(e){
        if(e & 1ULL) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1ULL;
    }
    return r;
}
int64 modinv(int64 x){ return modpow((x%MOD+MOD)%MOD, MOD-2); }

// C(m,len, baseR): sum_{j=0..m-1} val_len(j) * baseR^j .
// val_len(j) = decimal value of j written as len-bit binary with leading zeros.
struct CCalculator {
    int len_max;
    int64 baseR; // r = inv(10^k) for current block
    // memoization map keyed by pair (m,len) -> value
    unordered_map<unsigned long long, int64> memo; // key = ( (unsigned long long)len << 56 ) | (m & ((1ULL<<56)-1))
    CCalculator(int _len_max, int64 _baseR): len_max(_len_max), baseR(_baseR){
        memo.reserve(1024);
    }

    // key combiner: len up to ~60, m up to 1e15 fits into 56 bits
    static unsigned long long make_key(unsigned long long m, int len){
        return ( (unsigned long long)len << 56 ) | (m & ((1ULL<<56)-1));
    }

    int64 sumPowsGeom(unsigned long long cnt){ // sum_{j=0..cnt-1} baseR^j
        if(cnt == 0) return 0;
        if(baseR == 1){
            return (int64)(cnt % MOD);
        } else {
            int64 num = (modpow(baseR, cnt) - 1 + MOD) % MOD;
            int64 den = (baseR - 1 + MOD) % MOD;
            return num * modinv(den) % MOD;
        }
    }

    int64 compute(unsigned long long m, int len){
        if(m == 0) return 0;
        if(len == 0) return 0;
        auto key = make_key(m, len);
        auto it = memo.find(key);
        if(it != memo.end()) return it->second;

        unsigned long long half = 1ULL << (len - 1); // 2^{len-1}
        int64 res = 0;
        if(m <= half){
            // leading bit is zero for all, so val_len(j) == val_{len-1}(j)
            res = compute(m, len - 1);
        } else {
            // first half (j in [0, half-1]) -> same as compute(half, len-1)
            int64 S1 = compute(half, len - 1);

            // second half j = half + j', j' in [0, m-half-1]
            unsigned long long m2 = m - half;
            // sum of 10^{len-1} * baseR^{half + j'} for j'=0..m2-1
            // = baseR^{half} * 10^{len-1} * sum_{j'=0..m2-1} baseR^{j'}
            int64 baseR_pow_half = modpow(baseR, half);
            int64 geom = sumPowsGeom(m2); // sum baseR^{j'} j'=0..m2-1
            int64 termA = baseR_pow_half * (__int128)( (modpow(10, len-1) * 1LL) % MOD ) % MOD;
            termA = termA * geom % MOD;

            // plus baseR^{half} * C(m2, len-1)
            int64 S2part = compute(m2, len - 1);
            int64 termB = baseR_pow_half * (__int128)S2part % MOD;

            res = (S1 + termA) % MOD;
            res = (res + termB) % MOD;
        }
        memo[key] = res;
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    vector<unsigned long long> qs(t);
    for(int i=0;i<t;i++) cin >> qs[i];

    for(int i=0;i<t;i++){
        unsigned long long n = qs[i];
        int64 ans = 0;

        // compute up to max k where 2^{k-1} <= n
        for(int k = 1; (1ULL << (k-1)) <= n; ++k){
            unsigned long long L = 1ULL << (k-1);
            unsigned long long R = min((1ULL<<k) - 1ULL, n);
            unsigned long long cnt = R - L + 1ULL;
            if(cnt == 0) continue;

            // part1 = 10^{k-1} * (10^{k*cnt} - 1) / (10^k - 1)
            int64 ten_k = modpow(10, k);
            int64 ten_k_cnt = modpow(ten_k, cnt);
            int64 denom = (ten_k - 1 + MOD) % MOD;
            int64 geom_sum;
            if(denom == 0){
                // ten_k % MOD == 1 case (rare), sum is cnt % MOD
                geom_sum = (int64)(cnt % MOD);
            } else {
                geom_sum = ( (ten_k_cnt - 1 + MOD) % MOD ) * modinv(denom) % MOD;
            }
            int64 part1 = (modpow(10, k-1) * (__int128)geom_sum) % MOD;

            // part2 = 10^{k*(cnt-1)} * C(cnt, k-1, r) where r = inv(10^k)
            int64 r = modinv(ten_k);
            CCalculator calc(k-1, r);
            int64 Cval = calc.compute(cnt, k-1);
            // multiply by 10^{k*(cnt-1)}
            unsigned long long exponent = (unsigned long long)k * (cnt - 1ULL);
            int64 factor = modpow(10, exponent);
            int64 part2 = factor * (__int128)Cval % MOD;

            int64 A_k = (part1 + part2) % MOD;

            // ans = ans * 10^{k*cnt} + A_k
            unsigned long long shiftExp = (unsigned long long)k * cnt;
            int64 shiftVal = modpow(10, shiftExp);
            ans = ( (__int128)ans * shiftVal + A_k ) % MOD;
        }

        cout << (ans % MOD + MOD) % MOD << "\n";
    }
    return 0;
}
