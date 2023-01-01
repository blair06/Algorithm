let [i1, i2] = [0, 0];
function solution(queue1, queue2) {
  var answer = 0;
  let queue1SumResult = queue1.reduce(function add(sum, currValue) {
    return sum + currValue;
  }, 0);
  let queue2SumResult = queue2.reduce(function add(sum, currValue) {
    return sum + currValue;
  }, queue1SumResult);
  const targetNum = queue2SumResult / 2;
  const copyQ1 = new Array(queue1.length);
  const copyQ2 = new Array(queue2.length);

  for (let i = 0; i < copyQ1.length; i++) {
    copyQ1[i] = queue1[i];
    copyQ2[i] = queue2[i];
  }

  while (queue1SumResult !== targetNum) {
    if (queue1SumResult < targetNum) {
      const temp = copyQ2[i2];
      i2++;
      copyQ1.push(temp);
      queue1SumResult += temp;
      answer += 1;
    } else if (queue1SumResult > targetNum) {
      const temp = copyQ1[i1];
      i1++;
      copyQ2.push(temp);
      queue1SumResult -= temp;

      answer += 1;
    }
    if (
        queue1.length * 2 === copyQ1.length ||(
      queue1.length === copyQ1.length &&
      queue1.every((value, idx) => value === copyQ1[idx]) &&
      queue2.length === copyQ2.length &&
      queue2.every((value, idx) => value === copyQ2[idx])
    ) ){
      answer = -1;
      break;
    }
  }
  // console.log(temp1);

  return answer;
}
