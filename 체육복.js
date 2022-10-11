function solution(n, lost, reserve) {
  const students = new Array(n + 2).fill(1);
  let answer = n - lost.length;
  for (let item of lost) {
    const isInclude = reserve.indexOf(item);
    if (isInclude !== -1) {
      reserve.splice(isInclude, 1);
      students[lost[isInclude]] = 1;
      answer += 1;
      continue;
    }
    students[item] = 0;
  }
  reserve.sort();

  for (let item of reserve) {
    if (students[item - 1] === 0) {
      students[item - 1] = 1;
      answer += 1;
    } else if (students[item + 1] === 0) {
      students[item + 1] = 1;
      answer += 1;
    }
  }

  return answer;
}
