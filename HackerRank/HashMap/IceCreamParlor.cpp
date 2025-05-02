void whatFlavors(vector<int> cost, int money) {
    unordered_map<int, int> um;  // 가격 → 인덱스

    for (int i = 0; i < cost.size(); i++) {
        int needed = money - cost[i];
        if (um.count(needed)) {
            // 인덱스는 1-based
            int a = um[needed] + 1;
            int b = i + 1;
            cout << min(a, b) << " " << max(a, b) << "\n";
            return;
        }
        um[cost[i]] = i;
    }
}
