const discountedRate = [10, 20, 30, 40];
const discountedRateSet = [];
function dfs(tempArr, cnt, emoticons) {
  if (tempArr.length === emoticons.length) {
    discountedRateSet.push([].concat(tempArr));
    return;
  }

  for (let i = 0; i < discountedRate.length; i++) {
    tempArr.push(discountedRate[i]);
    dfs(tempArr, cnt + 1, emoticons);
    tempArr.pop();
  }
}

function solution(users, emoticons) {
  var answer = [];

  dfs([], 0, emoticons);

  //할인율 [10,10]
  let totalPrice = 0;
  let member = 0;
  for (let i = 0; i < discountedRateSet.length; i++) {
    let tempMember = 0;
    let tempTotalPrice = 0;
    //user1부터 마지막까지
    for (let j = 0; j < users.length; j++) {
      const minRate = users[j][0];
      const criteria = users[j][1];
      let isJoin = false;
      let individualTotalPrice = 0;
      for (let k = 0; k < discountedRateSet[i].length; k++) {
        const test = discountedRateSet[i];
        const test2 = discountedRateSet[i][k];
        if (discountedRateSet[i][k] < minRate) continue;
        individualTotalPrice +=
          emoticons[k] - emoticons[k] * (discountedRateSet[i][k] * 0.01);
        if (individualTotalPrice >= criteria) {
          tempMember += 1;
          isJoin = true;
          break;
        }
      }
      if (isJoin) continue;
      tempTotalPrice += individualTotalPrice;
    }
    if (
      tempMember > member ||
      (tempMember === member && tempTotalPrice > totalPrice)
    ) {
      member = tempMember;
      totalPrice = tempTotalPrice;
    }
  }
  return [member, totalPrice];
}
