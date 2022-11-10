function solution(people, limit) {
  let answer = 0;
  const boat = [];
  const peoples = [];
  people.sort(function (a, b) {
    if (a < b) return 1;
    if (a === b) return 0;
    if (a > b) return -1;
  });

  for (let i in people) {
    if (people[i] > limit / 2) {
      boat.push(people[i]);
    } else {
      peoples.push(people[i]);
    }
  }

  for (let p of peoples) {
    if (boat[boat.length - 1] + p > limit || boat.length === 0) {
      boat.push(p);
    } else {
      boat.pop();
      answer++;
    }
  }

  answer += boat.length;
  return answer;
}
