const { execSync } = require('child_process');
const path = require('path');

const solutionPath = path.join(__dirname, 'beakjoon_3272.js');

function run(input) {
  const result = execSync(`echo "${input}" | node ${solutionPath}`, {
    encoding: 'utf8',
  });
  return result.trim();
}

const tests = [
  {
    name: '예제1: [1,2,3,4,5], x=6 → 2쌍',
    input: `5\n1 2 3 4 5\n6`,
    expected: '2',
  },
  {
    name: '예제2: [1,2,3,4], x=10 → 0쌍',
    input: `4\n1 2 3 4\n10`,
    expected: '0',
  },
  {
    name: '예제3: [1,3,5,7,9,11,13], x=14 → 3쌍',
    input: `7\n1 3 5 7 9 11 13\n14`,
    expected: '3',
  },
  {
    name: '원소 2개, 합이 일치',
    input: `2\n1 9\n10`,
    expected: '1',
  },
  {
    name: '원소 2개, 합이 불일치',
    input: `2\n1 2\n10`,
    expected: '0',
  },
  {
    name: '비정렬 입력: [5,12,7,10,9,1,2,3,11], x=13',
    input: `9\n5 12 7 10 9 1 2 3 11\n13`,
    expected: '3',
  },
  {
    name: '역순 입력: [5,4,3,2,1], x=6',
    input: `5\n5 4 3 2 1\n6`,
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
