const fs = require("fs");
// let input = fs.readFileSync("/dev/stdin").toString();
let input = fs.readFileSync("./input.txt").toString();

input = input.trim().split("\n");
const n = parseInt(input[0]);

const arr = Array(n + 1).fill(0);
for (let i = 1; i <= n; i++) {
  arr[i] = +input[i];
}
const cycleList = Array(n + 1).fill(false);
const answer = [];
function dfs(visited, target, idx) {
  if (cycleList[idx]) return false;

  if (!visited[idx]) {
    visited[idx] = true;
    return dfs(visited, target, arr[idx]);
  }
  if (idx === target) {
    return true;
  }
}
function solution(n) {
  for (let i = 1; i <= n; i++) {
    const visited = Array(n + 1).fill(false);

    if (dfs(visited, i, i)) {
      for (let j = 1; j <= n; j++) {
        if (visited[j]) {
          cycleList[j] = true;
        }
      }
    }
  }
  for (let i = 1; i < cycleList.length; i++) {
    if (cycleList[i]) answer.push(i);
  }
  answer.unshift(answer.length);
  console.log(answer.join("\n"));
}
solution(n, arr);
