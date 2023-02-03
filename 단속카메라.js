function solution(routes) {
  var answer = 1;
  const sortedRoutes = routes.sort((a, b) => {
    if (a[0] > b[0]) {
      return 1;
    }
    if (a[0] < b[0]) return -1;
    return 0;
  });
  let left = sortedRoutes[0][0];
  let right = sortedRoutes[0][1];
  for (let i = 1; i < sortedRoutes.length; i++) {
    //범위안에 모두포함
    if (sortedRoutes[i][0] >= left && sortedRoutes[i][1] <= right) {
      left = sortedRoutes[i][0];
      right = sortedRoutes[i][1];
      continue;
    }

    if (sortedRoutes[i][0] >= left && sortedRoutes[i][0] <= right) {
      continue;
    }
    answer += 1;
    left = sortedRoutes[i][0];
    right = sortedRoutes[i][1];
  }
  return answer;
}

