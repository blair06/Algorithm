const record = [
  "Enter uid1234 Muzi",
  "Enter uid4567 Prodo",
  "Leave uid1234",
  "Enter uid1234 Prodo",
  "Change uid4567 Ryan",
];
function solution(record) {
  var answer = [];
  const userList = {};
  for (let elem of record) {
    const elemArray = elem.split(" ");
    let dialog = "";
    if (elemArray[0] === "Enter" && elemArray[1] !== undefined) {
      addUser(userList, elemArray);
    }
    if (elemArray[0] === "Change") {
      addUser(userList, elemArray);
    }
  }
  for (let elem of record) {
    const elemArray = elem.split(" ");
    if (elemArray[0] === "Enter") {
      answer.push(`${userList[elemArray[1]]}님이 들어왔습니다.`);
    }
    if (elemArray[0] === "Leave") {
      answer.push(`${userList[elemArray[1]]}님이 나갔습니다.`);
    }
  }

  return answer;
}

function addUser(userList, elemArray) {
  userList[elemArray[1]] = elemArray[2];
}

console.log(solution(record));
