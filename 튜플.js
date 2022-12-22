function solution(s) {
  var answer = [];
  s = s
    .slice(1, s.length - 1)
    .split("},{")
    .map((elem, index) => {
      elem = elem.replace(/[\{\}]/g, "");
      return elem.split(",");
    })
    .sort((a, b) => {
      if (a.length > b.length) return 1;
      if (a.length < b.length) return -1;
    });

  for (let arr of s) {
    for (let elem of arr) {
        const tempElem = parseInt(elem);
      if (!answer.includes(tempElem)) {
        answer.push(tempElem);
      }
    }
  }


  return answer;
}
