const { execSync } = require('child_process');
const path = require('path');

const solutionPath = path.join(__dirname, 'beakjoon_1700.js');

function run(input) {
  const result = execSync(`echo "${input}" | node ${solutionPath}`, {
    encoding: 'utf8',
  });
  return result.trim();
}

const tests = [
  {
    name: '예제1: 3구, [1,2,3,4,1,2] → 1번 뺌',
    input: `3 6\n1 2 3 4 1 2`,
    expected: '1',
  },
  {
    name: '예제2: 2구, [1,2,3,1,2] → 2번 뺌',
    input: `2 5\n1 2 3 1 2`,
    expected: '2',
  },
  {
    name: '예제3: 3구, [1,2,3,1,2,3,1] → 0번 뺌',
    input: `3 7\n1 2 3 1 2 3 1`,
    expected: '0',
  },
  {
    name: '1구, 같은 용품 반복 → 0번 뺌',
    input: `1 4\n1 1 1 1`,
    expected: '0',
  },
  {
    name: '1구, 매번 다른 용품 → 2번 뺌',
    input: `1 3\n1 2 3`,
    expected: '2',
  },
  {
    name: '이미 꽂혀있는 용품 사용 → 뺄 필요 없음',
    input: `2 4\n1 2 1 2`,
    expected: '0',
  },
  {
    name: '가장 나중에 쓰이는 것을 빼야 최적',
    input: `2 7\n1 2 3 2 1 3 1`,
    expected: '2',
  },
];

let passed = 0;
let failed = 0;

tests.forEach(({ name, input, expected }) => {
  const result = run(input);
  if (result === expected) {
    console.log(`✅ PASS: ${name}`);
    passed++;
  } else {
    console.log(`❌ FAIL: ${name} — expected ${expected}, got ${result}`);
    failed++;
  }
});

console.log(`\n결과: ${passed}/${tests.length} passed, ${failed} failed`);
if (failed > 0) process.exit(1);
