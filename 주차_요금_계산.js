function calcFee(fees, parkingTime) {
  const [standardTime, standardFee, unitTime, unitFee] = fees;

  if (parkingTime <= standardTime) {
    return standardFee;
  }
  if (parkingTime > standardTime) {
    return (
      standardFee + Math.ceil((parkingTime - standardTime) / unitTime) * unitFee
    );
  }
}
function checkTime(inTime, outTime) {
  const [inHour, inMinute] = inTime.split(":").map((elem) => parseInt(elem));
  const [outHour, outMinute] = outTime.split(":").map((elem) => parseInt(elem));
  let totalMinute = 0;
  let flag = false;
  if (outMinute < inMinute) {
    totalMinute += 60 - inMinute + outMinute;
    flag = true;
  } else {
    totalMinute += outMinute - inMinute;
  }

  flag
    ? (totalMinute += (outHour - 1 - inHour) * 60)
    : (totalMinute += (outHour - inHour) * 60);

  return totalMinute;
}
function solution(fees, records) {
  let answer = [];
  const obj = {};
  const feeList = {};
  const finishTime = "23:59";
  for (let elem of records) {
    const elemArr = elem.split(" ");
    if (elemArr[2] === "IN") {
      obj[elemArr[1]] = elemArr[0];
      continue;
    }
    if (obj.hasOwnProperty(elemArr[1]) && elemArr[2] === "OUT") {
      const parkingTime = checkTime(obj[elemArr[1]], elemArr[0]);
      if (feeList.hasOwnProperty(parseInt(elemArr[1]))) {
        feeList[parseInt(elemArr[1])] =
          feeList[parseInt(elemArr[1])] + parkingTime;
      } else {
        feeList[parseInt(elemArr[1])] = parkingTime;
      }
      delete obj[elemArr[1]];
    }
  }

  for (let key in obj) {
    const value = obj[key];
    const parkingTime = checkTime(value, finishTime);
    if (feeList.hasOwnProperty(parseInt(key))) {
      feeList[parseInt(key)] = feeList[parseInt(key)] + parkingTime;
    } else {
      feeList[parseInt(key)] = parkingTime;
    }
  }
  Object.fromEntries(
    Object.entries(feeList).sort(([a], [b]) => (a < b ? -1 : 1))
  );
  for (let key in feeList) {
    const value = feeList[key];
    answer.push(calcFee(fees, value));
  }

  return answer;
}
