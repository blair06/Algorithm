function solution(s) {
  let answer = 0;

  if (s.length % 2 === 1) {
    answer = 0;
    return 0;
  }
  const st = [];

  for (let str of s) {
    if (st[st.length - 1] === str) {
      st.pop();
      continue;
    }
    st.push(str);
  }
  answer = st.length ? 0 : 1;
  return answer;
}
