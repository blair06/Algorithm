const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString();

input = input.trim().split("\n"); // 한 줄씩 데이터 분리
const temp = input[0].split(" ");
const n = parseInt(temp[0]);
const m = parseInt(temp[1]);

const arr = Array.from(Array(n), () => Array(m).fill(0));
for (let i = 1; i < input.length; i++) {
  for (let j = 0; j < input[i].length; j++) {
    arr[i - 1][j] = input[i][j];
  }
}
const dx = [-1, 1, 0, 0];
const dy = [0, 0, 1, -1];
const checkAlpha = new Array(100).fill(false);
function dfs(x, y) {
  let answer = 1;
  console.log(arr[x][y], x, y);
  for (let dir = 0; dir < 4; dir++) {
    const nx = x + dx[dir];
    const ny = y + dy[dir];

    if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
    if (checkAlpha[arr[nx][ny].charCodeAt() - 65]) continue;
    checkAlpha[arr[nx][ny].charCodeAt() - 65] = true;
    answer = Math.max(answer, dfs(nx, ny) + 1);
    checkAlpha[arr[nx][ny].charCodeAt() - 65] = false;
  }
  return answer;
}

function solution(n, arr) {
  checkAlpha[arr[0][0].charCodeAt() - 65] = true;

  const cnt = dfs(0, 0);
  console.log(cnt);
}
solution(n, arr);
