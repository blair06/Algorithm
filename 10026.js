const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();

input = input.split("\n"); // 한 줄씩 데이터 분리

const n = +input[0];
const arr = Array.from(Array(n), () => Array(n).fill(0));
for (let i = 1; i < input.length; i++) {
  for (let j = 0; j < input[i].length; j++) {
    arr[i - 1][j] = input[i][j];
  }
}
const dx = [-1, 1, 0, 0];
const dy = [0, 0, 1, -1];

function bfs() {
  const visited = Array.from(Array(n), () => Array(n).fill(0));

  const queue = [];
  queue.push([0, 0]);
  let cnt = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (!visited[i][j]) {
        visited[i][j] = 1;
        cnt++;
        queue.push([i, j]);
        while (queue.length !== 0) {
          const curArr = queue.shift();
          const curX = +curArr[0];
          const curY = +curArr[1];
          for (let dir = 0; dir < 4; dir++) {
            const nx = curX + dx[dir];
            const ny = curY + dy[dir];
            if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            if (visited[nx][ny] !== 0) continue;
            if (arr[nx][ny] !== arr[curX][curY]) continue;

            visited[nx][ny] = 1;
            queue.push([nx, ny]);
          }
        }
      }
    }
  }
  return cnt;
}
function bfsForDyschromatopsie() {
  const visited = Array.from(Array(n), () => Array(n).fill(0));

  const queue = [];
  queue.push([0, 0]);
  let cnt = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (!visited[i][j]) {
        visited[i][j] = 1;
        cnt++;
        queue.push([i, j]);
        while (queue.length !== 0) {
          const curArr = queue.shift();
          const curX = +curArr[0];
          const curY = +curArr[1];
          for (let dir = 0; dir < 4; dir++) {
            const nx = curX + dx[dir];
            const ny = curY + dy[dir];
            if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            if (visited[nx][ny] !== 0) continue;
            if (
              arr[nx][ny] !== arr[curX][curY] &&
              (arr[nx][ny] === "B" || arr[curX][curY] === "B")
            )
              continue;

            visited[nx][ny] = 1;
            queue.push([nx, ny]);
          }
        }
      }
    }
  }
  return cnt;
}
function solution(n, arr) {
  const originAreaCnt = bfs();
  const dyschromatopsieCnt = bfsForDyschromatopsie();
  console.log(originAreaCnt, dyschromatopsieCnt);
}
solution(n, arr);
