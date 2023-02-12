
function solution(gems) {
  var answer = [1, gems.length];
  const gemCategory = new Set(gems);
  let windowSize = gemCategory.size;
  let left = 0;
  let right = 0;

  const shoppingList = new Map();
  shoppingList.set(gems[0], 1);

  while (right < gems.length) {
    if (shoppingList.size === windowSize) {
      if (right - left < answer[1] - answer[0]) {
        answer = [left + 1, right + 1];
      }
      shoppingList.set(gems[left], shoppingList.get(gems[left]) - 1);
      if (shoppingList.get(gems[left]) === 0) {
        shoppingList.delete(gems[left]);
      }
      left += 1;
    } else {
      right += 1;
      const r = shoppingList.get(gems[right]);
      shoppingList.set(gems[right], r ? r + 1 : 1);
    }
  }
  return answer;
}
