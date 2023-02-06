function solution(A, B) {
  var answer = 0;
  A.sort((a, b) => {
    return b - a;
  });
  B.sort((a, b) => {
    return b - a;
  });
  let idx = 0;
  for (let i = 0; i < A.length; i++) {
    if (A[i] >= B[idx]) {
      continue;
    }
    if (A[i] < B[idx]) {
      answer += 1;
      idx++;
      continue;
    }
  }

  return answer;
}
