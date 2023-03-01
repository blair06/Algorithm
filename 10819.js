const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
// let input = fs.readFileSync("./input.txt").toString();

input = input.trim().split("\n");
const n = parseInt(input[0]);
const arr = [];
const temp = input[1].split(" ");
for (let i = 0; i < temp.length; i++) {
  arr[i] = parseInt(temp[i]);
}
const visited = Array(n).fill(false);
let MaxNum = 0;

dfs([]);
console.log(MaxNum);

function dfs(result) {
  if (result.length === arr.length) {
    const tempMaxNum = calcMaxNum(result);
    if (MaxNum < tempMaxNum) {
      MaxNum = tempMaxNum;
    }
    return;
  }
  for (let i = 0; i < arr.length; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    result.push(arr[i]);
    dfs(result);
    visited[i] = false;
    result.pop();
  }
}
function calcMaxNum(result) {
  let tempNum = 0;
  for (let i = 0; i < result.length - 1; i++) {
    tempNum += Math.abs(result[i] - result[i + 1]);
  }
  return tempNum;
}
