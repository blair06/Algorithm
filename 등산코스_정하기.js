class Heap {
  constructor() {
    this.items = [];
  }

  swap(idx1, idx2) {
    [this.items[idx1], this.items[idx2]] = [this.items[idx2], this.items[idx1]];
  }

  findParentIdx(idx) {
    return Math.floor((idx - 1) / 2);
  }

  findLeftChildIdx(idx) {
    return idx * 2 + 1;
  }

  findRightChildIdx(idx) {
    return idx * 2 + 2;
  }

  findParent(idx) {
    return this.items[this.findParentIdx(idx)];
  }

  findLeftChild(idx) {
    return this.items[this.findLeftChildIdx(idx)];
  }

  findRightChild(idx) {
    return this.items[this.findRightChildIdx(idx)];
  }

  size() {
    return this.items.length;
  }
}

class MinHeap extends Heap {
  bubbleUp() {
    let index = this.items.length - 1;

    while (
      this.findParent(index) &&
      this.findParent(index)[1] > this.items[index][1]
    ) {
      this.swap(index, this.findParentIdx(index));
      index = this.findParentIdx(index);
    }
  }

  bubbleDown() {
    let index = 0;

    while (
      (this.findLeftChild(index) &&
        this.findLeftChild(index)[1] < this.items[index][1]) ||
      (this.findRightChild(index) &&
        this.findRightChild(index)[1] < this.items[index][1])
    ) {
      let smallerIndex = this.findLeftChildIdx(index);

      if (
        this.findRightChild(index) &&
        this.findRightChild(index)[1] < this.items[smallerIndex][1]
      ) {
        smallerIndex = this.findRightChildIdx(index);
      }

      this.swap(index, smallerIndex);
      index = smallerIndex;
    }
  }

  add(value) {
    this.items.push(value);
    this.bubbleUp();
  }

  poll() {
    if (this.size() === 1) {
      return this.items.pop();
    }

    const value = this.items[0];
    this.items[0] = this.items.pop();
    this.bubbleDown();

    return value;
  }
}
const paths = [
  [1, 2, 5],
  [1, 4, 1],
  [2, 3, 1],
  [2, 6, 7],
  [4, 5, 1],
  [5, 6, 1],
  [6, 7, 1],
];
const gates = [3, 7];
const summits = [1, 5];
const n = 7;
function solution(n, paths, gates, summits) {
  const hikingTrail = Array.from({ length: n + 1 }, () => []);
  const MAX = 10000001;
  const answer = [n, MAX];

  summits.sort((a, b) => a - b);
  paths.forEach((path) => {
    const [i, j, w] = path;

    hikingTrail[i].push([j, w]);
    hikingTrail[j].push([i, w]);
  });

  const isSummits = Array.from({ length: n + 1 }, () => false);

  summits.forEach((summit) => {
    isSummits[summit] = true;
  });
  const minHeap = new MinHeap();
  const intensity = Array(n + 1).fill(MAX);
  gates.forEach((gate) => {
    minHeap.add([gate, 0]);
    intensity[gate] = 0;
  });

  while (minHeap.size()) {
    //3,0
    const [vertex, cost] = minHeap.poll();
    if (isSummits[vertex] || intensity[vertex] < cost) {
      continue;
    }

    for (let i = 0; i < hikingTrail[vertex].length; i++) {
      //2,1
      const [nextVertex, nextCost] = hikingTrail[vertex][i];
      //Max 0, 1
      if (intensity[nextVertex] > Math.max(intensity[vertex], nextCost)) {
        intensity[nextVertex] = Math.max(intensity[vertex], nextCost);
        minHeap.add([nextVertex, intensity[nextVertex]]);
      }
    }
  }
  summits.forEach((summit) => {
    if (intensity[summit] < answer[1]) {
      answer[0] = summit;
      answer[1] = intensity[summit];
    }
  });

  return answer;
}

console.log(solution(n, paths, gates, summits));
