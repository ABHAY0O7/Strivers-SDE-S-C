#define ll long long int
ll valid(ll mid, ll n, ll m) {
    if(mid >= 1e5) return 1;
    ll i = 1;
    ll val = mid;
    while(i < n && val < m) val *= mid, i++;
    // cout << 'a' << i << " " << val << endl;
    // if(val > m) return 1;
    if(i == n) {
      if(val == m) return 0;
      else if(val > m) return 1;
      return 2;
    } 
    return 1;
}
int NthRoot(int n, int m) {
  int ans = -1;
  // function<ll(ll)> valid = [&] (ll mid) -> ll {
  if(n == 1) return m;
  // };
  ll l = 1, r = m;
  while(l <= r) {
    ll mid = (l + r) / 2;
    ll curr = valid(mid, n, m);
    // cout << mid << " " << curr << endl;
    if(curr == 0) {
      ans = mid;
      break;
    }
    else if(curr == 1) r = mid - 1;
    else l = mid + 1;
  }
  return ans;
}
