//programmers 위장
function solution(clothes) {
  var answer = 1;
  let clothesMap = new Map();
  for (let i of clothes) {
    clothesMap.set(i[1], clothesMap.get(i[1]) ? clothesMap.get(i[1]) + 1 : 1);
  }
  clothesMap.forEach((elem) => {
    answer *= elem + 1;
  });

  return answer - 1;
}
