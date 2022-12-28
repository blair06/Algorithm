const user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"];
const banned_id = ["fr*d*", "*rodo", "******", "******"];

let numberOfCases = [];
const caseArr = [];
const visited = new Array(10).fill(0);

function removeDup(arr) {
  return [...new Set(arr.join("|").split("|"))].map((v) => v.split(","));
}

function checkCondition(banned_id, caseArr) {
  for (let i = 0; i < banned_id.length; i++) {
    if (banned_id[i].length === caseArr[i].length) {
      for (let j = 0; j < banned_id.length; j++) {
        if (banned_id[i][j] === "*" || banned_id[i][j] === caseArr[i][j]) {
          continue;
        }
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

function permutation(user_id, banned_id, cnt) {
  if (cnt === banned_id?.length) {
    if (checkCondition(banned_id, caseArr)) {
      numberOfCases.push([].concat(caseArr));
    }
    return;
  }
  for (let i = 0; i < user_id.length; i++) {
    if (visited[i] === 0) {
      visited[i] = 1;
      caseArr.push(user_id[i]);
      permutation(user_id, banned_id, cnt + 1);
      caseArr.pop();
      visited[i] = 0;
    }
  }
}
function solution(user_id, banned_id) {
  var answer = 1;

  permutation(user_id, banned_id, 0);
  numberOfCases = removeDup(numberOfCases.map((elem) => elem.sort()));

  return (answer = numberOfCases.length);
}

