let maxDiff = -1;
let answer = [];

function checkScore(lionArr, peachArr) {
  let lionTotal = 0;
  let peachTotal = 0;

  for (let i = 0; i < lionArr.length; i++) {
    if (lionArr[i] === 0 && peachArr[i] === 0) continue;
    lionArr[i] > peachArr[i] ? (lionTotal += 10 - i) : (peachTotal += 10 - i);
  }
  if (lionTotal > peachTotal && maxDiff < lionTotal - peachTotal) {
    maxDiff = lionTotal - peachTotal;
    answer = [].concat(lionArr);

    return;
  }
  if (lionTotal > peachTotal && maxDiff === lionTotal - peachTotal) {
    for (let i = 10; i >= 0; i--) {
      if (lionArr[i] > answer[i]) {
      answer = [].concat(lionArr);

      break;
    } else if(answer[i] > lionArr[i]){
      break;
    }
    }
    return;
  }
}
function dfs(n, index, info, lionArr = new Array(11).fill(0)) {
  if (n === 0) {
    checkScore(lionArr, info);
    return;
  }
  if (n > 0) {
    for (let idx = index; idx < info.length; idx++) {
      const state = n - (info[idx] + 1) >= 0 ? info[idx] + 1 : n;

      lionArr[idx] = state;
      dfs(n - state, idx + 1, info, lionArr);
      lionArr[idx] = 0;
    }
  }
}
function solution(n, info) {
  dfs(n, 0, info);
  return  maxDiff === -1 ? [-1] : answer;
}
