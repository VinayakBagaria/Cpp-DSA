🧠 The Pattern (Core Idea)

You should think:

“Can I rewrite the condition so that it becomes
f(i) == f(j) instead of comparing i and j directly?”

If YES → 💥 hashmap pattern applies

----------------

🔍 How to Recognize It

Look for problems where:

1. You are given a condition on pairs (i, j)

Something like:

```
j - i == nums[j] - nums[i]
```
2. You can rearrange it into this form:
f(i) == f(j)

Example:

```
i - nums[i] == j - nums[j]
```

👉 Now it's no longer about pairs — it's about grouping


```
unordered_map<int, long long> mp;
long long ans = 0;

for (int i = 0; i < n; i++) {
    int key = f(i);
    ans += mp[key];   // count previous matches
    mp[key]++;
}
```

Eg: https://leetcode.com/problems/count-number-of-bad-pairs/
