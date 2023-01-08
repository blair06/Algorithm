const numbers = "143";
const arr = [];
const visited = new Array(10).fill(0);
const duplicateArr = new Array(999).fill(1);
function checkDecimal(num) {
  let pl = true;
  if (num === 1 || num === 0) return false;
  for (let i = 2; i <= Math.sqrt(num); i++) {
    if (num % i === 0) {
      pl = false;
      break;
    }
  }
  return pl;
}
function dfs(numberArr, cnt, str) {
  if (str.length === cnt) {
    const num = parseInt(str.join(""));
    if (checkDecimal(num) && duplicateArr[num]) {
      arr.push(num);
      duplicateArr[num] = 0;
    }
    return;
  }
  for (let i = 0; i < numberArr.length; i++) {
    if (visited[i]) continue;
    str.push(numberArr[i]);
    visited[i] = 1;
    dfs(numberArr, cnt, str);
    str.pop();
    visited[i] = 0;
  }
}
function solution(numbers) {
  var answer = 0;
  const numberArr = numbers.split("");
  for (let i = 1; i <= numberArr.length; i++) {
    const temp = [];
    dfs(numberArr, i, temp);
  }
  answer = arr.length;
  return answer;
}
console.log(solution(numbers));
