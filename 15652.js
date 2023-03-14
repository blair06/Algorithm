const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();

input = input.trim().split(" ");
const n = +input[0];
const m = +input[1];
let answer = "";
const temp = [];
function dfs(idx) {
  if (temp.length === m) {
    answer += `${temp.join(" ")}\n`;
    return;
  }
  for (let i = idx; i <= n; i++) {
    temp.push(i);
    dfs(i);
    temp.pop();
  }
}
dfs(1);
console.log(answer);
