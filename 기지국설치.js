function solution(n, stations, w) {
  let answer = 0;

  stations.sort((a, b) => {
    return a - b;
  });
  let left = 1;
  let idx = 0;
  while (1) {
    let temp = stations[idx] - w - left;
    answer += Math.ceil(temp / (2 * w + 1));
    left = stations[idx] + w + 1;
    idx++;
     
    if (idx >= stations.length) {
         if(n - left === 0) {
        answer+= 1;
        break;
      }
      answer += Math.ceil((n - left) / (2 * w + 1));
      break;
    }
  }
  return answer;
}
