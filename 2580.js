const fs = require("fs");
// let input = fs.readFileSync("/dev/stdin").toString();
let input = fs.readFileSync("./input.txt").toString();

input = input.trim().split("\n");
const n = parseInt(input.length);
const board = Array.from(Array(9), () => Array(9).fill(0));
const arr = [];

for (let i = 0; i < input.length; i++) {
  const temp = input[i].split(" ");
  for (let j = 0; j < temp.length; j++) {
    board[i][j] = parseInt(temp[j]);
    if (temp[j] === "0") arr.push([i, j]);
  }
}
if (arr.length !== 0) dfs(0);

let answer = "";
for (let i = 0; i < board.length; i++) {
  for (let j = 0; j < board[i].length; j++) {
    answer += `${board[i][j]} `;
  }
  answer.trim();
  answer += `\n`;
}
console.log(answer.trim());

function dfs(idx) {
  const [x, y] = arr[idx];
  const numbackup = checkNum(x, y);

  for (let i = 0; i < numbackup.length; i++) {
    board[x][y] = numbackup[i];
    if (idx + 1 === arr.length) return;
    let nextIdx = idx + 1;
    dfs(nextIdx);
    const [nx, ny] = arr[nextIdx];
    if (board[nx][ny] !== 0) return;
    board[x][y] = 0;
  }
}
function checkNum(x, y) {
  const candidtateArr = [];
  const num = new Array(10).fill(0);
  for (let i = 0; i < 9; i++) {
    if (board[x][i] !== 0) {
      num[board[x][i]] = 1;
    }
    if (board[i][y] !== 0) {
      num[board[i][y]] = 1;
    }
  }
  let tempx = parseInt(x / 3) * 3;
  let tempy = parseInt(y / 3) * 3;
  for (let i = tempx; i < tempx + 3; i++) {
    for (let j = tempy; j < tempy + 3; j++) {
      if (board[i][j] !== 0) {
        num[board[i][j]] = 1;
      }
    }
  }

  for (let i = 1; i < 10; i++) {
    if (num[i] === 0) candidtateArr.push(i);
  }
  return candidtateArr;
}
