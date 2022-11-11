const visited = new Array(10).fill(0);
let maxCnt = 0;
function dfs(health, cnt, k, dungeons) {
  for (let i = 0; i < dungeons.length; i++) {
    if (!visited[i] && health >= dungeons[i][0]) {
      visited[i] = 1;
      health -= dungeons[i][1];
      cnt++;
      if (cnt === dungeons.length) return (maxCnt = cnt);
      dfs(health, cnt, k, dungeons);
      health += dungeons[i][1];
      cnt--;
      visited[i] = 0;
    }
  }
  maxCnt = Math.max(maxCnt, cnt);
  return maxCnt;
}
function solution(k, dungeons) {
  let answer = 0;
  answer = dfs(k, 0, k, dungeons);
  return answer;
}
