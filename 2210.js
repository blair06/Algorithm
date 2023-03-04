const fs = require("fs");
// let input = fs.readFileSync("/dev/stdin").toString();
let input = fs.readFileSync("./input.txt").toString();

input = input.trim().split("\n");
for (let i = 0; i < input.length; i++) {
  input[i] = input[i].split(" ").map((e) => +e);
}
const dx = [-1, 1, 0, 0];
const dy = [0, 0, 1, -1];
const answerList = [];
for (let i = 0; i < 5; i++) {
  for (let j = 0; j < 5; j++) {
    dfs(i, j, []);
  }
}

function dfs(x, y, arr) {
  if (arr.length === 6) {
    const arrToStr = arr.join("");
    if (!answerList.includes(arrToStr)) {
      answerList.push(arrToStr);
    }
    return;
  }

  for (let i = 0; i < 4; i++) {
    const nx = dx[i] + x;
    const ny = dy[i] + y;

    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
    arr.push(input[nx][ny]);

    dfs(nx, ny, arr);
    arr.pop(input[nx][ny]);
  }
}

console.log(answerList.length);
