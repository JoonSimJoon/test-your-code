import { findCounterExample } from "./core/counterExample";

const testDir = "test_code";

const result = findCounterExample(testDir);
if (result) {
    console.log("\n❗ 반례 발견:");
    console.log(result);
} else {
    console.log("\n✅ 반례 없음");
}