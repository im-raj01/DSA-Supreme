 vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<int> d(n, 0);
        for (int i = 1; i < n; ++i) {
            d[i] = d[i - 1] + 1;
        }

        set<int> stt;
        for (int i = 0; i < n; ++i) {
            stt.insert(i);
        }

        vector<int> vec;

        for (auto& qi : q) {
            int l = qi[0];
            int rt = qi[1];

            auto lb = stt.lower_bound(l + 1);
            auto ub = stt.lower_bound(rt);

            stt.erase(lb, ub);

            vec.push_back(stt.size() - 1);
        }

        return vec;
    }