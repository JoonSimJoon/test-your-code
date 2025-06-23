import { findCounterExample } from "./core/counterExample";

async function main() {
    const testDir = "test_code";
    const result = await findCounterExample(testDir);
    if (result) {
        console.log("❗ 반례 발견:\n" + result);
    } else {
        console.log("✅ 반례 없음");
    }
}

main();