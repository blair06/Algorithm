const genres = ["classic", "pop", "classic", "classic", "pop"];
const plays = [500, 600, 150, 800, 2500];

function solution(genres, plays) {
  var answer = [];
  const album = [];

  for (let i in genres) {
    let currentIndex = -1;
    if (
      album.some((elem, index) => {
        if (elem.genre === genres[i]) {
          currentIndex = index;
        }
        return elem.genre === genres[i];
      })
    ) {
      album[currentIndex].total += plays[i];
      album[currentIndex].plays?.push({
        index: parseInt(i),
        playCnt: plays[i],
      });
    } else {
      album.push({
        genre: genres[i],
        total: plays[i],
        plays: [{ index: parseInt(i), playCnt: plays[i] }],
      });
    }
  }
  album.sort((a, b) => {
    return b.total - a.total;
  });

  for (let i of album) {
    if (i.plays.length === 1) {
      answer.push(i.plays[0].index);
    } else {
      i.plays.sort((a, b) => {
        return b.playCnt - a.playCnt;
      });
      answer.push(i.plays[0].index);
      answer.push(i.plays[1].index);
    }
  }
  return answer;
}
console.log(solution(genres, plays));
