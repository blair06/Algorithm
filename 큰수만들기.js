function solution(number, k) {
  let answer = "";
  let idx = 0;
  let st = [];

  for (let num of number) {
    if (k > 0) {
      for (let i = st.length - 1; i >= 0; i--) {
        if (k === 0) break;
        if (st[i] < num) {
          st.pop();
          k--;
        } else {
          break;
        }
      }
      st.push(num);
    } else {
      st.push(num);
    }
  }
  if (k > 0) {
    st = st.slice(0, st.length - k);
  }
  answer = st.join("");
  return answer;
}
