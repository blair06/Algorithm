function solution(s) {
  var answer = "";
  const arr = s.split(" ").sort(function (a, b) {
    return a - b;
  });
  answer = arr[0] + " " + arr[arr.length - 1];
  return answer;
}
