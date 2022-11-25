//const ids = [1, 2, 1, 3, 1, 2, 1, 2];
//const days = ["월", "목", "월", "수", "일", "화", "금", "수"];
function solution(ids, days) {
  const user = {};

  let test = ids.map((item, idx) => {
    return item + days[idx];
  });

  test = new Set(test);

  for (let elem of test.values()) {
    const tempArr = elem.split("");
    user[tempArr[0]] = user[tempArr[0]] ? user[tempArr[0]] + 1 : 1;
  }
  const answer = Object.entries(user)
    .filter((elem) => {
      return elem[1] >= 3;
    })
    .map((item) => {
      return parseInt(item[0]);
    });

  return answer;
}

console.log(solution(ids, days));
