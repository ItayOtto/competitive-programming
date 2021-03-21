vi d = a;
sort(d.begin(), d.end());
d.resize(unique(all(d)) - d.begin());
for (int i = 0; i < n; ++i) {
  a[i] = lower_bound(all(d), a[i]) - d.begin();
}
//original value of a[i] can be obtained through d[a[i]]
//compressed array is now a[i]
