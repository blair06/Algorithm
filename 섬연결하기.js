function solution(n, costs) {
  var answer = 0;
  const parents = new Array(n + 2).fill(Infinity);
  for (let i = 0; i < parents.length; i++) {
    parents[i] = i;
  }

  costs.sort((a, b) => a[2] - b[2]);
  costs.map((elem) => {
    const num1Parent = findParents(parents, elem[0]);
    const num2Parent = findParents(parents, elem[1]);

    if (num1Parent !== num2Parent) {
      unionParent(parents, elem[0], elem[1]);
      answer += elem[2];
    }
  });

  return answer;
}
function findParents(parents, num) {
  if (num === parents[num]) return num;
  return (parents[num] = findParents(parents, parents[num]));
}
function unionParent(parents, num1, num2) {
  num1 = findParents(parents, num1);
  num2 = findParents(parents, num2);

  num1 > num2 ? (parents[num1] = num2) : (parents[num2] = num1);
}
