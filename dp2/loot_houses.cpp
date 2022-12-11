int maxMoneyLooted(int *arr, int n) {
  if (n == 1) {
    return arr[0];
  }
  int *dp = new int[n];
  dp[0] = arr[0];
  if (n > 1) {
    dp[1] = max(arr[0], arr[1]);
  }
  for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
  }
  int ans = dp[n - 1];
  delete[] dp;
  return ans;
}