const stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1];
const k = 3;
function solution(stones, k) {
  let answer = 0;
  let left = 1;
  let right = 200000000;

  while (right >= left) {
    let stepCheck = 0;
    const mid = ((right + left) / 2) >> 0;
    const steppedStones = new Array(stones.length);
    for (let i = 0; i < stones.length; i++) {
      steppedStones[i] = stones[i];
    }
    for (let i = 0; i < steppedStones.length; i++) {
      steppedStones[i] -= mid;
      if (steppedStones[i] <= 0) {
        stepCheck += 1;
      } else {
        stepCheck = 0;
      }
      if (stepCheck === k) {
        break;
      }
    }

    if (stepCheck === k) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return (answer = left);
}
console.log(solution(stones, k));
