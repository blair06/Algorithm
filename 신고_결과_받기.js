function solution(id_list, report, k) {
  var answer = [];
  const reportList = {};
  const obj = {};
  for (let elem of report) {
    const elemArr = elem.split(" ");
    if (obj.hasOwnProperty(elemArr[1])) {
      if (!obj[elemArr[1]]["reporters"]?.includes(elemArr[0])) {
        obj[elemArr[1]]["cnt"] = obj[elemArr[1]]["cnt"] + 1;
        obj[elemArr[1]]["reporters"] = obj[elemArr[1]]["reporters"].concat(
          elemArr[0]
        );
      }
    } else {
      obj[elemArr[1]] = {
        cnt: 1,
        reporters: [elemArr[0]],
      };
    }
  }
  for (let key in obj) {
    const value = obj[key];
    if (value["cnt"] >= k) {
      for (let elem of value["reporters"]) {
        reportList[elem] =
          reportList[elem] === undefined ? 1 : reportList[elem] + 1;
      }
    }
  }
   for (let key of id_list) {
    if (reportList.hasOwnProperty(key)) {
      answer.push(reportList[key]);
    } else {
      answer.push(0);
    }
  }
  return answer;
}
