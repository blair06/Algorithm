const maps = [
  [1, 0, 1, 1, 1],
  [1, 0, 1, 0, 1],
  [1, 0, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [0, 0, 0, 0, 1],
];
let dx = [-1, 0, 1, 0],
  dy = [0, 1, 0, -1];
const q = [];
const visited = Array.from(Array(101), () => Array(101).fill(0));

function solution(maps) {
  var answer = -1;
  let m = maps[0].length - 1;
  let n = maps.length - 1;

  let curx, cury;
  q.push({ x: 0, y: 0, depth: 1 });
  visited[0][0] = 1;
  while (q.length) {
    let currentInfo = q.shift();
    let x = currentInfo.x;
    let y = currentInfo.y;
    let depth = currentInfo.depth;
    if (x === m && y === n) {
      answer = depth;
      break
    }
    for (let i = 0; i < dx.length; i++) {
      curx = dx[i] + x;
      cury = dy[i] + y;

      if (
        curx < 0 ||
        curx >= maps[0].length ||
        cury < 0 ||
        cury >= maps.length
      ) {
        continue;
      }
      if (visited[cury][curx] === 0 && maps[cury][curx] !== 0) {
        visited[cury][curx] = 1;
        q.push({ x: curx, y: cury, depth: depth + 1 });
      }
    }
  }

  return answer;
}

console.log(solution(maps));
