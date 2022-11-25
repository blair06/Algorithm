// const pin = "0000";
const pin = "9876";
function solution(pin) {
  let answer = true;
  const removeDuplicate = new Set(pin);
  if (removeDuplicate.size === 1) return false;

  let cnt = 0;
  let preNum = -1;
  for (let i = 0; i < pin.length; i++) {
    if (Math.abs(pin[i].charCodeAt() - preNum) === 1) {
      cnt++;
    }
    preNum = pin[i].charCodeAt();

    if (cnt === 3) return false;
  }
  return answer;
}

console.log(solution(pin));
