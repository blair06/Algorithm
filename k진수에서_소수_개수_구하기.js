const n = 110011;
const k = 10;
function checkPrime(str) {
  const target = parseInt(str);
  if (target === 1) return false;
  for (let i = 2; i <= Math.sqrt(target); i++) {
    if (target % i === 0) return false;
  }
  return true;
}
function solution(n, k) {
  var answer = 0;
  const number = n.toString(k).split("0");

  for (let i = 0; i < number.length; i++) {
    if (number[i] !== "" && checkPrime(number[i])) {
      answer++;
    }
  }
  return answer;
}

console.log(solution(n, k));
