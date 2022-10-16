var answer = 0;
function solution(cacheSize, cities) {
  const cache = new Array(cacheSize);

  if (cacheSize === 0) {
    return 5 * cities.length;
  }
  for (let city of cities) {
    city = city.toUpperCase();
    checkCache(cache, city);
  }
  return answer;
}
function checkCache(cache, city) {
  if (cache.includes(city)) {
    answer += 1;

    cache.splice(cache.indexOf(city), 1);
    cache.push(city);
  } else {
    answer += 5;
    cache.shift();
    cache.push(city);
  }
}
