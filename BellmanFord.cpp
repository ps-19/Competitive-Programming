

// First, we transform the graph:

for (int i = 0; i < N; ++i)
  for (int j = 0; j < N; ++j)
    w[i][j] = -log(w[i][j]);


// Then we perform a standard Bellman-Ford

double dis[N], pre[N];

for (int i = 0; i < N; ++i)
   dis[i] = INF, pre[i] = -1;

dis[source] = 0;

for (int k = 0; k < N; ++k)
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (dis[i] + w[i][j] < dis[j])
        dis[j] = dis[i] + w[i][j], pre[j] = i;

// Now we check for negative cycles:

for (int i = 0; i < N; ++i)
  for (int j = 0; j < N; ++j)
    if (dis[i] + w[i][j] < dis[j])
      // Node j is part of a negative cycle