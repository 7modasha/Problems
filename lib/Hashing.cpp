class RollingHashing {

    int base;
    const int MOD = 1000000007;

    vector<ll> h, pw;
    vector<ull> h64, pw64;

public:

    RollingHashing(const string &s, int base)
                : base(base), h(s.size()+1), pw(s.size()+1),
                  h64(s.size()+1), pw64(s.size()+1){

        pw[0] = pw64[0] = 1;
        for(int i = 0; i < s.size(); ++i){
            h[i+1] = (h[i] * base + s[i]) % MOD;
            h64[i+1] = h64[i] * base + s[i];

            pw[i+1] = (pw[i] * base) % MOD;
            pw64[i+1] = pw64[i] * base;
        }
    }

    pair<ll, ull> getHash(int i, int len){

        ll r1 = (h[i+len] - h[i] * pw[len])%MOD;
        r1 = r1 + (r1 < 0 ? MOD : 0);

        ull r2 = h64[i+len] - h64[i] * pw64[len];

        return make_pair(r1, r2);
    }
};