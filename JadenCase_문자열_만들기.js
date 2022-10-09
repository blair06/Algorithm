function solution(s) {
  var answer = "";
  const arr = s.split(" ");

  for (let index in arr) {
    if (arr[index] === "") {
      arr[index - 1] += "";
      continue;
    }
    if (arr[index][0] === arr[index][0].toLowerCase()) {
      arr[index] =
        arr[index].charAt(0).toUpperCase() +
        arr[index].substring(1).toLowerCase();
    } else {
      arr[index] = arr[index].charAt(0) + arr[index].substring(1).toLowerCase();
    }
  }
  answer = arr.join(" ");
  return answer;
}
