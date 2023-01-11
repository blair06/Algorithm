function solution(cap, n, deliveries, pickups) {
  var answer = 0;
  let remainCap = cap;
  let d_Idx = -1;
  let p_idx = -1;
  let start = n;
  for (let i = n - 1; i >= 0; i--) {
    if (pickups[i] !== 0) {
      p_idx = i;
      break;
    }
  }
  for (let i = n - 1; i >= 0; i--) {
    if (deliveries[i] !== 0) {
      d_Idx = i;
      break;
    }
  }
  while (true) {
    start = d_Idx > p_idx ? d_Idx + 1 : p_idx + 1;
    remainCap = cap;

    for (let i = d_Idx; i >= 0; i--) {
      if (i !== 0 && deliveries[i] === 0) {
        continue;
      }
      if (remainCap === deliveries[i]) {
        deliveries[i] = 0;
        remainCap = 0;
        if (i === 0 && deliveries[i] === 0) {
          d_Idx = -1;
          break;
        }
        continue;
      }
      if (remainCap > deliveries[i]) {
        remainCap -= deliveries[i];
        deliveries[i] = 0;
        if (i === 0 && deliveries[i] === 0) {
          d_Idx = -1;
          break;
        }
        continue;
      }
      if (remainCap < deliveries[i]) {
        deliveries[i] -= remainCap;
        d_Idx = i;
        break;
      }
    }
    remainCap = cap;

    for (let i = p_idx; i >= 0; i--) {

      if (i !== 0 && pickups[i] === 0) {
        continue;
      }
      if (remainCap > pickups[i]) {
        remainCap -= pickups[i];

        pickups[i] = 0;
        if (i === 0 && pickups[i] === 0) {
          p_idx = -1;
          break;
        }
        continue;
      }
      if (remainCap === pickups[i]) {
        remainCap = 0;
        pickups[i] = 0;
        if (i === 0 && pickups[i] === 0) {
          p_idx = -1;
          break;
        }
        continue;
      }

      if (remainCap < pickups[i]) {
        pickups[i] -= remainCap;
        p_idx = i;
        break;
      }
    }
    answer += start * 2;

    if (d_Idx === -1 && p_idx === -1) break;
  }
  return answer;
}
